#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>

#include "main_menu_options.h"


#define MAX_MINER_COUNT		9
#define MAX_ARMY_COUNT		5
#define MAX_UPGRADE_COUNT	6

int commander;


char* commanders[] = { "Combat Veteran", "Medic", "Banker" };

char* player_miners[] = { "Coal Miners", "Gold Miners", "Silver Miners", "Copper Miners", "Diamonds Miner", "Iron Ore Miners",
						"Salt Miners", "Uranium Miners", "Oil and Gas Miners"};

int player_miners_count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};

unsigned int game_miners_price[] = { 50, 200, 350, 700, 1900, 2500, 5000, 11000, 20000};

unsigned int game_miner_earning_money[] = { 2, 6, 10, 15, 25, 45, 70, 100, 250 };
unsigned int game_miner_earning_xp[] = { 1, 1, 1, 2, 2, 5, 10, 25, 40 };

char* player_game_upgrades[] = { "Miners Speed", "Miners Income", "Miners Health", "Army Speed", "Army Health", "Army Strenght" };

float player_game_upgrades_count[6] = { 0, 0, 0, 0, 0, 0 };

unsigned int game_upgrade_price[] = { 1000, 2000, 3000, 4000, 5000, 6000 };

char* player_army[] = { "Miner Militia", "Archers", "Healers", "Warrios", "Tankers" };

int player_army_count[] = { 0, 0, 0, 0, 0, 0 };

unsigned int game_army_price[] = { 25, 125, 500, 1440, 3200 };

#define STARTING_MONEY		1000


unsigned int player_crystal = 0;
unsigned long long earnings_xp = 0;
unsigned int player_xp = 0;
unsigned int player_money = STARTING_MONEY;
unsigned long long game_time = 0;
unsigned long long earnings_money = 0;


void new_game_play_choose();
void new_game_start();
void* main_game_screen();
void shop_menu_screen();
void* earning_money_loop();


pthread_mutex_t money_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t screen_mutex = PTHREAD_MUTEX_INITIALIZER;

int in_shop = 0;


void new_game_play_choose() {
	system("cls");
	printf("\n\n%61s", "MINER WAR");
	printf("\n\n\t\t\tChoose your captain of the castle!");
	printf("\n\n\t\t\t\t[1] Combat Veteran");
	printf("\n\t\t\t\t\t* Increases the strenght of the warriors by 5%%");
	printf("\n\n\t\t\t\t[2] Medic");
	printf("\n\t\t\t\t\t* Increases the heal of all the units by 15%%");
	printf("\n\n\t\t\t\t[3] Banker");
	printf("\n\t\t\t\t\t* Increases the income of all the miners by 3%%");
	HANDLE hStdin;
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;

	int running = 1;

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	// Set console mode to accept keyboard input
	SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);
		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown) {
			if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '1') {
				commander = 1;
				player_game_upgrades_count[5] += 5.00;
				new_game_start();
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '2') {
				commander = 2;
				player_game_upgrades_count[2] += 15.00;
				player_game_upgrades_count[4] += 15.00;
				new_game_start();
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '3') {
				commander = 3;
				player_game_upgrades_count[1] += 3.00;
				new_game_start();
			}
		}
	}
}


void new_game_start() {
	pthread_t tid;
	pthread_t tid2;
	pthread_create(&tid, NULL, earning_money_loop, NULL);
	pthread_create(&tid2, NULL, main_game_screen, NULL);

	HANDLE hStdin;
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);
		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown) {
			if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'S' || irInputRecord.Event.KeyEvent.uChar.AsciiChar == 's') {
				pthread_mutex_lock(&screen_mutex);
				shop_menu_screen();
				pthread_mutex_unlock(&screen_mutex);
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'O' || irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'o') {
				pthread_mutex_lock(&screen_mutex);
				menu_options();
				pthread_mutex_unlock(&screen_mutex);
			}
		}
	}
	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);
}



void* main_game_screen() {
	while (1) {
		pthread_mutex_lock(&screen_mutex);
		system("cls");
		printf("\n\n\t\t\t%40s", "MINER WAR");
		printf("\n\t___________________________________________________________________________________________________________");
		printf("\n\t\t|%10s%16s%-21s%-6s%-10s%-17s|", "WORKSHOP", "|COUNT", "| ARMY", "|COUNT", "| UPGRADES", " ");
		printf("\n\t-----------------------------------------------------------------------------------------------------------");
		for (int i = 0; i < MAX_MINER_COUNT || i < MAX_ARMY_COUNT || i < MAX_UPGRADE_COUNT; i++) {
			printf("\n\t\t");
			// Print miner information
			if (i < MAX_MINER_COUNT) {
				if (player_miners_count[i])
					printf("| %-18s | %-3d", player_miners[i], player_miners_count[i]);
				else
					printf("| %-18s |    ", " ");
			}
			else {
				printf("| %-25s", " ");
			}
			// Print army information
			if (i < MAX_ARMY_COUNT) {
				if (player_army_count[i])
					printf(" | %-18s | %-3d", player_army[i], player_army_count[i]);
				else
					printf(" | %-18s |    ", " ");
			}
			else {
				printf(" | %-18s |    ", " ");
			}
			// Print upgrade information
			if (i < MAX_UPGRADE_COUNT) {
				printf(" | %-18s %5.2f%%|", player_game_upgrades[i], player_game_upgrades_count[i]);
			}
			else {
				printf(" | %-18s       |", " ");
			}
		}
		printf("\n\t-----------------------------------------------------------------------------------------------------------");
		printf("\n\t\tMoney Balance: %d $", player_money);
		printf("\n\t\tMoney Earning: %d $ / sec", earnings_money);
		printf("\n\t\tCrystal Balance: %d <o>", player_crystal);
		printf("\n\t\tXP Balance: %d", player_xp);
		printf("\n\t\tXP Earning: %d Xp / sec", earnings_xp);
		printf("\n\t-----------------------------------------------------------------------------------------------------------");
		printf("\n\t\tS - Shop\t\tA - Attack\t\tZ - Achievements\t\tO - Game Options");
		printf("\n\t-----------------------------------------------------------------------------------------------------------");
		pthread_mutex_unlock(&screen_mutex);
		Sleep(1250);
	}
	return NULL;
}


void* earning_money_loop() {
	while (1) {
		earnings_money = 0;
		earnings_xp = 0;
		pthread_mutex_lock(&money_mutex);
		for (int i = 0; i < MAX_MINER_COUNT; i++) {
			player_money += game_miner_earning_money[i] * player_miners_count[i];
			player_xp += game_miner_earning_xp[i] * player_miners_count[i];
		}
		pthread_mutex_unlock(&money_mutex);
		for (int i = 0; i < MAX_MINER_COUNT; i++) {
			earnings_money += game_miner_earning_money[i] * player_miners_count[i];
			earnings_xp += game_miner_earning_xp[i] * player_miners_count[i];
		}
		Sleep(1250 / game_speed);
	}
	return NULL;
}