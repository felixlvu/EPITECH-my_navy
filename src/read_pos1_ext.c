/*
** EPITECH PROJECT, 2023
** navy
** File description:
** read_pos1_ext
*/

#include "../include/navy_function.h"
#include <fcntl.h>

int rd_ps_1_ext(Navy_t *navy, init_t *init, int i)
{
    if (init->init_p1[i][0] == '2') {
        same_letter(navy, init, i);
        same_nbr(navy, init, i);
    }
    if (init->init_p1[i][0] == '3') {
        same_letter(navy, init, i);
        same_nbr(navy, init, i);
    }
    if (init->init_p1[i][0] == '4') {
        same_letter(navy, init, i);
        same_nbr(navy, init, i);
    }
    if (init->init_p1[i][0] == '5') {
        same_letter(navy, init, i);
        same_nbr(navy, init, i);
    }
    return 0;
}
