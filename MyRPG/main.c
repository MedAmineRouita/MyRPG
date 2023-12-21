/*
** EPITECH PROJECT, 2022
** main_for_rpg
** File description:
** main.c
*/

#include "include/my.h"

all_t *init_all(void);
void print_all(all_t *all);
void process(all_t *all);

int main(int ac, UNUSED() char **av)
{
    if (ac == 2)
        return 84;
    all_t *all = init_all();
    process(all);
    return 0;
}
