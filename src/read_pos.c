/*
** EPITECH PROJECT, 2023
** navy
** File description:
** read_pos
*/

#include "../include/navy_function.h"
#include <fcntl.h>

int same_letter_ext(Navy_t *navy, init_t *init, int i, int nb1)
{
    if (init->init_p1[i + 1][0] == 'A')
        navy->player1[nb1 + 1][2] = init->init_p1[i][0];
    if (init->init_p1[i + 1][0] == 'B')
        navy->player1[nb1 + 1][4] = init->init_p1[i][0];
    if (init->init_p1[i + 1][0] == 'C')
        navy->player1[nb1 + 1][6] = init->init_p1[i][0];
    if (init->init_p1[i + 1][0] == 'D')
        navy->player1[nb1 + 1][8] = init->init_p1[i][0];
    if (init->init_p1[i + 1][0] == 'E')
        navy->player1[nb1 + 1][10] = init->init_p1[i][0];
    if (init->init_p1[i + 1][0] == 'F')
        navy->player1[nb1 + 1][12] = init->init_p1[i][0];
    if (init->init_p1[i + 1][0] == 'G')
        navy->player1[nb1 + 1][14] = init->init_p1[i][0];
    if (init->init_p1[i + 1][0] == 'H')
        navy->player1[nb1 + 1][16] = init->init_p1[i][0];
    return 0;
}

int same_letter(Navy_t *navy, init_t *init, int i)
{
    if (init->init_p1[i + 1][0] == init->init_p1[i + 2][0]) {
        int nb1 = init->init_p1[i + 1][1] - '0';
        int nb2 = init->init_p1[i + 2][1] - '0';
        for (nb1; nb1 != nb2 + 1; nb1++)
            same_letter_ext(navy, init, i, nb1);
    }
    return 0;
}

int same_nbr_ext(Navy_t *navy, init_t *init, int i, int j)
{
    if (init->init_p1[i + 1][1] == '1')
        navy->player1[2][j] = init->init_p1[i][0];
    if (init->init_p1[i + 1][1] == '2')
        navy->player1[3][j] = init->init_p1[i][0];
    if (init->init_p1[i + 1][1] == '3')
        navy->player1[4][j] = init->init_p1[i][0];
    if (init->init_p1[i + 1][1] == '4')
        navy->player1[5][j] = init->init_p1[i][0];
    if (init->init_p1[i + 1][1] == '5')
        navy->player1[6][j] = init->init_p1[i][0];
    if (init->init_p1[i + 1][1] == '6')
        navy->player1[7][j] = init->init_p1[i][0];
    if (init->init_p1[i + 1][1] == '7')
        navy->player1[8][j] = init->init_p1[i][0];
    if (init->init_p1[i + 1][1] == '8')
        navy->player1[9][j] = init->init_p1[i][0];
}

int same_nbr(Navy_t *navy, init_t *init, int i)
{
    if (init->init_p1[i + 1][1] == init->init_p1[i + 2][1]) {
        int nb1 = init->init_p1[i + 1][0] - 63;
        int nb2 = init->init_p1[i + 2][0] - 63;
        int j = nb1;
        if (j - 2 > 0)
            j += j - 2;
        for (nb1; nb1 != nb2 + 1; nb1++) {
            same_nbr_ext(navy, init, i, j);
            j += 2;
        }
    }
}

int read_files_pos1(Navy_t *navy, char **arv)
{
    init_t *init = malloc(sizeof(init_t));
    char *buffer = NULL;
    int fd = open(arv[1], O_RDONLY);
    if (fd == -1) {
        navy->return_error = 84;
        return 84;
    }
    buffer = malloc(sizeof(char) * 32);
    read(fd, buffer, 32);
    init->init_p1 = str_to_word_array(buffer, ':');

    check_error(buffer, init->init_p1, navy);
    if (navy->return_error == 84) return 84;
    check_boat_lenght(init->init_p1, navy);
    if (navy->return_error == 84) return 84;
    check_diago(init->init_p1, navy);
    if (navy->return_error == 84) return 84;
    for (int i = 0; i != 12; i += 3)
        rd_ps_1_ext(navy, init, i);
    return 0;
}
