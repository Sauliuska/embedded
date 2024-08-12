#include <windows.h>
#include <stdlib.h>
#include <stdio.h>


void game_menu_welcome();
void game_menu_how_to_play();
void menu_options();
void menu_options_game_color();
void change_color();
void menu_options_game_speed();


char* game_colors_string[] = { "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White", "Light Blue", "Light Green", "Light Aqua", "Light Red",
								"Light Purple", "Light Yellow" };
int game_current_color = 6;
int game_general = 0;
float game_speed = 1;


#define MAX_COLOR_SIZE	13
#define MAX_GAME_SPEED	5.
#define MIN_GAME_SPEED	1.

void game_menu_welcome() {
	system("cls");
	printf("\n\n%61s", "MINER WAR");
	printf("\n\n\n\t\t\t\t\t\t[1] Play new game");
	printf("\n\n\t\t\t\t\t\t[2] Play load game");
	printf("\n\n\t\t\t\t\t\t[3] Options");
	printf("\n\n\t\t\t\t\t\t[4] How to play");
	printf("\n\n\t\t\t\t\t\t[Q] Quit");
}


void game_menu_how_to_play() {

	HANDLE hStdin;
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT);

	system("cls");
	printf("\n\n\t\tMINER WAR");
	printf("\n\n\tIn this game are 3 types of general miners which are the commanders of the all community of miners who's are fighting the");
	printf("\n\tother miners teams. To win this game you need to survive to the last!");
	printf("\n\n\tPress Q to quit");
	while (1) {
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);
		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown) {
			if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'Q' || irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'q') {
				return;
			}
		}
	}
}


void menu_options() {
	HANDLE hStdin;
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT);
	while (1) {

		system("cls");
		printf("\n\n%61s", "MINER WAR");
		printf("\n\n\n\t\t\t\t\t\t [1] Game color");
		printf("\n\n\t\t\t\t\t\t [2] Game speed");
		printf("\n\n\t\t\t\t\t\t [Q] Back");
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);
		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown) {
			if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '1') {
				menu_options_game_color();
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '2') {
				menu_options_game_speed();
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'Q' || irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'q') {
				return;
			}
		}
	}

}


void menu_options_game_color() {
	HANDLE hStdin;
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT);

	while (1) {
		system("cls");
		printf("\n\n%61s", "MINER WAR");
		printf("\n\n\n\t\t\t\t\t\t <- %s ->", game_colors_string[game_current_color]);
		printf("\n\n\t\t\t\t\t\t [Q] Back");
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);
		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown) {
			if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT) {
				if (game_current_color == 0) {
					game_current_color = MAX_COLOR_SIZE - 1;
				}
				else {
					game_current_color--;
				}
			}
			else if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) {
				if (game_current_color == MAX_COLOR_SIZE - 1) {
					game_current_color = 0;
				}
				else {
					game_current_color++;
				}
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'Q' || irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'q') {
				return;
			}
		}
		change_color();
	}
}


void change_color() {
	if (game_current_color == 0) system("color 1");
	else if (game_current_color == 1) system("color 2");
	else if (game_current_color == 2) system("color 3");
	else if (game_current_color == 3) system("color 4");
	else if (game_current_color == 4) system("color 5");
	else if (game_current_color == 5) system("color 6");
	else if (game_current_color == 6) system("color 7");
	else if (game_current_color == 7) system("color 9");
	else if (game_current_color == 8) system("color A");
	else if (game_current_color == 9) system("color B");
	else if (game_current_color == 10) system("color C");
	else if (game_current_color == 11) system("color D");
	else if (game_current_color == 12) system("color E");
}


void menu_options_game_speed(){

	HANDLE hStdin;
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT);

	while (1) {
		system("cls");
		printf("\n\n%61s", "MINER WAR");
		printf("\n\n\n\t\t\t\t\t\t  <- %.2f ->", game_speed);
		printf("\n\n\t\t\t\t\t\t [Q] Back");
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);
		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown) {
			if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT) {
				if (game_speed <= (float)MIN_GAME_SPEED) {
					game_speed = MAX_GAME_SPEED;
				}
				else {
					game_speed -= 0.10;
				}
			}
			else if (irInputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) {
				if (game_speed >= (float)MAX_GAME_SPEED) {
					game_speed = MIN_GAME_SPEED;
				}
				else {
					game_speed += 0.10;
				}
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'Q' || irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'q') {
				return;
			}
		}
	}
}