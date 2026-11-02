# cpp-projects

A home for my C++ projects.

## Requirements

- A C++20 compiler (`g++` 11+ or `clang++` 14+)
- `make`

## Build and run

```bash
make        # builds build/app
make run    # builds, then runs it
make clean  # removes build/
```

## Layout

```
.
├── include/     # public headers
├── src/         # source files
├── Makefile
└── README.md
```

## Adding a project

Each subfolder under `src/` (or a new sibling folder) can be its own experiment.
Compile a single file quickly with:

```bash
g++ -std=c++20 -Wall -Wextra src/main.cpp -o build/app
```
