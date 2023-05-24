# Yet Another Sudoku Solver

The Sudoku Solver is a C++ application that allows you to solve Sudoku puzzles using a graphical user interface. It employs an efficient solving algorithm to find the solution to the given puzzle.

## Features

- Graphical user interface (GUI) for entering and displaying Sudoku puzzles
- Fast solving algorithm to find the solution
- Supports 9x9 Sudoku grids
- Easy-to-use interface with clear instructions

## Requirements

- C++ compiler with C++11 support
- GTK+ 3 library

```bash
sudo apt-get install libgtk3.0-dev
sudo apt-get install libgtkmm-3.0-dev
```

## Getting Started

1. Clone the repository:

   ```bash
   git clone https://github.com/bachpc/sudoku-solver.git
   ```

2. Navigate to the project directory:

    ```bash
    cd sudoku-solver
    ```

3. Compile the project using CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

4. Run the Sudoku Solver:

    ```bash
    ./SudokuSolver
    ```

## Usage

- Launch the Sudoku Solver application.
- Enter the numbers of the Sudoku puzzle into the cells of the grid.
- Click the "Solve" button to find the solution.
- If a solution exists, the solved puzzle will be displayed.
- If no solution is found, a message will indicate that the puzzle is unsolvable.
