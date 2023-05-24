#include "MainWindow.h"

int main(int argc, char* argv[]) {
    Gtk::Main kit(argc, argv);
    MainWindow mainWindow;
    Gtk::Main::run(mainWindow);
    return 0;
}
