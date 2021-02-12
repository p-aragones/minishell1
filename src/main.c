/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** remake of tcsh
*/

#include "mini.h"

int main(int ac, char **av, char **env)
{
    env_t *env_list = init_list(env);
    (void)av;
    if (ac != 1)
        return (84);
    return (loop(env_list));
}