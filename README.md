# cpp-lab

A home for my C++ projects.

## Requirements

- A C++20 compiler (`g++` 11+ or `clang++` 14+)
- `make`

## Build and run

```bash
make            # optimized build -> build/app
make run        # build and run
make debug      # unoptimized build with symbols -> build/debug/app
make run-debug  # debug build and run
make sanitize   # AddressSanitizer + UBSan build, then run
make clean      # remove build/
```

`make sanitize` is the quickest way to catch memory errors and undefined
behavior while iterating.

## Layout

```
.
├── include/         # public headers
├── src/             # source files
├── .clangd          # flags for clangd (editor intelligence)
├── .clang-format    # formatting rules
├── .vscode/         # VS Code build/debug/IntelliSense config
├── Makefile
└── README.md
```

## Editor setup (VS Code)

This is the easiest way to work on the project. Open the folder:

```bash
code ~/cpp-lab
```

Then, inside VS Code:

- **`Ctrl+Shift+B`** — build (runs `make debug`). Errors appear under the *Problems* tab.
- **`F5`** — build and start the debugger. Click in the gutter to set breakpoints.
- **`Ctrl+F5`** — build and run without the debugger.
- **Source Control panel** (left sidebar, the branch icon) — type a message, click
  the **✓ Commit** button, then **Sync Changes** to push to GitHub. No terminal needed.

The repo already contains everything needed: `.vscode/tasks.json` (build task),
`.vscode/launch.json` (gdb debugger), and `.vscode/c_cpp_properties.json`
(IntelliSense include paths and C++20).

## Adding a project

Each subfolder under `src/` (or a new sibling folder) can be its own experiment.
Compile a single file quickly with:

```bash
g++ -std=c++20 -Wall -Wextra src/main.cpp -o build/app
```
