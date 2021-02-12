/*
** EPITECH PROJECT, 2021
** B-PSU-101-BAR-1-1-minishell1
** File description:
** check_builtin
*/

#include "mini.h"

int check_builtin(env_t *env, char **av, int ac)
{
    int exec = 0;

    if (my_strcmp(av[0], "cd") == 0) {
        my_cd(av[1], env, ac);
        exec = 1;
    } if (my_strcmp(av[0], "env") == 0) {
        print_env(env);
        exec = 1;
    } if (my_strcmp(av[0], "setenv") == 0) {
        setenv_env(env, av, ac);
        exec = 1;
    } if (my_strcmp(av[0], "unsetenv") == 0) {
        unset_env(env, av, ac);
        exec = 1;
    } if (my_strcmp(av[0], "exit") == 0) {
        my_exit(ac, av);
        exec = 1;
    } if (exec == 0)
        return (-1);
    return (0);
}

char **path_from_env(env_t *env)
{
    env_t *temp = env;

    while (temp != NULL && my_strcmp(temp->name, "PATH") != 0)
        temp = temp->next;
    if (temp == NULL)
        return (NULL);
    return (my_split(temp->value));
}

char *get_path(env_t *env, char *args)
{
    char **paths = path_from_env(env);
    char *func_path;
    int i = 0;

    if (paths == NULL)
        return (NULL);
    if (access(args, F_OK) == 0)
        return (args);
    while (paths[i] != NULL) {
        func_path = my_malloc(my_strlen(paths[i]) + my_strlen(args) + 2);
        func_path = my_strcat(my_strcat(func_path, paths[i]), "/");
        func_path = my_strcat(func_path, args);
        if (access(func_path, F_OK) == 0)
            return (func_path);
        i++;
    }
    return (NULL);
}