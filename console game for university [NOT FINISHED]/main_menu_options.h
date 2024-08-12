#pragma once

extern char* game_colors_string[];
extern int game_current_color;
extern int game_general;
extern float game_speed;


void game_menu_welcome();
void game_menu_how_to_play();
void menu_options();
void menu_options_game_color();
void change_color();
void menu_options_game_speed();