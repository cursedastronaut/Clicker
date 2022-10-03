#pragma once

// Game data
typedef struct Game
{
    int kimchi;
    float timepassing;
    float frameTime;
    float kimchi_per_second;
    int last_action;
    int kimchi_eated;
    int kimchi_thrown;
    int kimchi_menu;



    int kimchi_offset;


    int scene;
    int is_dialog;
    int currentDialog;

} Game;

void game_init(Game* game);
void game_update(Game* game);
void game_shutdown(Game* game);
