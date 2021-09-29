/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-thomas.techer
** File description:
** win
*/

#include "../../include/sokoban.h"

void win_screen(void)
{
    int ch = 0;
    int x = COLS / 2;
    int y = LINES / 2;

    clear();
    while (ch != 113) {
        mvprintw(y - 3, x - 13.5, "- - --- YOU WIN ! --- - -");
        mvprintw(y + 3, x - 8.5, "Press 'q' to quit");
        ch = getch();
        clear();
        refresh();
    }
}
