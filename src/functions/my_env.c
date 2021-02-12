/*
** EPITECH PROJECT, 2021
** my_env
** File description:
** my_env
*/

#include "mini.h"

void print_env(env_t *env)
{
    while (env != NULL) {
        my_putstr(env->name);
        my_putchar(61);
        my_putstr(env->value);
        my_putchar('\n');
        env = env->next;
    }
}

env_t *set_new_env(char *name, char *value)
{
    env_t *node = malloc(sizeof(env_t));

    if (node == NULL)
        return (NULL);
    node->name = name;
    node->value = value;
    node->next = NULL;
    return (node);
}

env_t *change_element(env_t *env, char *name, char *value)
{
    env_t *temp = env;
    int i = 0;

    while (temp != NULL) {
        if (my_strcmp(temp->name, name) == 0) {
            temp->value = value;
            return (env);
        }
        temp = temp->next;
    }
    add_enviro(env, name, value);
    return (env);
}

int is_alphanum(char *s)
{
    int i = 0;

    if (s[0] >= '0' && s[0] <= '9') {
        my_putstr("setenv: Variable name must begin with a letter.\n");
    }
    while (s[i] != '\0') {
        if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') &&
        (s[i] < '0' || s[i] > '9')) {
            my_putstr("setenv: Variable name must ");
            my_putstr("contain alphanumeric characters.\n");
            return (0);
        }
        i++;
    }
    return (1);
}

env_t *setenv_env(env_t *head, char **args, int ac)
{
    env_t *temp = head;

    if (head == NULL)
        return (NULL);
    if (ac > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (NULL);
    }
    if (ac == 1)
        print_env(head);
    if (args[1] == NULL)
        return (NULL);
    if (args[2] == NULL)
        args[2] = my_strdup("");
    if (is_alphanum(args[1]) == 0)
        return (NULL);
    head = change_element(head, args[1], args[2]);
    return (head);
}