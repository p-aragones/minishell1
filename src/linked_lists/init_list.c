/*
** EPITECH PROJECT, 2021
** init_list.c
** File description:
** init_list
*/

#include "mini.h"

env_t *init_list(char **env_sys)
{
    env_t *env_list = NULL;
    int i = 0;

    while (env_sys[i] != NULL) {
        env_list = add_end(env_list, env_sys[i]);
        i++;
    }
    return (env_list);
}