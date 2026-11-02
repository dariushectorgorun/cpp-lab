# Tic-Tac-Toe (C++)

A 3x3 tic-tac-toe game that runs in the terminal. Two players, X and O,
taking turns on the same keyboard.

This is a learning project: the board, the input handling, and the main
game loop are written for you. **The win detection and draw detection are
your job** — look for the two `TODO` blocks in `src/main.cpp`.

## Build and play

```bash
make run        # build and play
make debug      # build a debuggable version
make sanitize   # build with AddressSanitizer and run
```

In VS Code, open this folder and press **`F5`** to build and debug.

## How to play

Type two numbers: the row, then the column, both from 1 to 3.

```
   1   2   3
1  . | . | .
  ---+---+---
2  . | . | .
  ---+---+---
3  . | . | .

Enter row and column (1-3, e.g. 2 3): 2 2
```

## Your tasks

### TODO 1: `hasWon(board, player)`

Return `true` when `player` has three in a row. There are 8 lines to check:

```
rows:      (0,0)(0,1)(0,2)   (1,0)(1,1)(1,2)   (2,0)(2,1)(2,2)
columns:   (0,0)(1,0)(2,0)   (0,1)(1,1)(2,1)   (0,2)(1,2)(2,2)
diagonals: (0,0)(1,1)(2,2)   (0,2)(1,1)(2,0)
```

Watch out: an empty cell is `'.'`. Three empty cells in a row are equal to
each other but that is **not** a win, so each cell must equal `player`.

### TODO 2: `isFull(board)`

Return `true` when no `'.'` cells remain. That, with no winner, means a draw.

## Milestones

- [x] Board printing and coordinate input
- [x] Reject moves that are off the board or on a taken square
- [ ] **Win detection** (`hasWon`)
- [ ] **Draw detection** (`isFull`)
- [ ] Random AI opponent
- [ ] Minimax AI (never loses)
- [ ] Refactor into a `Game` class
- [ ] Alpha-beta pruning

## Debugging tip

Set a breakpoint inside `hasWon` and press `F5`. Every time a move is
played you will stop there, and the **Variables** panel shows you the board
contents. That is the fastest way to see whether your check is looking at
the cells you think it is.

## Rules reminder

X goes first. Alternate turns. First player with three in a row wins.
If the board fills with no winner, it is a draw.
