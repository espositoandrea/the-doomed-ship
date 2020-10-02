cmake_minimum_required(VERSION 3.10)

project(ship VERSION 0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmenu -lncurses")

set(CURSES_NEED_NCURSES True)
find_package(Curses REQUIRED)
find_library(MENU_LIBRARY menu)
include_directories(${CURSES_INCLUDE_DIR})

configure_file(src/config.h.in config.h)

add_executable(ship src/main.cpp src/user_interface/colors.cpp src/user_interface/user_interface.cpp src/game_controller.cpp src/user_interface/curses_interface.cpp src/user_interface/curses_interface.h)

target_include_directories(ship PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(ship ${CURSES_LIBRARIES} ${MENU_LIBRARY})
