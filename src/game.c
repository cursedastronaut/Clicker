#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <playground.h>
#include <stdio.h>
#include "game.h"
#include "utils/utils.c"
#include <string.h>
#include "gui/gui.h"
#include "debug/debug.h"
#include "debug/debug.c"
#include "scenes/save.c"
#include "scenes/save.h"
#include "scenes/map.c"
#include "scenes/shop/shop.c"
#include "scenes/shop/shop_npc.c"
#include "scenes/kimchi_box.c"
#include "scenes/menu.c"
#include "scenes/main_menu.c"

void game_init(Game* game)
{
    game->kimchi = 0;
    game->timepassing = 0;
    game->kimchi_per_second = 1;
    game->last_action = 0;
    game->kimchi_thrown = 0;
    game->kimchi_menu = false;
    game->kimchi_offset = 0;
    game->scene = 1; 
    game->is_dialog = 0;
    
}


//Display
void display_game(Game* game)
{
    print_text(0, 48, "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD", 0xC4);



    switch (game->last_action)
    {
    case 1:
        print_text(0, 49,"You have eaten %d kimchi", game->kimchi_eated, game->kimchi_eated > 1 ? "s." : ".");
        break;
    
    case 2:
        print_text(0, 49,"You have thrown %d kimchis. You wasteful.", game->kimchi_thrown);
        break;
    case 51:
        print_text(0, 49,"Shopkeeper: Heya, my comrade!", game->kimchi_thrown);
        break;
    default:
        break;
    }

    switch (game->scene)
    {
    case 0:
        im_print(1, 0 + game->kimchi_offset, "You have %d kimchis", game->kimchi);
        scene0_kimchibox(game);
        break;
    
    case 1:
        scene1_mainmenu(game);
        break;
    
    case 2:
        im_print(1, 0 + game->kimchi_offset, "You have %d kimchis", game->kimchi);
        save_button(game, 1);
        save_button(game, 2);
        save_button(game, 3);
        save_button(game, 4);
        break;
    
    case 3:
        im_print(1, 0 + game->kimchi_offset, "You have %d kimchis", game->kimchi);
        display_map(game);
        break;

    case 4:
        im_print(1, 0 + game->kimchi_offset, "You have %d kimchis", game->kimchi);
        npc_shopkeeper(game);
        break;
    
    case 99:
        im_print(1, 0 + game->kimchi_offset, "You have %d kimchis", game->kimchi);
        scene99_debug(game);
        break;

    default:
        break;
    }
    display_dialog(game, game->currentDialog);


    menu_display(game);
    button_debug(game);

}


void kimchi_increment(Game* game)
{
    game->frameTime = pg_io_get_frame_time();
    if (game->timepassing >= 1 / game->kimchi_per_second)
    {
        im_print(1, 5, "%d", game->timepassing);
        game->timepassing = 0;
        game->kimchi++;
    }
    game->timepassing += game->frameTime;
}









void game_update(Game* game)
{
    if (game->scene != 1)
    {kimchi_increment(game);}
    pg_clear_all();
    display_game(game);
}


void game_shutdown(Game* game)
{

}
