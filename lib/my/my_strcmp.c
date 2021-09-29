/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** lib
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i]) {
        if (s1[i] != s2[i])
            return (FALSE);
        i = i + 1;
    }
    return (TRUE);
}
