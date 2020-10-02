//
// Created by andrea on 27/09/20.
//

#include "curses_interface.h"
#include "user_interface.h"
#include <curses.h>
#include "colors.h"
#include <menu.h>

curses_interface::curses_interface()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    start_color();
    for (int bg = 0; bg<=7; bg++) {
        for (int fg = 0; fg<=7; fg++) {
            init_pair(color_pair_number(fg, bg), color_to_curses(fg), color_to_curses(bg));
        }
    }
    getmaxyx(stdscr, this->height, this->width);
}

void curses_interface::print(const std::string& str, const text_options& options) const
{
    if (options.center) {
        int y = getcury(stdscr);
        move(y, (this->width-str.length())/2);
    }
    if (options.bold)
        attron(A_BOLD);
    attron(COLOR_PAIR(color_pair_number(options.color.foreground, options.color.background)));
    addstr(str.c_str());
    attroff(A_BOLD);
    attroff(COLOR_PAIR(color_pair_number(options.color.foreground, options.color.background)));
}

unsigned int curses_interface::menu(const std::string (& options)[], size_t n) const
{
    int y = getcury(stdscr);
    WINDOW* w = newwin(n+2, this->width-2, y, 1);
    keypad(w, true);
    curs_set(0);
    wrefresh(stdscr);
    box(w, 0, 0);
    for (int i = 0; i<n; ++i) {
        if (i==0)
            wattron(w, A_STANDOUT);
        else
            wattroff(w, A_STANDOUT);
        wrefresh(w);
        mvwprintw(w, i+1, 2, "%s", options[i].c_str());
    }
    wrefresh(w);
    int ch;
    int i = 0;
    while ((ch = wgetch(w))!=KEY_ENTER && ch!='\n') {
        mvwprintw(w, i+1, 2, "%s", options[i].c_str());
        // use a variable to increment or decrement the value based on the input.
        switch (ch) {
        case KEY_UP:
            i--;
            i = (i<0) ? n-1 : i;
            break;
        case KEY_DOWN:
            i++;
            i = (i>n-1) ? 0 : i;
            break;
        }
        // now highlight the next item in the list.
        wattron(w, A_STANDOUT);
        mvwprintw(w, i+1, 2, "%s", options[i].c_str());
        wattroff(w, A_STANDOUT);
    }

    werase(w);
    wrefresh(w);
    delwin(w);
    refresh();
    return i;
}

void curses_interface::pause(bool show_prompt, const text_options& options) const
{
    if (show_prompt)
        this->print("Press a key to continue...", options);
    getch();
}
