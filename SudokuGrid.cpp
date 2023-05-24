#include "SudokuGrid.h"

SudokuGrid::SudokuGrid() {
    // Initialize the grid with zeros
    grid.resize(9, std::vector<int>(9, 0));
}

void SudokuGrid::loadPuzzle(const std::string& puzzle) {
    // Load the puzzle into the grid
    for (int i = 0; i < 81; ++i) {
        int row = i / 9;
        int col = i % 9;
        grid[row][col] = puzzle[i] - '0';
    }
}

bool SudokuGrid::solve() {
    int row, col;
    if (!findEmptyCell(row, col)) {
        // All cells are filled, puzzle solved
        return true;
    }

    for (int num = 1; num <= 9; ++num) {
        if (isValidPlacement(row, col, num)) {
            grid[row][col] = num;

            if (solve()) {
                // Found a solution
                return true;
            }

            // Backtrack and try the next number
            grid[row][col] = 0;
        }
    }

    // No solution found
    return false;
}

bool SudokuGrid::isSolved() const {
    // Check if the puzzle is solved
    for (const auto& row : grid) {
        for (int cell : row) {
            if (cell == 0) {
                return false;
            }
        }
    }
    return true;
}

int SudokuGrid::getCellValue(int row, int col) const {
    // Get the value of a cell
    return grid[row][col];
}

bool SudokuGrid::isValidPlacement(int row, int col, int num) const {
    // Check if the placement of num at (row, col) is valid

    // Check row
    for (int c = 0; c < 9; ++c) {
        if (grid[row][c] == num) {
            return false;
        }
    }

    // Check column
    for (int r = 0; r < 9; ++r) {
        if (grid[r][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int r = startRow; r < startRow + 3; ++r) {
        for (int c = startCol; c < startCol + 3; ++c) {
            if (grid[r][c] == num) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuGrid::findEmptyCell(int& row, int& col) const {
    // Find the next empty cell in the grid
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}
