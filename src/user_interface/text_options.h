//
// Created by andrea on 27/09/20.
//

#ifndef SHIP_TEXT_OPTIONS_H
#define SHIP_TEXT_OPTIONS_H

#include "colors.h"

struct text_options {
    bool center = false;
    bool bold = false;

    struct {
        colors foreground = colors::WHITE;
        colors background = colors::BLACK;
    } color;
};

#endif //SHIP_TEXT_OPTIONS_H
