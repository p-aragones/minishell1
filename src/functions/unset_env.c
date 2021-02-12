/*
** EPITECH PROJECT, 2021
** B-PSU-101-BAR-1-1-minishell1
** File description:
** unset_env
*/

#include "mini.h"

env_t *find_name(env_t *env, char **names, int i)
{
    env_t *temp = env;

    while (temp->next != NULL) {
        if (my_strcmp(temp->next->name, names[i]) == 0) {
            temp->next = temp->next->next;
            return (env);
        }
        temp = temp->next;
    }
    return (env);
}

env_t *unset_env(env_t *env, char **names, int ac)
{
    int i = 0;

    if (ac < 2) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (NULL);
    }
    if (env == NULL)
        return (NULL);
    while (names[i] != NULL) {
        env = find_name(env, names, i);
        i++;
    }
    return (env);
}