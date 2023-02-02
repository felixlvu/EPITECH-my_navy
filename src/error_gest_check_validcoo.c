/*
** EPITECH PROJECT, 2023
** navy
** File description:
** error_gest_check_validcoo
*/

#include "../include/navy_function.h"
#include <fcntl.h>

int check_letter_ext(char **buffer, int i, int error)
{
    char letter[9] = "ABCDEFGH";

    for (int index_l = 0; letter[index_l] != '\0'; index_l++) {
        if (buffer[i][0] == letter[index_l])
            error += 1;
        if (buffer[i + 1][0] == letter[index_l])
            error += 1;
    }
    return error;
}

int check_letter(Navy_t *navy, char **buffer)
{
    int error = 0;

    for (int i = 1; i != 13; i += 3) {
        error = check_letter_ext(buffer, i, error);
    }
    if (error != 8)
        navy->return_error = 84;
    return 0;
}

int check_nbr_ext(char **buffer, int i, int error)
{
    char nbr[9] = "12345678";

    for (int index_l = 0; nbr[index_l] != '\0'; index_l++) {
        if (buffer[i][1] == nbr[index_l])
            error += 1;
        if (buffer[i + 1][1] == nbr[index_l])
            error += 1;
    }
    return error;
}

int check_nbr(Navy_t *navy, char **buffer)
{
    int error = 0;

    for (int i = 1; i != 13; i += 3)
        error = check_nbr_ext(buffer, i, error);
    if (error != 8)
        navy->return_error = 84;
    return 0;
}

int check_error(char *buffer, char **init, Navy_t *navy)
{
    int i = 0;
    for (i; init[i] != NULL; i++);
    if (i != 12)
        navy->return_error = 84;
    if (navy->return_error == 84)
        return 84;
    check_nbr_boat(buffer, navy);
    if (navy->return_error == 84)
        return 84;
    check_letter(navy, init);
    if (navy->return_error == 84)
        return 84;
    check_nbr(navy, init);
    if (navy->return_error == 84)
        return 84;
    return 0;
}
