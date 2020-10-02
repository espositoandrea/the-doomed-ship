//
//
// Created by andrea on 27/09/20.

#include "user_interface.h"
#include <curses.h>
#include "colors.h"
#include <menu.h>

user_interface::user_interface() = default;


user_interface::~user_interface()
{
    endwin();
}

