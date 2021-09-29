/*
** EPITECH PROJECT, 2021
** MAIN SOKOBAN
** File description:
** SOKOBAN
*/

#include "../include/sokoban.h"

int main(int ac, char **av)
{
    sokoban_t sokoban;

    if (ac != 2)
        return (my_error(
            "Error: Incorrect syntax, type ./my_sokoban -h for help.\n", 84));
    if (check_args(av, 1, "-h"))
        return (my_error(HELP_MESSAGE, 0));
    return (init_map(av[1], &sokoban));
}