//
// Created by andrea on 27/09/20.
//

#include "colors.h"
#include <curses.h>
#include <stdexcept>

short color_pair_number(colors foreground, colors background)
{
    return color_pair_number(static_cast<unsigned short>(foreground), static_cast<unsigned short>(background));
}

short color_pair_number(unsigned short foreground, unsigned short background)
{
    short first_bit = 1u << 7u;
    short bbb = (7u & background) << 4u;
    short ffff = 7u & foreground;

    return (first_bit | bbb | ffff);
}

short color_to_curses(colors color)
{
    return color_to_curses(static_cast<unsigned short>(color));
}

short color_to_curses(unsigned short color)
{
    switch (7u & color) {
    case 0:
        return COLOR_BLACK;
    case 1:
        return COLOR_BLUE;
    case 2:
        return COLOR_GREEN;
    case 3:
        return COLOR_CYAN;
    case 4:
        return COLOR_RED;
    case 5:
        return COLOR_MAGENTA;
    case 6:
        return COLOR_YELLOW;
    case 7:
        return COLOR_WHITE;
    default:
        throw std::invalid_argument("The color must be in the range [0, 7]");
    }
}
