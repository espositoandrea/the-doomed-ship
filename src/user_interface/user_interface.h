//
// Created by andrea on 27/09/20.
//

#ifndef SHIP_USER_INTERFACE_H
#define SHIP_USER_INTERFACE_H

#include "text_options.h"
#include <string>

class user_interface {
public:
    user_interface();

    ~user_interface();

    virtual void pause(bool show_prompt = false, const text_options& options = {}) const = 0;

    virtual void print(const std::string& str, const text_options& options = {}) const = 0;

    virtual unsigned menu(const std::string (& options)[], size_t n) const = 0;
};

#endif //SHIP_USER_INTERFACE_H
