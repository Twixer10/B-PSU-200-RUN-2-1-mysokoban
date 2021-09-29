/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-thomas.techer
** File description:
** moov_manager
*/

#include "../../include/sokoban.h"

int check_area(sokoban_t *s, int x, int y)
{
    int i = 0;

    while (i < s->total_area) {
        if (y == s->area[i] && x == s->area[i + 1])
            return (1);
        i = i + 2;
    }
    return (0);
}

int is_empty(sokoban_t *s, int x, int y)
{
    if (s->map[y][x] == ' ')
        return (1);
    if (s->map[y][x] == 'O')
        return (2);
    if (s->map[y][x] == 'X')
        return (-1);
    if (s->map[y][x] == 'x')
        return (-2);
    return (0);
}

void update_moov(sokoban_t *s)
{
    if (is_empty(s, s->player_x + s->tmp_x, s->player_y + s->tmp_y) > 0) {
        if (check_area(s, s->player_y, s->player_x) == 1)
            s->map[s->player_y][s->player_x] = 'O';
        else
            s->map[s->player_y][s->player_x] = ' ';
        s->player_y += s->tmp_y;
        s->player_x += s->tmp_x;
        s->map[s->player_y][s->player_x] = 'P';
    }
}

void try_update_moov(sokoban_t *s)
{
    if (is_empty(s, s->player_x + s->tmp_x, s->player_y + s->tmp_y) < 0) {
        if (is_empty(s, s->player_x + s->tmp_x * 2,
        s->player_y + s->tmp_y * 2) > 0) {
            if (check_area(s, s->player_x, s->player_y) == 1)
                s->map[s->player_y][s->player_x] = 'O';
            else
                s->map[s->player_y][s->player_x] = ' ';
            s->player_y += s->tmp_y;
            s->player_x += s->tmp_x;
            s->map[s->player_y][s->player_x] = 'P';
            s->map[s->player_y + s->tmp_y][s->player_x + s->tmp_x] = 'X';
        }
    }
    update_moov(s);
}