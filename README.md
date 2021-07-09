Performance of **OpenMP** based vs [nvGraph] based PageRank ([pull], [CSR]).

This experiment was for comparing the performance between:
1. Find pagerank accelerated using **OpenMP**.
2. Find pagerank using **nvGraph**.

Both methods were attempted on different types of graphs, running each method
5 times per graph to get a good time measure. Number of threads for this
experiment (using `OMP_NUM_THREADS`) was varied from `2` to `48`. **nvGraph**
is clearly **way faster** than the *OpenMP* version. This is as expected because
**nvGraph** makes use of *GPU* to speed up performance. Note that the *OpenMP*
approach does not make use of *SIMD instructions* which are available on all
modern hardware.

All outputs are saved in [out](out/) and a small part of the output is listed
here. Some [charts] are also included below, generated from [sheets]. The input
data used for this experiment is available at ["graphs"] (for small ones), and
the [SuiteSparse Matrix Collection]. This experiment was done with guidance
from [Prof. Dip Sankar Banerjee] and [Prof. Kishore Kothapalli].

<br>

```bash
$ nvcc -std=c++17 -Xcompiler -fopenmp -lnvgraph -O3 main.cu
$ export OMP_NUM_THREADS=4
$ ./a.out ~/data/min-1DeadEnd.mtx
$ ./a.out ~/data/min-2SCC.mtx
$ ...

# ...
#
# Loading graph /home/subhajit/data/web-Stanford.mtx ...
# order: 281903 size: 2312497 {}
# order: 281903 size: 2312497 {} (transposeWithDegree)
# [00121.686 ms; 063 iters.] [0.0000e+00 err.] pagerankOmp
# [00011.373 ms; 000 iters.] [4.9306e-06 err.] pagerankNvgraph
#
# ...
#
# Loading graph /home/subhajit/data/soc-LiveJournal1.mtx ...
# order: 4847571 size: 68993773 {}
# order: 4847571 size: 68993773 {} (transposeWithDegree)
# [04262.776 ms; 051 iters.] [0.0000e+00 err.] pagerankOmp
# [00167.619 ms; 000 iters.] [2.4506e-06 err.] pagerankNvgraph
#
# ...
```

<br>

```bash
$ nvcc -std=c++17 -Xcompiler -fopenmp -lnvgraph -O3 main.cu
$ export OMP_NUM_THREADS=48
$ ./a.out ~/data/min-1DeadEnd.mtx
$ ./a.out ~/data/min-2SCC.mtx
$ ...

# ...
#
# Loading graph /home/subhajit/data/web-Stanford.mtx ...
# order: 281903 size: 2312497 {}
# order: 281903 size: 2312497 {} (transposeWithDegree)
# [00050.413 ms; 063 iters.] [0.0000e+00 err.] pagerankOmp
# [00010.514 ms; 000 iters.] [5.0267e-06 err.] pagerankNvgraph
#
# ...
#
# Loading graph /home/subhajit/data/soc-LiveJournal1.mtx ...
# order: 4847571 size: 68993773 {}
# order: 4847571 size: 68993773 {} (transposeWithDegree)
# [00861.084 ms; 051 iters.] [0.0000e+00 err.] pagerankOmp
# [00168.043 ms; 000 iters.] [3.8261e-06 err.] pagerankNvgraph
#
# ...
```

[![](https://i.imgur.com/bFwKlkB.gif)][sheets]

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
["graphs"]: https://github.com/puzzlef/graphs
[nvGraph]: https://github.com/rapidsai/nvgraph
[pull]: https://github.com/puzzlef/pagerank-push-vs-pull
[CSR]: https://github.com/puzzlef/pagerank-class-vs-csr
[charts]: https://photos.app.goo.gl/3KHG4VgGQz3vK8yg8
[sheets]: https://docs.google.com/spreadsheets/d/1fzCIqNjLQguzfpWXUZRR3DknqEwwyFW5hMsgP4TFRwM/edit?usp=sharing
