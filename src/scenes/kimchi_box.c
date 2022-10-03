#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <playground.h>
#include <playground_backend_glfw.h>
#include <stdarg.h>
#include <stdio.h>
#include "../game.h"

//Buttons
void button_eatkimchis(Game* game)
{
    if (im_button(1, 2 + game->kimchi_offset, "Eat all the kimchis") == true)
    {
        game->kimchi_eated += game->kimchi;
        game->kimchi = 0;
        game->last_action = 1;
    }
}


void button_throwkimchis(Game* game)
{
    if (im_button(1, 4 + game->kimchi_offset, "Throw 10 kimchis.") == true)
    {
        game->kimchi_thrown += 10;
        game->kimchi -= 10;
        game->last_action = 2;
    }
}

void button_enablemenu(Game* game)
{
    if (im_button(1, 6 + game->kimchi_offset, "Bribe the dev' with 30 kimchis for a new feature.") == true && game->kimchi_menu < 3)
    {
        game->kimchi -= 30;
        game->last_action = 3;
        game->kimchi_menu += 1;
        game->kimchi_offset = 6;
    }
}


void scene0_kimchibox(Game* game)
{
    switch (game->kimchi)
        {
        case 1 ... 9:
            button_eatkimchis(game);
            break;
        
        case 10 ... 29:
            button_eatkimchis(game);
            button_throwkimchis(game);
            break;

        case 30 ... 100000000:
            button_eatkimchis(game);
            button_throwkimchis(game);
            button_enablemenu(game);
            break;

        default:
            break;
        }
}
