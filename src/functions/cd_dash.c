/*
** EPITECH PROJECT, 2021
** B-PSU-101-BAR-1-1-minishell1
** File description:
** cd_dash
*/

#include "mini.h"

char *get_old_path(env_t *env)
{
    env_t *temp = env;

    while (temp != NULL && my_strcmp(temp->name, "OLDPWD") != 0) {
        temp = temp->next;
    }
    if (temp == NULL)
        return (NULL);
    return (temp->value);
}

int cd_dash(env_t *env, int *integer)
{
    char *old_path = get_old_path(env);

    *integer = 1;
    if (old_path == NULL) {
        my_putstr(": No such file or directory.\n");
        return (84);
    }
    change_dir(old_path, env, NULL);
    return (0);
}