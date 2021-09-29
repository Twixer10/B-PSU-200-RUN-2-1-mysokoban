/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-thomas.techer
** File description:
** game_manager
*/

#include "../../include/sokoban.h"

void update_game2(sokoban_t *sokoban)
{
    int x;
    int y;

    while (sokoban->tmp_b < sokoban->height) {
        y = LINES / 2 + sokoban->tmp_b;
        x = COLS / 2;
        if (COLS < sokoban->height || LINES < sokoban->height + 1)
            mvprintw(LINES / 2, x- 20, "Please expand  your terminal !");
        else
            mvprintw(y - sokoban->height / 2, x - sokoban->width / 2,
            sokoban->map[sokoban->tmp_b]);
        sokoban->tmp_b++;
    }
}

void get_direction(int ch, sokoban_t *soko)
{
    soko->tmp_x = 0;
    soko->tmp_y = 0;
    if (ch == KEY_LEFT)
        soko->tmp_x = -1;
    if (ch == KEY_RIGHT)
        soko->tmp_x = 1;
    if (ch == KEY_UP)
        soko->tmp_y = -1;
    if (ch == KEY_DOWN)
        soko->tmp_y = 1;
}

int	check_win(sokoban_t *s)
{
    int i = 0;

    while (i < s->total_area) {
        s->tmp_b = s->area[i++];
        s->tmp_a = s->area[i++];
        if (s->map[s->tmp_b][s->tmp_a] != 'X')
            return (TRUE);
    }
    s->tmp_a = 974;
    s->tmp_b = 974;
    return (FALSE);
}

my_bool update_game(sokoban_t *sokoban)
{
    int ch;

    update_game2(sokoban);
    refresh();
    ch = getch();
    reset_map(ch, sokoban);
    get_direction(ch, sokoban);
    try_update_moov(sokoban);
    if (ch == 113)
        return (FALSE);
    return (check_win(sokoban));
}

void lunch_game(sokoban_t *sokoban)
{
    my_bool i = TRUE;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    raw();
    curs_set(FALSE);
    while (i) {
        clear();
        sokoban->tmp_a = 0;
        sokoban->tmp_b = 0;
        i = update_game(sokoban);
    }
    if (sokoban->tmp_a == 974 && sokoban->tmp_b == 974)
        win_screen();
    endwin();
}