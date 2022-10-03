#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <playground.h>
#include <playground_backend_glfw.h>
#include <stdarg.h>
#include <stdio.h>
#include "../utils/dialog.c"
#include "../game.h"

void scene1_mainmenu(Game* game)
{
    im_print(4,0, "Kimchi clicker ig... nothing works anyway.");
    if (im_button(20,3, "New Game"))
    {
        game->scene = 0;
    }
    print_text(0, 5, "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD", 0xC4);



    im_print(23 ,7, "Load");
    if (im_button(5,9, "Load slot 1"))
    {
        int temp = load(game, 1);
        if (temp == 1)
        {
            im_print(0,49, "Failed.");
        }
        else
        {
            game->scene = 0;
        }
    }

    if (im_button(34, 9, "Load slot 2"))
    {
        game->scene = 0;
        load(game, 2);
    }

    if (im_button(5, 11, "Load slot 3"))
    {
        game->scene = 0;
        load(game, 3);
    }

    if (im_button(34, 11, "Load slot 4"))
    {
        game->scene = 0;
        load(game, 4);
    }
    
}