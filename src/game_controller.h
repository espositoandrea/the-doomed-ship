//
// Created by andrea on 27/09/20.
//

#ifndef SHIP_GAME_CONTROLLER_H
#define SHIP_GAME_CONTROLLER_H

#include "user_interface/user_interface.h"

class game_controller {
public:
    game_controller();
    explicit game_controller(const user_interface& ui);
    ~game_controller();

    void show_main_menu() const;
    void show_credits() const;

private:
    const user_interface* ui;
};

#endif //SHIP_GAME_CONTROLLER_H
