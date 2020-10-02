#include "config.h"
#include "game_controller.h"

int main()
{
    const auto controller = game_controller();
    controller.show_main_menu();
    return 0;
}
