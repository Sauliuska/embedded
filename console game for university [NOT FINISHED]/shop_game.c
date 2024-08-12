#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#include "main_menu_options.h"
#include "game_loop.h"


void shop_menu_window() {

}



void shop_menu_screen() {
	int screen = 1;
	HANDLE hStdin;
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	// Set console mode to accept keyboard input
	SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT);
	in_shop = 1;
	while (in_shop) {
		system("cls");
		printf("\n\n%61s", "MINER WAR");
		printf("\n\n%58s", "SHOP");
		if (screen == 1) {
			for (int i = 0; i < MAX_MINER_COUNT; i++) {
				printf("\n\n\t\t\t\t[%d]. %-30s %d$", i + 1, player_miners[i], game_miners_price[i]);
			}
			printf("\n\n\n%61s", "< Miners >");
		}
		else if (screen == 2) {
			for (int i = 0; i < MAX_ARMY_COUNT; i++) {
				printf("\n\n\t\t\t\t[%d]. %-30s %d$", i + 1, player_army[i], game_army_price[i]);
			}
			printf("\n\n\n%61s", "< Army >");
		}
		else if (screen == 3) {
			for (int i = 0; i < MAX_UPGRADE_COUNT; i++) {
				printf("\n\n\t\t\t\t[%d]. %-30s %d <o>", i + 1, player_game_upgrades[i], game_upgrade_price[i]);
			}
			printf("\n\n\n%61s", "< Upgrade >");
		}
		printf("\n\t-----------------------------------------------------------------------------------------------------------");
		printf("\n\t\tMoney: %d\t\t\t\tXp: %d\t\t\tCrystals: %d <o>", player_money, player_xp, player_crystal);
		printf("\n\t-----------------------------------------------------------------------------------------------------------");
		printf("\n\t\tQ - Back\t\tA - Attack\t\tZ - Achievements\t\tO - Game Options");
		printf("\n\t-----------------------------------------------------------------------------------------------------------");

		char user_input_char;
		unsigned int user_input = 0;
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);
		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown){
			if (isdigit(irInputRecord.Event.KeyEvent.uChar.AsciiChar))
			{
				user_input_char = irInputRecord.Event.KeyEvent.uChar.AsciiChar;
				user_input = user_input_char - '0';
			}
			if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) {
				if (screen == 3) screen = 1;
				else screen++;
			}
			else if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT) {
				if (screen == 1) screen = 3;
				else screen--;
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'Q' || irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'q') {
				in_shop = 0;
				return;
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'O' || irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'o') {
				menu_options();
			}
			else if (user_input >= 1 && user_input <= MAX_MINER_COUNT) {
				switch (screen) {
				case 1:
					if (user_input <= MAX_MINER_COUNT && game_miners_price[user_input - 1] <= player_money) {
						pthread_mutex_lock(&money_mutex);
						player_money -= game_miners_price[user_input - 1];
						player_miners_count[user_input - 1]++;
						pthread_mutex_unlock(&money_mutex);
						printf("\n\n\t\t\t\t[SYSTEM] BOUGHT a %s!", player_miners[user_input - 1]);
					}
					else if (user_input <= MAX_MINER_COUNT){
						printf("\n\n\t\t\t\t[SYSTEM] NOT ENOUGH MONEY TO BUY a %s!", player_miners[user_input - 1]);
					}
					Sleep(333);
					break;
				case 2:
					if (user_input <= MAX_ARMY_COUNT && game_army_price[user_input - 1] <= player_money) {
						pthread_mutex_lock(&money_mutex);
						player_money -= game_army_price[user_input - 1];
						player_army_count[user_input - 1]++;
						printf("\n\n\t\t\t\t[SYSTEM] BOUGHT a %s!", player_army[user_input - 1]);
						pthread_mutex_unlock(&money_mutex);
					}
					else if (user_input <= MAX_ARMY_COUNT){
						printf("\n\n\t\t\t\t[SYSTEM] NOT ENOUGH MONEY TO BUY a %s!", player_army[user_input - 1]);
					}
					Sleep(333);
					break;
				case 3:
					if (user_input <= MAX_UPGRADE_COUNT && game_upgrade_price[user_input - 1] <= player_crystal) {
						player_crystal -= game_upgrade_price[user_input - 1];
						player_game_upgrades_count[user_input - 1]++;
						printf("\n\n\t\t\t\t[SYSTEM] BOUGHT a %s!", player_game_upgrades[user_input - 1]);
					}
					else if(user_input <= MAX_UPGRADE_COUNT){
						printf("\n\n\t\t\t\t[SYSTEM] NOT ENOUGH CRYSTALS TO BUY a %s!", player_game_upgrades[user_input - 1]);
					}
					Sleep(400);
					break;
				}
			}
		}
	}
}