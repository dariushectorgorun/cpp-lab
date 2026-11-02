// Tic-Tac-Toe — Milestone 1: two humans, hot-seat.
//
// Everything here works EXCEPT the two functions marked TODO near the
// bottom: hasWon() and isFull(). That's your job.
//
// Build and play:   make run
// Debug it:         make debug, then F5 in VS Code

#include <array>
#include <iostream>
#include <limits>

constexpr int SIZE = 3;  // 3x3 board

// The board is 9 cells stored in a flat array of chars.
// '.' means empty, otherwise 'X' or 'O'.
using Board = std::array<char, SIZE * SIZE>;

// Maps a (row, col) pair to a position in the flat array.
// Row 0, col 0 -> 0.  Row 0, col 2 -> 2.  Row 1, col 0 -> 3.  etc.
int indexOf(int row, int col) { return row * SIZE + col; }

void printBoard(const Board& board) {
    std::cout << "\n   1   2   3\n";
    for (int row = 0; row < SIZE; ++row) {
        std::cout << (row + 1) << "  ";
        for (int col = 0; col < SIZE; ++col) {
            std::cout << board[indexOf(row, col)];
            if (col < SIZE - 1) {
                std::cout << " | ";
            }
        }
        std::cout << '\n';
        if (row < SIZE - 1) {
            std::cout << "  ---+---+---\n";
        }
    }
    std::cout << '\n';
}

// Asks the player for a move like "2 3" (row then column, 1-based).
// Returns false if the input wasn't two numbers.
bool readMove(int& row, int& col) {
    std::cout << "Enter row and column (1-3, e.g. 2 3): ";
    if (!(std::cin >> row >> col)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    --row;  // convert 1-based input to 0-based array indexes
    --col;
    return true;
}

// A move is valid when it's on the board and the cell is still empty.
bool isValidMove(const Board& board, int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }
    return board[indexOf(row, col)] == '.';
}

void placeMove(Board& board, int row, int col, char player) {
    board[indexOf(row, col)] = player;
}

// ---------------------------------------------------------------------------
// TODO 1 — your job
// ---------------------------------------------------------------------------
// Return true if `player` has three in a row: horizontally, vertically,
// or diagonally. Return false otherwise.
//
// Hints:
//   - There are 8 possible winning lines: 3 rows, 3 columns, 2 diagonals.
//   - A row is:  board[indexOf(r, 0)], board[indexOf(r, 1)], board[indexOf(r, 2)]
//   - A column is: board[indexOf(0, c)], board[indexOf(1, c)], board[indexOf(2, c)]
//   - Diagonal:  (0,0) (1,1) (2,2)      Other diagonal: (0,2) (1,1) (2,0)
//   - Careful: an empty cell is '.', so check that the cells equal `player`,
//     not just that they are all equal to each other!
bool hasWon(const Board& board, char player) {
    (void)board;
    (void)player;
    return false;  // TODO: delete this line and write the real check
}

// ---------------------------------------------------------------------------
// TODO 2 — your job
// ---------------------------------------------------------------------------
// Return true when there are no empty cells ('.") left, meaning it's a draw.
// Hints:
//   - Loop over all 9 cells; if you find a '.', it's not full yet.
//   - Or use a range-for: for (char c : board) { ... }
bool isFull(const Board& board) {
    (void)board;
    return false;  // TODO: delete this line and write the real check
}
// ---------------------------------------------------------------------------

int main() {
    Board board;
    board.fill('.');

    char player = 'X';

    while (true) {
        printBoard(board);

        int row = 0;
        int col = 0;
        if (!readMove(row, col)) {
            if (std::cin.eof()) {
                std::cout << "\nInput closed. Bye.\n";
                break;
            }
            std::cout << "Please type two numbers, like: 2 3\n";
            continue;
        }

        if (!isValidMove(board, row, col)) {
            std::cout << "That square is not available. Try again.\n";
            continue;
        }

        placeMove(board, row, col, player);

        if (hasWon(board, player)) {
            printBoard(board);
            std::cout << "Player " << player << " wins!\n";
            break;
        }

        if (isFull(board)) {
            printBoard(board);
            std::cout << "It's a draw.\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';  // swap turns
    }

    std::cout << "Game over.\n";
    return 0;
}
