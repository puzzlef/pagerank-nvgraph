#pragma once
#include <vector>
#include <type_traits>
#include "_main.hxx"
#include "vertices.hxx"
#include "edges.hxx"
#include "pagerank.hxx"

using std::vector;
using std::is_same;




template <class G, class T=float>
PagerankResult<T> pagerankOmp(const G& xt, const vector<T> *q=nullptr, PagerankOptions<T> o={}) {
  T    p = o.damping;
  T    E = o.tolerance;
  int  L = o.maxIterations, l;
  auto vfrom = sourceOffsets(xt);
  auto efrom = destinationIndices(xt);
  auto vdata = vertexData(xt);
  int  N     = xt.order();
  vector<T> a(N), r(N), f(N), c(N);
  float t = measureDuration([&]() { l = pagerankOmpCore(a, r, f, c, vfrom, efrom, vdata, N, q, p, E, L); }, o.repeat);
  return {vertexContainer(xt, a), l, t};
}


// @param xt transpose graph, with vertex-data=1 for dead-ends & edge-data=1/out-degree

// Find pagerank accelerated using nvGraph.
// @param xt transpose graph, with vertex-data=out-degree
// @param q initial ranks (optional)
// @param o options {damping=0.85, tolerance=1e-6, maxIterations=500}
// @returns {ranks, iterations, time}
template <class G, class T=float>
PagerankResult<T> pagerank(const G& x, const vector<T> *q=nullptr, PagerankOptions<T> o={}) {
  T   p = o.damping;
  T   E = o.tolerance;
  int L = o.maxIterations;
  nvgraphHandle_t     h;
  nvgraphGraphDescr_t g;
  struct nvgraphCSCTopology32I_st csc;
  cudaDataType_t type = is_same<T, float>::value? CUDA_R_32F : CUDA_R_64F;
  vector<cudaDataType_t> vtype {type, type};
  vector<cudaDataType_t> etype {type};
  vector<float> ranks(x.order());
  auto ks    = vertices(x);
  auto vfrom = sourceOffsets(x);
  auto efrom = destinationIndices(x);
  auto vdata = vertexData(x);
  auto edata = edgeData(x);

  TRY( nvgraphCreate(&h) );
  TRY( nvgraphCreateGraphDescr(h, &g) );

  csc.nvertices = x.order();
  csc.nedges    = x.size();
  csc.destination_offsets = vfrom.data();
  csc.source_indices      = efrom.data();
  TRY( nvgraphSetGraphStructure(h, g, &csc, NVGRAPH_CSC_32) );

  TRY( nvgraphAllocateVertexData(h, g, vtype.size(), vtype.data()) );
  TRY( nvgraphAllocateEdgeData  (h, g, etype.size(), etype.data()) );
  TRY( nvgraphSetVertexData(h, g, vdata.data(), 0) );
  TRY( nvgraphSetVertexData(h, g, ranks.data(), 1) );
  TRY( nvgraphSetEdgeData  (h, g, edata.data(), 0) );

  t = measureDuration([&]() { TRY( nvgraphPagerank(h, g, 0, &p, 0, 0, 1, E, R) ); }, T);
  TRY( nvgraphGetVertexData(h, g, ranks.data(), 1) );

  TRY( nvgraphDestroyGraphDescr(h, g) );
  TRY( nvgraphDestroy(h) );
  return vertexContainer(x, ranks, ks);
}
