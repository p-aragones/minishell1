/*
** EPITECH PROJECT, 2021
** linked_functions
** File description:
** linked_functions
*/

#include "mini.h"

env_t *create_node(char *str)
{
    env_t *node = malloc(sizeof(env_t));
    char *name = get_name(str);
    char *value = get_value(str);

    if (node == NULL)
        return (NULL);
    node->name = name;
    node->value = value;
    node->next = NULL;
    return (node);
}

env_t *add_start(env_t *head, char *name)
{
    env_t *list = create_node(name);

    if (list == NULL)
        return (NULL);
    list->next = head;
    return (list);
}

env_t *add_end(env_t *head, char *name)
{
    env_t *list = create_node(name);
    env_t *temp = head;

    if (list == NULL)
        return (NULL);
    if (head == NULL)
        return (list);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list;
    return (head);
}

env_t *add_enviro(env_t *head, char *name, char *value)
{
    env_t *temp = head;

    head = set_new_env(name, value);
    if (head == NULL)
        return (NULL);
    if (head == NULL)
        return (head);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
}