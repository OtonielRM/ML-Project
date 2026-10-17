# Derivations Book

Every theorem, estimator, loss and update rule from the curriculum, derived in my own words.
A result is marked *derived* only once I can reproduce the full proof closed-book.

**Latest PDF:** download the `derivations-book` artifact from the most recent
[derivations workflow run](https://github.com/OtonielRM/ML-Project/actions/workflows/derivations.yml).

## Build locally (WSL)

```bash
latexmk main.tex        # → build/main.pdf
latexmk -pvc main.tex   # rebuild automatically on every save
```

## Layout

```
main.tex           book skeleton: one \input per chapter
preamble.tex       packages, theorem environments, notation macros
chapters/          00-notation, 01-linear-algebra, ... (one chapter per study-plan Topic)
```
