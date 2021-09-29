/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-thomas.techer
** File description:
** map_manager
*/

#include "../../include/sokoban.h"

void reset_map_option(sokoban_t *sokoban)
{
    sokoban->tmp_b = 0;
    while (sokoban->tmp_b < sokoban->height)
    {
        free(sokoban->map[sokoban->tmp_b]);
        sokoban->tmp_b++;
    }
    free(sokoban->map);
}

void reset_map(int ch, sokoban_t *sokoban)
{
    if (ch == 32) {
        reset_map_option(sokoban);
        sokoban->tmp_b = 0;
        sokoban->tmp_a = 0;
        load_map(sokoban);
    }
}