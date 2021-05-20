Performance of **OpenMP** based vs [nvGraph] based PageRank ([pull], [CSR]).

This experiment was for comparing the performance between:
1. Find pagerank accelerated using **OpenMP**.
2. Find pagerank using **nvGraph**.

Both methods were attempted on different types of graphs, running each method
5 times per graph to get a good time measure. **nvGraph** is clearly way faster
than the **OpenMP** version. This is as expected because **nvGraph** makes
use of *GPU* to speed up performance.

Number of threads for this experiment (using `OMP_NUM_THREADS`) was varied
from `2` to `48`. All outputs are saved in [out/](out/) and outputs for `4`,
`48` threads are listed here. The input data used for this experiment is
available at ["graphs"] (for small ones), and the [SuiteSparse Matrix Collection].

<br>

```bash
$ nvcc -std=c++17 -Xcompiler -fopenmp -lnvgraph -O3 main.cxx
$ export OMP_NUM_THREADS=4
$ ./a.out ~/data/min-1DeadEnd.mtx
$ ./a.out ~/data/min-2SCC.mtx
$ ...

# Loading graph /home/subhajit/data/min-1DeadEnd.mtx ...
# order: 5 size: 6 {}
# order: 5 size: 6 {} (transposeWithDegree)
# [00000.524 ms; 017 iters.] [0.0000e+00 err.] pagerankOmp
# [00001.546 ms; 000 iters.] [1.3411e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-2SCC.mtx ...
# order: 8 size: 12 {}
# order: 8 size: 12 {} (transposeWithDegree)
# [00001.134 ms; 040 iters.] [0.0000e+00 err.] pagerankOmp
# [00003.931 ms; 000 iters.] [9.1270e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-4SCC.mtx ...
# order: 21 size: 35 {}
# order: 21 size: 35 {} (transposeWithDegree)
# [00001.274 ms; 045 iters.] [0.0000e+00 err.] pagerankOmp
# [00004.298 ms; 000 iters.] [6.1560e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-NvgraphEx.mtx ...
# order: 6 size: 10 {}
# order: 6 size: 10 {} (transposeWithDegree)
# [00000.718 ms; 024 iters.] [0.0000e+00 err.] pagerankOmp
# [00002.086 ms; 000 iters.] [2.9802e-08 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-Stanford.mtx ...
# order: 281903 size: 2312497 {}
# order: 281903 size: 2312497 {} (transposeWithDegree)
# [00121.686 ms; 063 iters.] [0.0000e+00 err.] pagerankOmp
# [00011.373 ms; 000 iters.] [4.9306e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-BerkStan.mtx ...
# order: 685230 size: 7600595 {}
# order: 685230 size: 7600595 {} (transposeWithDegree)
# [00288.220 ms; 064 iters.] [0.0000e+00 err.] pagerankOmp
# [00016.489 ms; 000 iters.] [2.0907e-05 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-Google.mtx ...
# order: 916428 size: 5105039 {}
# order: 916428 size: 5105039 {} (transposeWithDegree)
# [00452.813 ms; 062 iters.] [0.0000e+00 err.] pagerankOmp
# [00019.864 ms; 000 iters.] [2.3635e-05 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-NotreDame.mtx ...
# order: 325729 size: 1497134 {}
# order: 325729 size: 1497134 {} (transposeWithDegree)
# [00069.445 ms; 058 iters.] [0.0000e+00 err.] pagerankOmp
# [00008.246 ms; 000 iters.] [2.6627e-05 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Slashdot0811.mtx ...
# order: 77360 size: 905468 {}
# order: 77360 size: 905468 {} (transposeWithDegree)
# [00033.043 ms; 055 iters.] [0.0000e+00 err.] pagerankOmp
# [00006.578 ms; 000 iters.] [1.0596e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Slashdot0902.mtx ...
# order: 82168 size: 948464 {}
# order: 82168 size: 948464 {} (transposeWithDegree)
# [00035.620 ms; 056 iters.] [0.0000e+00 err.] pagerankOmp
# [00007.000 ms; 000 iters.] [8.3158e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Epinions1.mtx ...
# order: 75888 size: 508837 {}
# order: 75888 size: 508837 {} (transposeWithDegree)
# [00036.236 ms; 054 iters.] [0.0000e+00 err.] pagerankOmp
# [00007.145 ms; 000 iters.] [2.7193e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coAuthorsDBLP.mtx ...
# order: 299067 size: 1955352 {}
# order: 299067 size: 1955352 {} (transposeWithDegree)
# [00086.488 ms; 045 iters.] [0.0000e+00 err.] pagerankOmp
# [00007.089 ms; 000 iters.] [2.9339e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coAuthorsCiteseer.mtx ...
# order: 227320 size: 1628268 {}
# order: 227320 size: 1628268 {} (transposeWithDegree)
# [00068.508 ms; 048 iters.] [0.0000e+00 err.] pagerankOmp
# [00006.691 ms; 000 iters.] [2.1900e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-LiveJournal1.mtx ...
# order: 4847571 size: 68993773 {}
# order: 4847571 size: 68993773 {} (transposeWithDegree)
# [04262.776 ms; 051 iters.] [0.0000e+00 err.] pagerankOmp
# [00167.619 ms; 000 iters.] [2.4506e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coPapersCiteseer.mtx ...
# order: 434102 size: 32073440 {}
# order: 434102 size: 32073440 {} (transposeWithDegree)
# [00701.838 ms; 051 iters.] [0.0000e+00 err.] pagerankOmp
# [00026.049 ms; 000 iters.] [1.9895e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coPapersDBLP.mtx ...
# order: 540486 size: 30491458 {}
# order: 540486 size: 30491458 {} (transposeWithDegree)
# [00669.905 ms; 049 iters.] [0.0000e+00 err.] pagerankOmp
# [00024.839 ms; 000 iters.] [1.4915e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/indochina-2004.mtx ...
# order: 7414866 size: 194109311 {}
# order: 7414866 size: 194109311 {} (transposeWithDegree)
# [06617.489 ms; 060 iters.] [0.0000e+00 err.] pagerankOmp
# [00193.993 ms; 000 iters.] [1.0540e-04 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/italy_osm.mtx ...
# order: 6686493 size: 14027956 {}
# order: 6686493 size: 14027956 {} (transposeWithDegree)
# [01571.808 ms; 063 iters.] [0.0000e+00 err.] pagerankOmp
# [00062.091 ms; 000 iters.] [6.4568e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/great-britain_osm.mtx ...
# order: 7733822 size: 16313034 {}
# order: 7733822 size: 16313034 {} (transposeWithDegree)
# [02311.328 ms; 067 iters.] [0.0000e+00 err.] pagerankOmp
# [00076.372 ms; 000 iters.] [1.6188e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/germany_osm.mtx ...
# order: 11548845 size: 24738362 {}
# order: 11548845 size: 24738362 {} (transposeWithDegree)
# [03769.150 ms; 065 iters.] [0.0000e+00 err.] pagerankOmp
# [00113.907 ms; 000 iters.] [2.0173e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/asia_osm.mtx ...
# order: 11950757 size: 25423206 {}
# order: 11950757 size: 25423206 {} (transposeWithDegree)
# [02780.383 ms; 063 iters.] [0.0000e+00 err.] pagerankOmp
# [00107.975 ms; 000 iters.] [6.7846e-07 err.] pagerankNvgraph
```

<br>

```bash
$ nvcc -std=c++17 -Xcompiler -fopenmp -lnvgraph -O3 main.cxx
$ export OMP_NUM_THREADS=48
$ ./a.out ~/data/min-1DeadEnd.mtx
$ ./a.out ~/data/min-2SCC.mtx
$ ...

# Loading graph /home/subhajit/data/min-1DeadEnd.mtx ...
# order: 5 size: 6 {}
# order: 5 size: 6 {} (transposeWithDegree)
# [00019.752 ms; 017 iters.] [0.0000e+00 err.] pagerankOmp
# [00001.523 ms; 000 iters.] [1.3411e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-2SCC.mtx ...
# order: 8 size: 12 {}
# order: 8 size: 12 {} (transposeWithDegree)
# [00022.059 ms; 040 iters.] [0.0000e+00 err.] pagerankOmp
# [00003.559 ms; 000 iters.] [9.1270e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-4SCC.mtx ...
# order: 21 size: 35 {}
# order: 21 size: 35 {} (transposeWithDegree)
# [00022.613 ms; 045 iters.] [0.0000e+00 err.] pagerankOmp
# [00003.898 ms; 000 iters.] [6.1560e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/min-NvgraphEx.mtx ...
# order: 6 size: 10 {}
# order: 6 size: 10 {} (transposeWithDegree)
# [00021.108 ms; 024 iters.] [0.0000e+00 err.] pagerankOmp
# [00002.077 ms; 000 iters.] [2.9802e-08 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-Stanford.mtx ...
# order: 281903 size: 2312497 {}
# order: 281903 size: 2312497 {} (transposeWithDegree)
# [00050.413 ms; 063 iters.] [0.0000e+00 err.] pagerankOmp
# [00010.514 ms; 000 iters.] [5.0267e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-BerkStan.mtx ...
# order: 685230 size: 7600595 {}
# order: 685230 size: 7600595 {} (transposeWithDegree)
# [00097.145 ms; 064 iters.] [0.0000e+00 err.] pagerankOmp
# [00016.074 ms; 000 iters.] [2.1006e-05 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-Google.mtx ...
# order: 916428 size: 5105039 {}
# order: 916428 size: 5105039 {} (transposeWithDegree)
# [00111.508 ms; 062 iters.] [0.0000e+00 err.] pagerankOmp
# [00021.094 ms; 000 iters.] [3.0537e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/web-NotreDame.mtx ...
# order: 325729 size: 1497134 {}
# order: 325729 size: 1497134 {} (transposeWithDegree)
# [00038.742 ms; 058 iters.] [0.0000e+00 err.] pagerankOmp
# [00008.288 ms; 000 iters.] [2.8748e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Slashdot0811.mtx ...
# order: 77360 size: 905468 {}
# order: 77360 size: 905468 {} (transposeWithDegree)
# [00043.888 ms; 055 iters.] [0.0000e+00 err.] pagerankOmp
# [00006.488 ms; 000 iters.] [9.7165e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Slashdot0902.mtx ...
# order: 82168 size: 948464 {}
# order: 82168 size: 948464 {} (transposeWithDegree)
# [00041.277 ms; 056 iters.] [0.0000e+00 err.] pagerankOmp
# [00006.662 ms; 000 iters.] [8.6331e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-Epinions1.mtx ...
# order: 75888 size: 508837 {}
# order: 75888 size: 508837 {} (transposeWithDegree)
# [00050.022 ms; 054 iters.] [0.0000e+00 err.] pagerankOmp
# [00006.708 ms; 000 iters.] [1.1072e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coAuthorsDBLP.mtx ...
# order: 299067 size: 1955352 {}
# order: 299067 size: 1955352 {} (transposeWithDegree)
# [00040.907 ms; 045 iters.] [0.0000e+00 err.] pagerankOmp
# [00007.129 ms; 000 iters.] [2.9339e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coAuthorsCiteseer.mtx ...
# order: 227320 size: 1628268 {}
# order: 227320 size: 1628268 {} (transposeWithDegree)
# [00038.926 ms; 048 iters.] [0.0000e+00 err.] pagerankOmp
# [00006.663 ms; 000 iters.] [2.1900e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/soc-LiveJournal1.mtx ...
# order: 4847571 size: 68993773 {}
# order: 4847571 size: 68993773 {} (transposeWithDegree)
# [00861.084 ms; 051 iters.] [0.0000e+00 err.] pagerankOmp
# [00168.043 ms; 000 iters.] [3.8261e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coPapersCiteseer.mtx ...
# order: 434102 size: 32073440 {}
# order: 434102 size: 32073440 {} (transposeWithDegree)
# [00221.938 ms; 051 iters.] [0.0000e+00 err.] pagerankOmp
# [00026.129 ms; 000 iters.] [1.9895e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/coPapersDBLP.mtx ...
# order: 540486 size: 30491458 {}
# order: 540486 size: 30491458 {} (transposeWithDegree)
# [00157.311 ms; 049 iters.] [0.0000e+00 err.] pagerankOmp
# [00024.380 ms; 000 iters.] [1.4915e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/indochina-2004.mtx ...
# order: 7414866 size: 194109311 {}
# order: 7414866 size: 194109311 {} (transposeWithDegree)
# [03993.056 ms; 061 iters.] [0.0000e+00 err.] pagerankOmp
# [00193.727 ms; 000 iters.] [9.3049e-06 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/italy_osm.mtx ...
# order: 6686493 size: 14027956 {}
# order: 6686493 size: 14027956 {} (transposeWithDegree)
# [00413.655 ms; 063 iters.] [0.0000e+00 err.] pagerankOmp
# [00062.250 ms; 000 iters.] [6.4568e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/great-britain_osm.mtx ...
# order: 7733822 size: 16313034 {}
# order: 7733822 size: 16313034 {} (transposeWithDegree)
# [00581.434 ms; 067 iters.] [0.0000e+00 err.] pagerankOmp
# [00076.217 ms; 000 iters.] [1.6188e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/germany_osm.mtx ...
# order: 11548845 size: 24738362 {}
# order: 11548845 size: 24738362 {} (transposeWithDegree)
# [00917.296 ms; 065 iters.] [0.0000e+00 err.] pagerankOmp
# [00114.520 ms; 000 iters.] [2.0173e-07 err.] pagerankNvgraph
#
# Loading graph /home/subhajit/data/asia_osm.mtx ...
# order: 11950757 size: 25423206 {}
# order: 11950757 size: 25423206 {} (transposeWithDegree)
# [00761.304 ms; 063 iters.] [0.0000e+00 err.] pagerankOmp
# [00107.759 ms; 000 iters.] [6.7846e-07 err.] pagerankNvgraph
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

[![](https://i.imgur.com/WKtzdoh.jpg)](https://www.youtube.com/watch?v=tIybKX2NKeo)

[nvGraph]: https://github.com/rapidsai/nvgraph
[pull]: https://github.com/puzzlef/pagerank-push-vs-pull
[CSR]: https://github.com/puzzlef/pagerank-class-vs-csr
["graphs"]: https://github.com/puzzlef/graphs
[SuiteSparse Matrix Collection]: https://suitesparse-collection-website.herokuapp.com
