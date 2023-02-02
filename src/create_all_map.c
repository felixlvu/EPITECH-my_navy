/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** create_all_map
*/

#include "../include/navy_function.h"
#include "../include/myn.h"
#include <fcntl.h>

int create_map(Navy_t *navy, char **argv)
{
    int fd = 0;
    char *buffer = NULL;
    buffer = malloc(sizeof(char) * 180);
    fd = open("src/txt/map.txt", O_RDONLY);
    read(fd, buffer, 180);
    close(fd);

    navy->player1 = str_to_word_array(buffer, '\n');
    navy->player1_nmi = str_to_word_array(buffer, '\n');
    navy->player2 = str_to_word_array(buffer, '\n');
    navy->player2_nmi = str_to_word_array(buffer, '\n');
    return 0;
}
