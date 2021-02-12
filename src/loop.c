/*
** EPITECH PROJECT, 2021
** loop
** File description:
** shell loop of functions
*/

#include "mini.h"

char *get_input(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    print_prompt();
    lineSize = getline(&line, &len, stdin);
    if (lineSize == EOF || my_strcmp(line, "exit\n") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    return (line);
}

int count_args(char **args)
{
    int i = 0;

    while (args[i] != NULL)
        i++;
    return (i);
}

int find_function(char **args, env_t *env)
{
    int error = 0;
    char *path = get_path(env, args[0]);

    if (path == NULL && args[0][0] != '\n') {
        my_putstr(args[0]);
        my_putstr(": Command not found.\n");
        return (error);
    }
    error = exec_func(args, path, env);
    return (error);
}

int exec_function(char *input, env_t *env)
{
    char **args;
    int error = 0;
    int arg_count = 0;

    if (input[0] == '\n')
        return (0);
    args = my_str_to_word_array(input);
    if (args == NULL || args[0] == NULL)
        return (0);
    arg_count = count_args(args);
    if (check_builtin(env, args, arg_count) != 0) {
        error = find_function(args, env);
    }
    return (error);
}

int loop(env_t *env)
{
    char *input = my_malloc(1);

    while (my_strcmp(input, "exit\n")) {
        input = my_strdup(get_input());
        if (input == NULL)
            return (84);
        if (exec_function(input, env) != 0)
            return (84);
    }
    my_putstr("exit\n");
    free(input);
    return (0);
}