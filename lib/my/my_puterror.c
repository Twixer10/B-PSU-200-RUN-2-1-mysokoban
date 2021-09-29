/*
** EPITECH PROJECT, 2021
** libC
** File description:
** my_puterror
*/

#include <unistd.h>
#include "../../include/my.h"

void my_puterror(char *err)
{
    for (int i = 0; err[i] != '\0'; i++)
        write(2, &err[i], 1);
}
