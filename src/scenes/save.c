#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <playground.h>
#include <playground_backend_glfw.h>
#include <stdarg.h>
#include <stdio.h>
#include "../game.h"
void save(Game* game, int index)
{
    char buffer[19];
    sprintf(buffer, "save%d.sav", index);
    FILE* savefile = fopen(buffer, "w");
    fputc(game->kimchi,savefile);
    fputc(game->kimchi_eated,savefile);
    fputc(game->kimchi_menu,savefile);
    fputc(game->kimchi_offset,savefile);
    fputc(game->kimchi_per_second,savefile);
    fputc(game->kimchi_thrown,savefile);
    fputc(game->last_action,savefile);
    fputc(game->scene,savefile);
    fputc(game->timepassing,savefile);

    fclose(savefile);
}

void load(Game* game, int index)
{
    char buffer[19];
    sprintf(buffer, "save%d.sav", index);
    FILE* savefile = fopen(buffer, "r");
    if (savefile == NULL)
    {

    }
    else
    {
        game->kimchi = fgetc(savefile);
        game->kimchi_eated = fgetc(savefile);
        game->kimchi_menu = fgetc(savefile);
        game->kimchi_offset = fgetc(savefile);
        game->kimchi_per_second = fgetc(savefile);
        game->kimchi_thrown = fgetc(savefile);
        game->last_action = fgetc(savefile);
        game->timepassing = fgetc(savefile);
        fclose(savefile);
    }
}





void save_button(Game* game, int index)
{
    if (im_button(1, 8, "Save on slot 1") == true)
    {
        save(game, 1);
    }
    if (im_button(1, 9, "Load slot 1") == true)
    {
        load(game, 1);
    }
    if (im_button(1, 10, "Save on slot 2") == true)
    {
        save(game, 2);
    }
    if (im_button(1, 11, "Load slot 2") == true)
    {
        load(game, 2);
    }
    if (im_button(1, 12, "Save on slot 3") == true)
    {
        save(game, 3);
    }
    if (im_button(1, 13, "Load slot 3") == true)
    {
        load(game, 3);
    }
    if (im_button(1, 14, "Save on slot 4") == true)
    {
        save(game, 4);
    }
    if (im_button(1, 15, "Load slot 4") == true)
    {
        load(game, 4);
    }
}

