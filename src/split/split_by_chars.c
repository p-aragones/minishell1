/*
** EPITECH PROJECT, 2021
** word_to_array
** File description:
** str word to array
*/

#include "mini.h"
#include "libmy.h"

int count_dots(char *str)
{
    int i = 0;
    int w = 0;

    while (str[i] != '\0') {
        if (check_chars(str[i]) == 1 && check_chars(str[i + 1]) == 0)
            w++;
        i++;
    }
    return (w);
}

int len_of_path(char *str, int i)
{
    int len_of = 0;

    while (check_chars(str[i]) == 1) {
        i++;
        len_of++;
    }
    return (len_of);
}

char **my_split(char *str)
{
    char **result = malloc(sizeof(char *) * (count_dots(str) + 1));
    int a = 0;
    int b = 0;
    int c = 0;

    if (result == NULL)
        return (NULL);
    while (b <= (count_dots(str) - 1)) {
        while (check_chars(str[a]) == 0)
            a++;
        result[b] = my_malloc(len_of_path(str, a) + 1);
        while (check_chars(str[a]) == 1) {
            result[b][c++] = str[a];
            a++;
        }
        c = 0;
        b++;
    }
    result[b] = NULL;
    return (result);
}