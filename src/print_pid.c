/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** my_navy
*/

#include "../include/navy_function.h"

void print_pid(int arc, char **arv, Navy_t *navy)
{
    if (arc == 2) {
        navy->playerpid1 = getpid();
        my_putstr("my_pid: ");
        my_put_nbr(navy->playerpid1);
        my_putstr("\nwaiting for enemy connection...\n");
    }
    if (arc == 3) {
        navy->playerpid1 = getpid();
        navy->playerpid2 = my_getnbr(arv[1]);
        my_putstr("my_pid: ");
        my_put_nbr(navy->playerpid1);
        my_putstr("\n");
    }
}
