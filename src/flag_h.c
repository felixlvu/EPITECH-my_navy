/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar
*/

#include "../include/navy_function.h"
#include "../include/myn.h"

void flag_h(void)
{
    write(1, "USAGE\n", 7);
    write(1, "     ./navy [first_player_pid] navy_positions\n", 47);
    write(1, "\nDESCRIPTION\n", 14);
    write(1, "     first_player_pid: only for the 2nd ", 40);
    write(1, "player. pid of the first player.\n", 34);
    write(1, "     navy_positions: file representing ", 39);
    write(1, "the positions of the ships.\n", 29);
}
