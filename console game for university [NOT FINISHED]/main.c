#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>


#include "main_menu_options.h"
#include "system.h"
#include "game_loop.h"


int main(void) {

	hide_console_cursor();

	HANDLE hStdin;
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;

	int running = 1;

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	// Set console mode to accept keyboard input
	SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT);

	do {
		game_menu_welcome();
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);
		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown) {
			if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '1') {
				new_game_play_choose();
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '2') {

			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '3') {
				menu_options();
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == '4') {
				game_menu_how_to_play();
			}
			else if (irInputRecord.Event.KeyEvent.uChar.AsciiChar == 'Q') {
				break;
			}
		}
	} while (1);

	printf("\n\tYou successfully quited the game!");
	return 0;
}