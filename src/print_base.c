/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** my_navy
*/

#include "../include/navy_function.h"

void print_patern(char **player)
{
    for (int i = 0; player[i] != NULL; i++) {
        my_putstr(player[i]);
        write(1, "\n", 1);
    }
}

void print_base(int arc, char **arv, Navy_t *navy)
{
    if (arc == 2) {
        my_putstr("\nmy positions:\n");
        print_patern(navy->player1);
        my_putstr("\nenemy's positions:\n");
        print_patern(navy->player1_nmi);
    }
    if (arc == 3) {
        my_putstr("\nmy positions:\n");
        print_patern(navy->player2);
        my_putstr("\nenemy's positions:\n");
        print_patern(navy->player2_nmi);
    }
}
