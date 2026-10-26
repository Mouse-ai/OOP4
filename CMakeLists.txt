cmake_minimum_required(VERSION 4.2)
project(OOP4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(OOP4 main.cpp
        Shape.cpp
        Shape.h
        Ccircle.cpp
        Ccircle.h
        ShapeStorage.cpp
        ShapeStorage.h
        MainWindow.cpp
        MainWindow.h
        CRectangle.cpp
        CRectangle.h
        CSquare.cpp
        CSquare.h)
target_link_libraries(OOP4
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

