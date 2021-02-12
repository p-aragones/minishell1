/*
** EPITECH PROJECT, 2021
** cd_func
** File description:
** cd_func
*/

#include "mini.h"

char *create_new_path(char *new_path, char *current_path, char *path)
{
    int i = 0;
    int j = 0;

    while (current_path[i] != '\0') {
        new_path[i] = current_path[i];
        i++;
    }
    new_path[i] = '/';
    i++;
    while (path[j] != '\0') {
        new_path[i] = path[j];
        i++;
        j++;
    }
    return (new_path);
}

int usr_path(char *path, env_t *env, int *i)
{
    int home_len = my_strlen(find_home_path(env));
    char *new_path = my_malloc(home_len);

    new_path = find_home_path(env);
    change_dir(new_path, env, path);
    *i = 1;
    return (0);
}

env_t *setenv_cd(env_t *head, char *name, char *value, int ac)
{
    env_t *temp = head;

    if (ac > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (NULL);
    }
    if (ac == 1)
        print_env(head);
    if (name == NULL)
        return (NULL);
    if (value == NULL)
        value = my_strdup("");
    head = change_element(head, name, value);
    return (head);
}

void change_dir(char *new_dir, env_t *env, char *path)
{
    char *current_path = NULL;
    size_t size = 0;
    char *new_current_path = NULL;
    size_t new_size = 0;

    current_path = getcwd(current_path, size);
    if (chdir(new_dir) != 0) {
        if (path != NULL)
            my_putstr(path);
        my_putstr(": No such file or directory.\n");
    } else {
        setenv_cd(env, "OLDPWD", current_path, 3);
        new_current_path = getcwd(new_current_path, new_size);
        setenv_cd(env, "PWD", new_current_path, 3);
    }
}