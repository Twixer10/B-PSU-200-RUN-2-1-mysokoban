/*
** EPITECH PROJECT, 2021
** SOKOBAN
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include "my.h"
#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

typedef struct sokoban
{
    int width;
    int height;
    int return_value;
    char *buffer;
    int *area;
    int total_area;
    int tmp_a;
    int tmp_b;
    int player_x;
    int player_y;
    int tmp_x;
    int tmp_y;
    char **map;
    int utility;
} sokoban_t;

int init_map(char *path, sokoban_t *sokoban);
void init_area(sokoban_t *sokoban);
void lunch_game(sokoban_t *sokoban);
void load_map(sokoban_t *sokoban);
void try_update_moov(sokoban_t *soko);
void win_screen();
void reset_map(int ch, sokoban_t *soko);

#define HELP_MESSAGE "USAGE\n\t\t./my_sokoban map.txt\nDESCRIPTION\nmap.txt\t\
\tFile representing the warehouse map, containing '#' for walls,\n\t\t'P' for \
the player, 'X' for boxes and 'O' for storage locations.\nHOW TO PLAY\n\t\tPres\
s 'ZQSD' keys to move, -SPACE- to reset the game and 'Q' to quit.\n\t\tPush all\
 the boxes on storage locations to win.\nAUTHOR\n\t\tMade by TECHER Thomas\n"

#endif /* !SOKOBAN_H_ */
