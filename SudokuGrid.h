#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <vector>
#include <string>

class SudokuGrid {
public:
    SudokuGrid();

    void loadPuzzle(const std::string& puzzle);
    bool solve();
    bool isSolved() const;
    int getCellValue(int row, int col) const;

private:
    bool isValidPlacement(int row, int col, int num) const;
    bool findEmptyCell(int& row, int& col) const;

    std::vector<std::vector<int>> grid;
};

#endif // SUDOKUGRID_H
