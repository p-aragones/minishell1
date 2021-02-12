/*
** EPITECH PROJECT, 2021
** functions file
** File description:
** functions
*/

#include "mini.h"

int list_length(env_t *env)
{
    env_t *temp = env;
    int len = 0;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return (len + 1);
}

char **list_to_arr(env_t *env)
{
    env_t *temp = env;
    char **arr = malloc(sizeof(char *) * (list_length(env) + 1));
    int i = 0;

    while (temp != NULL) {
        arr[i] = my_malloc(my_strlen(temp->name) + my_strlen(temp->value) + 2);
        arr[i] = my_strcat(arr[i], temp->name);
        arr[i] = my_strcat(arr[i], "=");
        arr[i] = my_strcat(arr[i], temp->value);
        i++;
        temp = temp->next;
    }
    arr[i] = NULL;
    return (arr);
}

int exec_func(char **arguments, char *path, env_t *env)
{
    int pid = fork();
    int status = 0;
    int error = 0;
    char **env_arr = list_to_arr(env);

    if (pid == -1)
        return (84);
    else if (pid == 0) {
        error = execve(path, arguments, env_arr);
    }
    waitpid(pid, &status, 0);
    if (error != 0)
        my_putstr("Segmentation fault");
    return (0);
}