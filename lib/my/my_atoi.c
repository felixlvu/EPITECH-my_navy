/*
** EPITECH PROJECT, 2022
** my_pushswap
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int return_nbr = 0;
    int i = 0;
    int check_neg = 0;

    if (str[0] == '-') {
        i = 1;
        check_neg = 42;
    }
    for (; str[i] != '\0'; i++) {
        return_nbr *= 10;
        return_nbr += (str[i] - '0');
    }
    if (check_neg == 42) {
        return_nbr = -return_nbr;
    }
    return return_nbr;
}
