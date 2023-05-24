cmake_minimum_required(VERSION 3.5)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM3 REQUIRED gtkmm-3.0)

set(SOURCES
    main.cpp
    SudokuGrid.cpp
    MainWindow.cpp
)

set(HEADERS
    SudokuGrid.h
    MainWindow.h
)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

include_directories(${GTKMM3_INCLUDE_DIRS})
link_directories(${GTKMM3_LIBRARY_DIRS})
link_libraries(${GTKMM3_LIBRARIES})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} ${GTKMM3_LIBRARIES})
