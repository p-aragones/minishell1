/*
** EPITECH PROJECT, 2021
** env
** File description:
** env
*/

#ifndef ENV_H_
#define ENV_H_

typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
} env_t;

#endif /* !ENV_H_ */
