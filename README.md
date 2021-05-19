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

# Loading graph /home/subhajit/data/min-1DeadEnd.mtx ...
# order: 5 size: 6 {}
# order: 5 size: 6 {} (transposeWithDegree)
# [00000.001 ms; 017 iters.] [0.0000e+00 err.] pagerankSeq
# [00001.561 ms; 000 iters.] [1.3411e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-2SCC.mtx ...
# order: 8 size: 12 {}
# order: 8 size: 12 {} (transposeWithDegree)
# [00000.002 ms; 040 iters.] [0.0000e+00 err.] pagerankSeq
# [00003.883 ms; 000 iters.] [9.1270e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-4SCC.mtx ...
# order: 21 size: 35 {}
# order: 21 size: 35 {} (transposeWithDegree)
# [00000.006 ms; 045 iters.] [0.0000e+00 err.] pagerankSeq
# [00003.944 ms; 000 iters.] [6.1560e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-NvgraphEx.mtx ...
# order: 6 size: 10 {}
# order: 6 size: 10 {} (transposeWithDegree)
# [00000.001 ms; 024 iters.] [0.0000e+00 err.] pagerankSeq
# [00002.111 ms; 000 iters.] [2.9802e-08 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-Stanford.mtx ...
# order: 281903 size: 2312497 {}
# order: 281903 size: 2312497 {} (transposeWithDegree)
# [00393.616 ms; 063 iters.] [0.0000e+00 err.] pagerankSeq
# [00011.227 ms; 000 iters.] [5.0388e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-BerkStan.mtx ...
# order: 685230 size: 7600595 {}
# order: 685230 size: 7600595 {} (transposeWithDegree)
# [00855.541 ms; 064 iters.] [0.0000e+00 err.] pagerankSeq
# [00016.368 ms; 000 iters.] [2.3699e-05 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-Google.mtx ...
# order: 916428 size: 5105039 {}
# order: 916428 size: 5105039 {} (transposeWithDegree)
# [01468.480 ms; 061 iters.] [0.0000e+00 err.] pagerankSeq
# [00019.868 ms; 000 iters.] [5.1346e-04 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-NotreDame.mtx ...
# order: 325729 size: 1497134 {}
# order: 325729 size: 1497134 {} (transposeWithDegree)
# [00207.833 ms; 058 iters.] [0.0000e+00 err.] pagerankSeq
# [00008.241 ms; 000 iters.] [7.7281e-04 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Slashdot0811.mtx ...
# order: 77360 size: 905468 {}
# order: 77360 size: 905468 {} (transposeWithDegree)
# [00086.885 ms; 055 iters.] [0.0000e+00 err.] pagerankSeq
# [00006.649 ms; 000 iters.] [9.8525e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Slashdot0902.mtx ...
# order: 82168 size: 948464 {}
# order: 82168 size: 948464 {} (transposeWithDegree)
# [00096.232 ms; 056 iters.] [0.0000e+00 err.] pagerankSeq
# [00007.010 ms; 000 iters.] [4.4357e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Epinions1.mtx ...
# order: 75888 size: 508837 {}
# order: 75888 size: 508837 {} (transposeWithDegree)
# [00077.752 ms; 054 iters.] [0.0000e+00 err.] pagerankSeq
# [00006.684 ms; 000 iters.] [2.6672e-05 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coAuthorsDBLP.mtx ...
# order: 299067 size: 1955352 {}
# order: 299067 size: 1955352 {} (transposeWithDegree)
# [00226.548 ms; 045 iters.] [0.0000e+00 err.] pagerankSeq
# [00007.268 ms; 000 iters.] [2.9339e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coAuthorsCiteseer.mtx ...
# order: 227320 size: 1628268 {}
# order: 227320 size: 1628268 {} (transposeWithDegree)
# [00184.522 ms; 048 iters.] [0.0000e+00 err.] pagerankSeq
# [00007.048 ms; 000 iters.] [2.1900e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-LiveJournal1.mtx ...
# order: 4847571 size: 68993773 {}
# order: 4847571 size: 68993773 {} (transposeWithDegree)
# [11527.516 ms; 051 iters.] [0.0000e+00 err.] pagerankSeq
# [00168.264 ms; 000 iters.] [2.0581e-03 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coPapersCiteseer.mtx ...
# order: 434102 size: 32073440 {}
# order: 434102 size: 32073440 {} (transposeWithDegree)
# [02145.250 ms; 051 iters.] [0.0000e+00 err.] pagerankSeq
# [00025.982 ms; 000 iters.] [1.9895e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coPapersDBLP.mtx ...
# order: 540486 size: 30491458 {}
# order: 540486 size: 30491458 {} (transposeWithDegree)
# [02060.091 ms; 049 iters.] [0.0000e+00 err.] pagerankSeq
# [00024.859 ms; 000 iters.] [1.4915e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/indochina-2004.mtx ...
# order: 7414866 size: 194109311 {}
# order: 7414866 size: 194109311 {} (transposeWithDegree)
# [18560.754 ms; 061 iters.] [0.0000e+00 err.] pagerankSeq
# [00193.906 ms; 000 iters.] [7.8820e-04 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/italy_osm.mtx ...
# order: 6686493 size: 14027956 {}
# order: 6686493 size: 14027956 {} (transposeWithDegree)
# [04029.127 ms; 063 iters.] [0.0000e+00 err.] pagerankSeq
# [00061.948 ms; 000 iters.] [6.4568e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/great-britain_osm.mtx ...
# order: 7733822 size: 16313034 {}
# order: 7733822 size: 16313034 {} (transposeWithDegree)
# [06301.550 ms; 067 iters.] [0.0000e+00 err.] pagerankSeq
# [00076.258 ms; 000 iters.] [1.6188e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/germany_osm.mtx ...
# order: 11548845 size: 24738362 {}
# order: 11548845 size: 24738362 {} (transposeWithDegree)
# [10315.133 ms; 065 iters.] [0.0000e+00 err.] pagerankSeq
# [00113.886 ms; 000 iters.] [2.0173e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/asia_osm.mtx ...
# order: 11950757 size: 25423206 {}
# order: 11950757 size: 25423206 {} (transposeWithDegree)
# [07562.224 ms; 063 iters.] [0.0000e+00 err.] pagerankSeq
# [00107.775 ms; 000 iters.] [6.7846e-07 err.] pagerankNvgraph
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
