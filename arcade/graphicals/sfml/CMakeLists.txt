cmake_minimum_required (VERSION 3.11)
project (ArcadeNCurses)

set(NCURSES_SRC Main.cpp)

add_library(_ncurses SHARED ${NCURSES_SRC})