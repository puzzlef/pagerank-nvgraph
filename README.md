Comparision of **nvGraph PageRank** with CPU-based implementations.

<br>


### Comparision with Sequential implementation

This experiment ([compare-sequential]) was for comparing the performance between
finding pagerank using a single thread (**sequential**), and finding pagerank
using **nvGraph**. Both methods were attempted on different types of graphs,
running each method 5 times per graph to get a good time measure.

**nvGraph** is clearly **way** **faster** than the *sequential* version. This is
as expected because **nvGraph** makes use of *GPU* to speed up performance. It
should be noted that for graphs `soc-LiveJournal1` and `indochina-2004` the
absolute error between *nvGraph* and *sequential* method is higher. This could
be because of floating-point accuracy issues when generating input for
[nvgraphPagerank()] and by the order in which calculations are performed on both
methods.

[compare-sequential]: https://github.com/puzzlef/pagerank-nvgraph/tree/compare-sequential

<br>


### Comparision with OpenMP-based implementation

This experiment ([compare-openmp]) was for comparing the performance between
finding pagerank accelerated using **OpenMP**, and find pagerank using
**nvGraph**. Both methods were attempted on different types of graphs, running
each method 5 times per graph to get a good time measure. Number of threads for
this experiment (using `OMP_NUM_THREADS`) was varied from `2` to `48`.

**nvGraph** is clearly **way faster** than the *OpenMP* version. This is as
expected because **nvGraph** makes use of *GPU* to speed up performance. Note
that the *OpenMP* approach does not make use of *SIMD instructions* which are
available on all modern hardware.

[![](https://i.imgur.com/bFwKlkB.gif)][sheets]

[compare-openmp]: https://github.com/puzzlef/pagerank-nvgraph/tree/compare-openmp

<br>
<br>


## References

- [nvGraph pagerank example, EN605.617, JHU-EP-Intro2GPU](https://github.com/JHU-EP-Intro2GPU/EN605.617/blob/master/module9/nvgraph_examples/nvgraph_Pagerank.cpp)
- [nvGraph pagerank example, CUDA Toolkit Documentation](https://docs.nvidia.com/cuda/archive/10.0/nvgraph/index.html#nvgraph-pagerank-example)
- [nvGraph Library User's Guide](https://docs.nvidia.com/cuda/archive/10.1/pdf/nvGRAPH_Library.pdf)
- [RAPIDS nvGraph NVIDIA graph library][nvGraph]
- [PageRank Algorithm, Mining massive Datasets (CS246), Stanford University](https://www.youtube.com/watch?v=ke9g8hB0MEo)
- [SuiteSparse Matrix Collection]

<br>
<br>


[![](https://i.imgur.com/WKtzdoh.jpg)](https://www.youtube.com/watch?v=tIybKX2NKeo)


[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://cstar.iiit.ac.in/~kkishore/
[SuiteSparse Matrix Collection]: https://suitesparse-collection-website.herokuapp.com
[nvGraph]: https://github.com/rapidsai/nvgraph
[nvgraphPagerank()]: https://docs.nvidia.com/cuda/archive/10.0/nvgraph/index.html#function-nvgraphpagerank
[charts]: https://photos.app.goo.gl/3KHG4VgGQz3vK8yg8
[sheets]: https://docs.google.com/spreadsheets/d/1fzCIqNjLQguzfpWXUZRR3DknqEwwyFW5hMsgP4TFRwM/edit?usp=sharing
