# ML-Project

Monorepo for my from-scratch ML curriculum: numerical kernels, learning algorithms,
and systems work in C++, Python and Java. Every project folder is self-contained and
its README doubles as a short technical report (question → method → results → limits).

## Projects

| Project | Language | Topic | Status |
|---|---|---|---|
| [`linalg-kernels`](linalg-kernels/) | C++20 | Dense linear algebra from scratch (matmul, LU, QR, randomized SVD) | scaffold |

## Conventions

- **From scratch first:** libraries are used only as references/oracles in tests.
- **Every figure is regenerable** from a script in the project folder.
- **Tests are green under sanitizers** (ASan + UBSan) before anything is merged.
