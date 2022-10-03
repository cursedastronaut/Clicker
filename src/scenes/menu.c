#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <playground.h>
#include <playground_backend_glfw.h>
#include <stdarg.h>
#include <stdio.h>
#include "../game.h"

//Scene
//Buttons
void btsc_kimchi(Game* game)
{
    if (im_button(3, 2, "Kimchi") == true || im_button(3, 3, "Fridge") == true)
    {
        game->scene = 0;
    }
}

void btsc_save(Game* game)
{
    if (im_button(35, 2, "Save") == true || im_button(35, 3, "Menu") == true)
    {
        game->scene = 2;
    }
}

void button_debug(Game* game)
{
    if (game->scene != 99)
    {
        if (im_button(41, 2, "Debug'") == true || im_button(41, 3, " Menu ") == true)
        {
            game->scene = 99;
        }
    }
    else 
    {
        if (im_button(41, 2, "Debug'") == true || im_button(41, 3, " Menu ") == true)
        {
            game->scene = 0;
        }
    }
}

void menu_display(Game* game)
{
    if (game->kimchi_menu >= 1)
        {
            im_print(0, 0, "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            im_print(0, 1, "\xBA                                                \xBA");
            im_print(0, 2, "\xBA                                                \xBA");
            im_print(0, 3, "\xBA                                                \xBA");
            im_print(0, 4, "\xBA                                                \xBA");
            im_print(0, 5, "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            btsc_kimchi(game);
            btsc_save(game);
            switch (game->kimchi_menu)
            {
            case 2:
                btsc_map(game);
                break;
            
            case 3:
                btsc_map(game);
                //btsc_minigame(game);
                break;

            default:
                break;
            }
        }
}