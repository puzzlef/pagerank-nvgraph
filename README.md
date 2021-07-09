Performance of **sequential** execution based vs [nvGraph] based PageRank
([pull], [CSR]).

This experiment was for comparing the performance between:
1. Find pagerank using a single thread (**sequential**).
2. Find pagerank using **nvGraph**.

Both methods were attempted on different types of graphs, running each method
5 times per graph to get a good time measure. **nvGraph** is clearly **way**
**faster** than the *sequential* version. This is as expected because
**nvGraph** makes use of *GPU* to speed up performance. It should be noted
that for graphs `soc-LiveJournal1` and `indochina-2004` the absolute error
between *nvGraph* and *sequential* method is higher. This could be because of
floating-point accuracy issues when generating input for [nvgraphPagerank()]
and by the order in which calculations are performed on both methods. Also note
that *sequential* approach does not make use of *SIMD instructions* which are
available on all modern hardware.

All outputs are saved in [out](out/) and a small part of the output is listed
here. Some [charts] are also included below, generated from [sheets]. The input
data used for this experiment is available at ["graphs"] (for small ones), and
the [SuiteSparse Matrix Collection]. This experiment was done with guidance
from [Prof. Dip Sankar Banerjee] and [Prof. Kishore Kothapalli].

<br>

```bash
$ nvcc -std=c++17 -Xcompiler -lnvgraph -O3 main.cu
$ ./a.out ~/data/min-1DeadEnd.mtx
$ ./a.out ~/data/min-2SCC.mtx
$ ...

# ...
#
# Loading graph /home/subhajit/data/web-Stanford.mtx ...
# order: 281903 size: 2312497 {}
# order: 281903 size: 2312497 {} (transposeWithDegree)
# [00393.616 ms; 063 iters.] [0.0000e+00 err.] pagerankSeq
# [00011.227 ms; 000 iters.] [5.0388e-06 err.] pagerankNvgraph
#
# ...
#
# Loading graph /home/subhajit/data/soc-LiveJournal1.mtx ...
# order: 4847571 size: 68993773 {}
# order: 4847571 size: 68993773 {} (transposeWithDegree)
# [11527.516 ms; 051 iters.] [0.0000e+00 err.] pagerankSeq
# [00168.264 ms; 000 iters.] [2.0581e-03 err.] pagerankNvgraph
#
# ...
```

[![](https://i.imgur.com/uFjTkDm.png)][sheets]
[![](https://i.imgur.com/N74HpJk.png)][sheets]

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

[![](https://i.imgur.com/iPxcsyw.jpg)](https://www.youtube.com/watch?v=fb4hqKzp_AA)

[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://cstar.iiit.ac.in/~kkishore/
[SuiteSparse Matrix Collection]: https://suitesparse-collection-website.herokuapp.com
["graphs"]: https://github.com/puzzlef/graphs
[nvGraph]: https://github.com/rapidsai/nvgraph
[nvgraphPagerank()]: https://docs.nvidia.com/cuda/archive/10.0/nvgraph/index.html#function-nvgraphpagerank
[pull]: https://github.com/puzzlef/pagerank-push-vs-pull
[CSR]: https://github.com/puzzlef/pagerank-class-vs-csr
[charts]: https://photos.app.goo.gl/4ndSneF8bFjyNxvS8
[sheets]: https://docs.google.com/spreadsheets/d/1GJkhoCRJAc7OXM56Vz8XbfPE8Iek2pp6Kf-PpTOmBAw/edit?usp=sharing
