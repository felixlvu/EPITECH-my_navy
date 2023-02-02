/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** my_navy
*/

#include "../include/navy_function.h"

void attack(int arc, char **arv, Navy_t *navy, char *pos)
{
    char *binary_code = malloc(sizeof(char) * 7);
    size_t len = 0;
    int event = 0;

    while (event == 0) {
        my_putstr("\nattack: ");
        getline(&pos, &len, stdin);
        if (pos[0] >= 65 && pos[0] <= 72 && pos[1] >= 49 && pos[1] <= 56) {
            binary_code = trans_coo_bin(pos);
            send_signal(binary_code, navy->playerpid2);
            write(1, pos, 2);
            my_putstr(":\n");
            event = 1;
        } else {
            my_putstr("wrong position");
        }
    }
}
