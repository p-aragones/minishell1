/*
** EPITECH PROJECT, 2020
** minish.h
** File description:
** minish header file
*/

#ifndef MY_MINI_H_
#define MY_MINI_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libmy.h"
#include "env.h"

int loop(env_t *);
int my_cd(char *, env_t *, int);
void print_env(env_t *);
void print_prompt(void);
int exec_func(char **, char *, env_t *);
char **my_str_to_word_array(char *);
int count_w(char *);
int is_check(char);
int len_of_word(char *, int);
char *get_name(char *);
char *get_value(char *);
char *create_new_path(char *, char *, char *);
int usr_path(char *, env_t *, int *);
char *find_home_path(env_t *);
int actual(char *, env_t *);
int check_chars(char);
char **my_split(char *);
char *get_path(env_t *, char *);
char **path_from_env(env_t *);
int check_builtin(env_t *, char **, int);
int my_exit(int, char **);
void change_dir(char *, env_t *, char *);
int cd_dash(env_t *, int *);

env_t *change_element(env_t *, char *, char *);
env_t *set_new_env(char *, char *);
env_t *unset_env(env_t *, char **, int);
env_t *add_enviro(env_t *, char *, char *);
env_t *create_node(char *);
env_t *add_start(env_t *, char *);
env_t *add_end(env_t *, char *);
env_t *init_list(char **);
env_t *setenv_env(env_t *, char **, int);

#endif /* !MINI_H_ */
