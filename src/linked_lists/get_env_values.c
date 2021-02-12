/*
** EPITECH PROJECT, 2021
** get_env_values.c
** File description:
** get_env_values
*/

#include "mini.h"

char *get_name(char *str)
{
    char *name = my_malloc(my_strlen(str));
    int i = 0;

    while (str[i] != 61) {
        name[i] = str[i];
        i++;
    }
    return (name);
}

char *get_value(char *str)
{
    char *value = my_malloc(my_strlen(str));
    int i = 0;
    int j = 0;

    while (str[i] != 61)
        i++;
    i++;
    while (str[i] != '\0') {
        value[j] = str[i];
        i++;
        j++;
    }
    return (value);
}