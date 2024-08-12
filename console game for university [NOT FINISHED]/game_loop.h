#pragma once

#include <pthread.h>

void new_game_play_choose();
void new_game_start();
void main_game_screen();
void shop_menu_screen();


#define MAX_MINER_COUNT		9
#define MAX_ARMY_COUNT		5
#define MAX_UPGRADE_COUNT	6

extern int commander;


extern char* commanders[];

extern char* player_miners[];

extern int player_miners_count[];

extern unsigned int game_miners_price[];

extern char* player_game_upgrades[];

extern float player_game_upgrades_count[];

extern unsigned int game_upgrade_price[];

extern char* player_army[];

extern int player_army_count[];

extern unsigned int game_army_price[];

extern unsigned int earnings;
extern unsigned int player_xp;
extern unsigned int player_money;

extern unsigned int player_crystal;

extern int in_shop;

extern pthread_mutex_t money_mutex;