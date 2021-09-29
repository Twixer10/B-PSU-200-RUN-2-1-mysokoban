/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-thomas.techer
** File description:
** area_manager
*/

#include "../../include/sokoban.h"

void init_area(sokoban_t *sokoban)
{
    int i = 0;

    sokoban->tmp_a = 0;
    sokoban->tmp_b = 0;
    while (sokoban->tmp_b < sokoban->height) {
        while (sokoban->tmp_a < sokoban->width) {
            if (sokoban->map[sokoban->tmp_b][sokoban->tmp_a] == 'O') {
                sokoban->area[i++] = sokoban->tmp_b;
                sokoban->area[i++] = sokoban->tmp_a;
            }
            sokoban->tmp_a++;
        }
        sokoban->tmp_a = 0;
        sokoban->tmp_b++;
    }
    sokoban->total_area = i;
}
