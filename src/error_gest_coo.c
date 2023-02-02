/*
** EPITECH PROJECT, 2023
** navy
** File description:
** error_gest_coo
*/

#include "../include/navy_function.h"
#include <fcntl.h>

int check_nbr_if (Navy_t *navy, char *check, int index)
{
    if (check[index] == 'o')
        check[index] = 'x';
    else
        navy->return_error = 84;
    return 0;
}

int check_nbr_boat (char *buffer, Navy_t *navy)
{
    char check[9] = "2o3o4o5o";

    for (int i = 0; i != 32; i += 8) {
        if (buffer[i] == '2')
            check_nbr_if(navy, check, 1);
        if (buffer[i] == '3')
            check_nbr_if(navy, check, 3);
        if (buffer[i] == '4')
            check_nbr_if(navy, check, 5);
        if (buffer[i] == '5')
            check_nbr_if(navy, check, 7);
    }
    return 0;
}

int check_lenght_ext(int check_lenght, int lenght, Navy_t *navy)
{
    if (check_lenght != lenght - 1)
        navy->return_error = 84;
    return 0;
}

int check_boat_lenght(char **str, Navy_t *navy)
{
    int lenght = 0;
    int check_lenght = 0;

    for (int i = 0; i != 12; i += 3) {
        lenght = my_atoi(str[i]);
        if (str[i + 1][0] == str[i + 2][0]) {
            check_lenght = str[i + 2][1] - str[i + 1][1];
            check_lenght_ext(check_lenght, lenght, navy);
        }
        if (str[i + 1][1] == str[i + 2][1]) {
            check_lenght = str[i + 2][0] - str[i + 1][0];
            check_lenght_ext(check_lenght, lenght, navy);
        }
    }
}

int check_diago(char **str, Navy_t *navy)
{
    for (int i = 1; i != 13; i += 3) {
        if (str[i][0] != str[i + 1][0] && str[i][1] != str[i + 1][1])
            navy->return_error = 84;
    }
}
