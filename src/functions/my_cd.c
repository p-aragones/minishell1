/*
** EPITECH PROJECT, 2021
** my_cd
** File description:
** my_cd
*/

#include "mini.h"

int actual(char *path, env_t *env)
{
    char *new_path = NULL;
    char *current_path = NULL;
    char *home = find_home_path(env);
    size_t size = 0;

    if (home == NULL)
        return (-1);
    current_path = getcwd(current_path, size);
    new_path = my_malloc(my_strlen(current_path) + my_strlen(path) + 2);
    if (new_path == NULL)
        return (84);
    if (my_strcmp(path, "home") == 0) {
        new_path = my_strdup(home);
        my_putstr("~\n");
    } else
        new_path = create_new_path(new_path, current_path, path);
    change_dir(new_path, env, path);
    return (0);
}

char *find_home_path(env_t *env)
{
    env_t *temp = env;

    while (temp != NULL && my_strcmp(temp->name, "HOME") != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        my_putstr("cd: no home directory\n");
        return (NULL);
    }
    return (temp->value);
}

int start_from_usr(char *path, env_t *env, int *integer)
{
    int i = 0;
    int j = 2;
    char *home = find_home_path(env);
    char *dir = my_malloc(my_strlen(home) + my_strlen(path));
    char *new_path = my_malloc(my_strlen(path));

    *integer = 1;
    if (home == NULL)
        return (-1);
    while (my_strlen(path) > 2 && path[j] != '\0') {
        new_path[i] = path[j++];
        i++;
    }
    if (my_strcmp(path, "~") == 0 || my_strcmp(path, "--") == 0) {
        dir = my_strdup(home);
    } else
        dir = my_strcat(my_strcat(my_strcat(dir, home), "/"), new_path);
    change_dir(dir, env, path);
    return (0);
}

int start_from_computer(char *path, env_t *env, int *integer)
{
    int i = 0;
    int j = 1;
    int count = 0;
    char *new_dir = my_malloc(my_strlen(path) + 1);

    new_dir = my_strdup("/");
    if (my_strcmp(path, "/") != 0)
        new_dir = my_strcat(new_dir, path);
    change_dir(new_dir, env, path);
    *integer = 1;
    return (0);
}

int my_cd(char *path, env_t *env, int ac)
{
    int error = 0;
    int i = 0;

    if (ac > 2) {
        my_putstr("cd: too many arguments\n");
        return (error);
    }
    if (find_home_path(env) == NULL)
        return (84);
    if (ac == 1)
        error = usr_path(path, env, &i);
    if (ac > 1 && (path[0] == '~' || my_strcmp(path, "--") == 0)) {
        error = start_from_usr(path, env, &i);
    } else if (ac > 1 && path[0] == '/')
        error = start_from_computer(path, env, &i);
    if (path != NULL && my_strcmp(path, "-") == 0)
        error = cd_dash(env, &i);
    if (i == 0)
        error = actual(path, env);
    return (error);
}