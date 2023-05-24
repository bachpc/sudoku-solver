#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>
#include "SudokuGrid.h"

class MainWindow : public Gtk::Window {
public:
    MainWindow();
    virtual ~MainWindow();

private:
    void onSolveButtonClicked();
    void onResetButtonClicked();

    SudokuGrid grid;
    Gtk::Grid gridContainer;
    Gtk::Button solveButton;
    Gtk::Button resetButton;
    Gtk::Entry cells[9][9];
};

#endif // MAINWINDOW_H
