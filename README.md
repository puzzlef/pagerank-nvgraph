Performance of **OpenMP** based vs [nvGraph] based PageRank (pull, CSR).

This experiment was for comparing the performance between:
1. Find pagerank accelerated using **OpenMP**.
2. Find pagerank using **nvGraph**.

Both methods were attempted on different types of graphs, running each method
5 times per graph to get a good time measure. **nvGraph** is clearly way faster
than the **sequential** version. This is as expected because **nvGraph** makes
use of *GPU* to speed up performance. It should be noted that for graphs
`soc-LiveJournal1` and `indochina-2004` the absolute error between **nvGraph**
and **sequential** method is higher. This could be because of floating-point
accuracy issues when generating input for [nvgraphPagerank()] and by the order
in which calculations are performed on both methods.

See ["pagerank-push-vs-pull"] for a discussion on *push* vs *pull* method, and
["pagerank-class-vs-csr"] for a comparision between using a C++ DiGraph class
directly vs using its CSR representation. The input data used for this
experiment is available at ["graphs"] (for small ones), and the
[SuiteSparse Matrix Collection].

<br>

```bash
$ nvcc -std=c++17 -Xcompiler -lnvgraph -O3 main.cxx
$ ./a.out ~/data/min-1DeadEnd.mtx
$ ./a.out ~/data/min-2SCC.mtx
$ ...

# ...
```

<br>
<br>


## References

- [nvGraph pagerank example, EN605.617, JHU-EP-Intro2GPU](https://github.com/JHU-EP-Intro2GPU/EN605.617/blob/master/module9/nvgraph_examples/nvgraph_Pagerank.cpp)
- [nvGraph pagerank example, CUDA Toolkit Documentation](https://docs.nvidia.com/cuda/archive/10.0/nvgraph/index.html#nvgraph-pagerank-example)
- [nvGraph Library User's Guide](https://docs.nvidia.com/cuda/archive/10.1/pdf/nvGRAPH_Library.pdf)
- [RAPIDS nvGraph NVIDIA graph library][nvGraph]
- [SuiteSparse Matrix Collection]

<br>
<br>

[![](https://i.imgur.com/iPxcsyw.jpg)](https://www.youtube.com/watch?v=fb4hqKzp_AA)

[nvGraph]: https://github.com/rapidsai/nvgraph
[nvgraphPagerank()]: https://docs.nvidia.com/cuda/archive/10.0/nvgraph/index.html#function-nvgraphpagerank
["pagerank-push-vs-pull"]: https://github.com/puzzlef/pagerank-push-vs-pull
["pagerank-class-vs-csr"]: https://github.com/puzzlef/pagerank-class-vs-csr
["graphs"]: https://github.com/puzzlef/graphs
[SuiteSparse Matrix Collection]: https://suitesparse-collection-website.herokuapp.com
