/*
** EPITECH PROJECT, 2023
** navy
** File description:
** read_pos
*/

#include "../include/navy_function.h"
#include <fcntl.h>

int same_letter_ext_2(Navy_t *navy, init_t *init, int i, int nb1)
{
    if (init->init_p2[i + 1][0] == 'A')
        navy->player2[nb1 + 1][2] = init->init_p2[i][0];
    if (init->init_p2[i + 1][0] == 'B')
        navy->player2[nb1 + 1][4] = init->init_p2[i][0];
    if (init->init_p2[i + 1][0] == 'C')
        navy->player2[nb1 + 1][6] = init->init_p2[i][0];
    if (init->init_p2[i + 1][0] == 'D')
        navy->player2[nb1 + 1][8] = init->init_p2[i][0];
    if (init->init_p2[i + 1][0] == 'E')
        navy->player2[nb1 + 1][10] = init->init_p2[i][0];
    if (init->init_p2[i + 1][0] == 'F')
        navy->player2[nb1 + 1][12] = init->init_p2[i][0];
    if (init->init_p2[i + 1][0] == 'G')
        navy->player2[nb1 + 1][14] = init->init_p2[i][0];
    if (init->init_p2[i + 1][0] == 'H')
        navy->player2[nb1 + 1][16] = init->init_p2[i][0];
    return 0;
}

int same_letter_2(Navy_t *navy, init_t *init, int i)
{
    if (init->init_p2[i + 1][0] == init->init_p2[i + 2][0]) {
        int nb1 = init->init_p2[i + 1][1] - '0';
        int nb2 = init->init_p2[i + 2][1] - '0';
        for (nb1; nb1 != nb2 + 1; nb1++)
            same_letter_ext_2(navy, init, i, nb1);
    }
    return 0;
}

int same_nbr_ext_2(Navy_t *navy, init_t *init, int i, int j)
{
    if (init->init_p2[i + 1][1] == '1')
        navy->player2[2][j] = init->init_p2[i][0];
    if (init->init_p2[i + 1][1] == '2')
        navy->player2[3][j] = init->init_p2[i][0];
    if (init->init_p2[i + 1][1] == '3')
        navy->player2[4][j] = init->init_p2[i][0];
    if (init->init_p2[i + 1][1] == '4')
        navy->player2[5][j] = init->init_p2[i][0];
    if (init->init_p2[i + 1][1] == '5')
        navy->player2[6][j] = init->init_p2[i][0];
    if (init->init_p2[i + 1][1] == '6')
        navy->player2[7][j] = init->init_p2[i][0];
    if (init->init_p2[i + 1][1] == '7')
        navy->player2[8][j] = init->init_p2[i][0];
    if (init->init_p2[i + 1][1] == '8')
        navy->player2[9][j] = init->init_p2[i][0];
}

int same_nbr_2(Navy_t *navy, init_t *init, int i)
{
    if (init->init_p2[i + 1][1] == init->init_p2[i + 2][1]) {
        int nb1 = init->init_p2[i + 1][0] - 63;
        int nb2 = init->init_p2[i + 2][0] - 63;
        int j = nb1;
        if (j - 2 > 0)
            j += j - 2;
        for (nb1; nb1 != nb2 + 1; nb1++) {
            same_nbr_ext_2(navy, init, i, j);
            j += 2;
        }
    }
}

int read_files_pos2(Navy_t *navy, char **arv)
{
    init_t *init = malloc(sizeof(init_t));
    char *buffer = NULL;
    int fd = open(arv[2], O_RDONLY);
    if (fd == -1) {
        navy->return_error = 84;
        return 84;
    }
    buffer = malloc(sizeof(char) * 32);
    read(fd, buffer, 32);
    init->init_p2 = str_to_word_array(buffer, ':');

    check_error(buffer, init->init_p2, navy);
    if (navy->return_error == 84) return 84;
    check_boat_lenght(init->init_p2, navy);
    if (navy->return_error == 84) return 84;
    check_diago(init->init_p2, navy);
    if (navy->return_error == 84) return 84;
    for (int i = 0; i != 12; i += 3)
        rd_ps_2_ext(navy, init, i);
    return 0;
}
