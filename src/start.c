/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** my_navy
*/

#include "../include/navy_function.h"

void start_receive(int arc, char **arv, Navy_t *navy)
{
    print_base(arc, arv, navy);
    my_putstr("\nwaiting for enemy's attack...\n");
    receive_signal(navy);
}

void start_attack(int arc, char **arv, Navy_t *navy, char *pos)
{
    print_base(arc, arv, navy);
    attack(arc, arv, navy, pos);
}

char *trans_coo_bin(char *coo)
{
    char *binary_code = NULL;

    binary_code = malloc(sizeof(char) * 7);
    binary_code = copy_dictio_bin(coo, binary_code);
    return binary_code;
}
