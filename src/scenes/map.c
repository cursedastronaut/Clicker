#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <playground.h>
#include <playground_backend_glfw.h>
#include <stdarg.h>
#include <stdio.h>
#include "../game.h"

void btsc_map(Game* game)
{
    if (im_button(10, 2, "The") || im_button(10, 3, "Map"))
    {
        game->scene = 3;
    }
}

void map_moveshop(Game* game)
{
    if (game->scene == 3)
    {
        if (im_button(39, 13, " ") == true || im_button(39, 14, " ") == true )
        {
            game->scene = 4;
        }
    }
    /*else if (game->scene == 4)
    {
        if (im_button(39, 13, " ") == true || im_button(39, 14, " ") == true );
        {
            game->scene == 4
        }
    }*/
}

void display_map(Game* game)
{
    print_text(0, 9, "    __________ ,,");
    print_text(0, 10, "   /\x5C     _   \x5C");
    print_text(0, 11, "  /  \x5C___/^\x5C");
    print_text(0, 12, "  |  | []   [] |");
    print_text(0, 13, "  |  |   .-.   |");
    print_text(0, 14, "  |._|___|||___|");

    print_text(34, 9, "  ____||____");
    print_text(34, 10, " ///////////\x5C");
    print_text(34, 11, "///////////  \x5C");
    print_text(34, 12, "|    _    |  |");
    print_text(34, 13, "|[] | | []|[]|");
    print_text(34, 14, "|   | |   |  |");


    map_moveshop(game);
}    

