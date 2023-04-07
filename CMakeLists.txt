cmake_minimum_required(VERSION 3.25)
project(GAG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(GAG main.cpp gag.cpp gag.h)
target_link_libraries(GAG
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

