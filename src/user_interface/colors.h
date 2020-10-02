//
// Created by andrea on 27/09/20.
//

#ifndef SHIP_COLORS_H
#define SHIP_COLORS_H

enum class colors : unsigned short {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
};

short color_pair_number(colors foreground, colors background);

short color_pair_number(unsigned short foreground, unsigned short background);

short color_to_curses(colors color);

short color_to_curses(unsigned short color);

#endif //SHIP_COLORS_H
