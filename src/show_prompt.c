/*
** EPITECH PROJECT, 2021
** B-PSU-101-BAR-1-1-minishell1
** File description:
** show_prompt
*/

#include "mini.h"

int last_slash(char *cwd)
{
    int i = 0;
    int slash_pos = 0;

    while (cwd[i] != '\0') {
        if (cwd[i] == '/')
            slash_pos = i;
        i++;
    }
    return (slash_pos);
}

char *set_color(char *color_code, char *str)
{
    char *str_colored = my_malloc(my_strlen(str) + my_strlen(color_code) + 8);

    str_colored = my_strcat(str_colored, color_code);
    str_colored = my_strcat(str_colored, str);
    str_colored = my_strcat(str_colored, "\033[0m");
    return (str_colored);
}

void print_prompt(void)
{
    int i = 0;
    int j = 0;
    char *buf = NULL;
    size_t size = 0;
    char *cwd = getcwd(buf, size);
    char *color = my_malloc(my_strlen(cwd));

    if (cwd == NULL) {
        my_putstr("\033[22;34$>\033[0m");
    } else {
        i = last_slash(cwd);
        while (cwd[i] != '\0') {
            color[j] = cwd[i++];
            j++;
        }
        my_putstr("\033[22;34m<\033[0m");
        my_putstr(set_color("\033[1;32m", color));
        my_putstr("\033[22;34m> \033[0m");
        my_putstr(set_color("\033[1;31m", "~> "));
    }
}