#include "MainWindow.h"

MainWindow::MainWindow() {
    set_default_size(400, 400);
    set_title("Sudoku Solver");

    // Create the Sudoku grid
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[row][col].set_max_length(1);
            cells[row][col].set_width_chars(2);

            if (row % 3 == 0)
                cells[row][col].set_margin_top(3);
            if (col % 3 == 0)
                cells[row][col].set_margin_left(3);
                
            gridContainer.attach(cells[row][col], col, row, 1, 1);
        }
    }

    solveButton.set_label("Solve");
    solveButton.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onSolveButtonClicked));
    gridContainer.attach(solveButton, 0, 9, 9, 1);

    resetButton.set_label("Reset");
    resetButton.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onResetButtonClicked));
    gridContainer.attach(resetButton, 0, 10, 9, 1);

    add(gridContainer);
    show_all_children();
}

MainWindow::~MainWindow() {}

void MainWindow::onSolveButtonClicked() {
    std::string puzzle;

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (cells[row][col].get_text().size() < 1 || cells[row][col].get_text()[0] < '0' || cells[row][col].get_text()[0] > '9')
                puzzle += "0";
            else
                puzzle += cells[row][col].get_text();
        }
    }

    grid.loadPuzzle(puzzle);
    grid.solve();

    if (grid.isSolved()) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                cells[row][col].set_text(std::to_string(grid.getCellValue(row, col)));
            }
        }
    } else {
        Gtk::MessageDialog dialog(*this, "No solution found for the puzzle.");
        dialog.run();
    }
}

void MainWindow::onResetButtonClicked() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[row][col].set_text("");
        }
    }
}
