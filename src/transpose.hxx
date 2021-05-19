#pragma once
#include "DiGraph.hxx"




// TRANSPOSE
// ---------

template <class H, class G>
void transpose(H& a, const G& x) {
  for (int u : x.vertices())
    a.addVertex(u, x.vertexData(u));
  for (int u : x.vertices()) {
    for (int v : x.edges(u))
      a.addEdge(v, u, x.edgeData(u, v));
  }
}

template <class G>
auto transpose(const G& x) {
  G a; transpose(a, x);
  return a;
}




// TRANSPOSE-WITH-DEGREE
// ---------------------

template <class H, class G>
void transposeWithDegree(H& a, const G& x) {
  for (int u : x.vertices())
    a.addVertex(u, x.degree(u));
  for (int u : x.vertices()) {
    for (int v : x.edges(u))
      a.addEdge(v, u, x.edgeData(u, v));
  }
}

template <class G>
auto transposeWithDegree(const G& x) {
  using E = typename G::TEdge;
  DiGraph<int, E> a; transposeWithDegree(a, x);
  return a;
}
/*



// TRANSPOSE-FOR-NVGRAPH
// ---------------------

template <class G, class H>
void transposeForNvgraph(H& a, G& x) {
  using V = typename H::TVertex;
  using E = typename H::TEdge;
  for (int u : x.vertices())
    a.addVertex(u, x.degree(u) == 0? V(1) : V(0));
  for (int u : x.vertices()) {
    for (int v : x.edges(u))
      a.addEdge(v, u, E(1)/x.degree(u));
  }
}

template <class G>
auto transposeForNvgraph(G& x) {
  DiGraph<float, float> a; transposeForNvgraph(a, x);
  return a;
}
*/
