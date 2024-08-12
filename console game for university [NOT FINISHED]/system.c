#include <windows.h>


void hide_console_cursor() {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hStdout, &cursorInfo);
    cursorInfo.bVisible = FALSE; // paslepiam cursoriu
    SetConsoleCursorInfo(hStdout, &cursorInfo);
}