/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-thomas.techer
** File description:
** load_map
*/

#include "../../include/sokoban.h"

void load_width(sokoban_t *sokoban)
{
    int tmp = 0;
    int i = 0;

    sokoban->tmp_a = 0;
    sokoban->tmp_b = 0;
    sokoban->width = 0;
    while (sokoban->buffer[i] != '\0') {
        if (sokoban->buffer[i] == '\n') {
            if (tmp > sokoban->width)
                sokoban->width = tmp - 1;
            tmp = 0;
        }
        i++;
        tmp++;
    }
}

void load_map2(sokoban_t *s)
{
    while (s->tmp_a < s->width) {
        s->map[s->tmp_b][s->tmp_a] = s->buffer[s->utility];
        if (s->buffer[s->utility] == 'P')
            s->player_x = s->tmp_a;
        if (s->buffer[s->utility] == 'P')
            s->player_y = s->tmp_b;
        if (s->buffer[s->utility] == '\n')
            s->map[s->tmp_b][s->tmp_a + 1] = '\0';
        if (s->buffer[s->utility] == '\n')
            s->tmp_a = s->width;
        else
            s->utility++;
        s->tmp_a++;
    }
}

void load_map(sokoban_t *s)
{
    s->utility = 0;
    s->map = malloc(sizeof(char*) * s->height +1);
    while (s->tmp_b < s->height) {
        s->map[s->tmp_b] = malloc(sizeof(char) * (s->width + 1));
        load_map2(s);
        s->utility++;
        s->tmp_a = 0;
        s->tmp_b++;
    }
}

int init_game(sokoban_t *sokoban)
{
    int i = 0;

    sokoban->map = NULL;
    sokoban->height = 0;
    if ((sokoban->area = malloc(sizeof(int) * 100)) == NULL)
        return (my_error("Error: Malloc Error in `init_game`", 84));
    load_width(sokoban);
    while (sokoban->buffer[i] != '\0') {
        if (sokoban->buffer[i] == '\n')
            sokoban->height++;
        i++;
    }
    load_map(sokoban);
    init_area(sokoban);
    lunch_game(sokoban);
    return (0);
}

int init_map(char *path, sokoban_t *sokoban)
{
    struct stat s;
    int f;

    if ((f = open(path, O_RDONLY)) == -1) {
        my_printf("Error: Can not open this file : %s", path);
        return (84);
    }
    stat(path, &s);
    sokoban->buffer = NULL;
    if ((sokoban->buffer = malloc(sizeof(char) * s.st_size)) == NULL)
        return (my_error("Error: Can not load this map (malloc error)", 84));
    if (read(f, sokoban->buffer, s.st_size) < 0)
        return (my_error("Error: Can not load this map (read error)", 84));
    close(f);
    return (init_game(sokoban));
}