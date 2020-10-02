//
// Created by andrea on 27/09/20.
//

#include "game_controller.h"
#include "user_interface/curses_interface.h"

game_controller::game_controller()
        :ui(new curses_interface()) { };

game_controller::game_controller(const user_interface& ui)
        :
        ui(&ui)
{
}

void game_controller::show_main_menu() const
{
    ui->print(
            "The Doomed Ship: an Adventure\n",
            {
                    .center=true,
                    .bold=true,
                    .color={
                            .foreground=colors::RED,
                            .background=colors::BLACK
                    }
            }
    );
    ui->print("By Andrea Esposito\n", {.center=true});
    ui->print("Based on the game \"L'Astronave Condannata\"\n", {.center=true});

    switch (ui->menu({"Play", "Credits and license", "Exit"}, 3)) {
    case 0:
        // Start the game
        break;
    case 1:
        // Print credits
        this->show_credits();
        this->ui->pause(true);
        break;
    default:
        // Exit game
        break;
    }
}

game_controller::~game_controller()
{
    delete this->ui;
}

void game_controller::show_credits() const
{
    this->ui->print("CIAONE\n");
}
