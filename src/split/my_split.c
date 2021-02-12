/*
** EPITECH PROJECT, 2021
** strtowarr
** File description:
** str to word array
*/

#include "mini.h"
#include "libmy.h"

int check_chars(char w)
{
    if (w != '\0' && w != ':' && w != '\n' && w != '\t')
        return (1);
    else
        return (0);
}