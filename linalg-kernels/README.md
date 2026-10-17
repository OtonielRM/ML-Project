# linalg-kernels

Dense linear algebra kernels written from scratch in C++20: matmul, LU (partial pivoting),
QR (Gram–Schmidt, Householder), and randomized SVD. Correctness is checked against NumPy
with fixed tolerances; every test also runs under AddressSanitizer + UBSan.

## Build & test

Requires CMake ≥ 3.25 and GCC or Clang (Linux / WSL2).

```bash
cmake --preset asan            # Debug + ASan/UBSan (default for development)
cmake --build --preset asan
ctest --preset asan
```

Other presets: `debug` (no sanitizers), `release` (for benchmarks).

## Layout

```
include/linalg/   public headers
src/              implementations
tests/            GoogleTest suites
```

## Roadmap

- [x] Build skeleton: CMake + GoogleTest + sanitizers, green smoke test
- [ ] Dense matrix type + matmul (naive → blocked), validated against NumPy
- [ ] LU with partial pivoting
- [ ] QR: classical/modified Gram–Schmidt vs Householder (orthogonality loss study)
- [ ] Randomized SVD: error vs rank vs dense SVD
