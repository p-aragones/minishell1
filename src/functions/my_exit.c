/*
** EPITECH PROJECT, 2021
** B-PSU-101-BAR-1-1-minishell1
** File description:
** my_exit
*/

#include "mini.h"

int my_exit(int ac, char **av)
{
    if (ac > 2) {
        my_putstr("exit: Expression Syntax.\n");
        return (-1);
    }
    if (ac > 1 && my_str_isnum(av[1]) == 1) {
        my_putstr("exit\n");
        exit(my_getnbr(av[1]));
    } if (ac == 1 && my_strcmp(av[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    } if (my_str_isnum(av[1]) == 0) {
        my_putstr("exit: Expression Syntax.\n");
    }
}