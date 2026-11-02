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
├── .clang-format    # formatting rules, used by clangd's formatter
├── .zed/            # Zed project config (debugger + format on save)
├── Makefile
└── README.md
```

## Editor setup (Zed)

The repo ships with:

- `.clangd` — gives clangd the include path and language standard, so no
  `compile_commands.json` is needed. Without this, clangd guesses and reports
  false errors on standard headers.
- `.zed/debug.json` — a ready-made debug configuration. Press `F4`
  (*debugger: start*), pick **Debug app (CodeLLDB)**, and it runs `make debug`
  before launching. The first launch prompts to install the CodeLLDB extension.
  If you prefer GDB, change `"adapter": "CodeLLDB"` to `"adapter": "GDB"`
  (needs `gdb` 14.1+).
- `.zed/settings.json` — format on save for C++.

## Adding a project

Each subfolder under `src/` (or a new sibling folder) can be its own experiment.
Compile a single file quickly with:

```bash
g++ -std=c++20 -Wall -Wextra src/main.cpp -o build/app
```
