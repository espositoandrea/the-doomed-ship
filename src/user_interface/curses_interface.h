//
// Created by andrea on 27/09/20.
//

#ifndef SHIP_CURSES_INTERFACE_H
#define SHIP_CURSES_INTERFACE_H

#include "user_interface.h"

class curses_interface : public user_interface {
public:
    curses_interface();

    void pause(bool show_prompt, const text_options& options) const override;

    void print(const std::string& str, const text_options& options) const override;

    unsigned int menu(const std::string (& options)[], size_t n) const override;

private:
    unsigned int height;
    unsigned int width;
};

#endif //SHIP_CURSES_INTERFACE_H

