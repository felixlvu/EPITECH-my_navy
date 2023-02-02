/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H

    int my_putchar(char c);
    int my_put_nbr(int nb);
    int my_getnbr(const char *str);
    int my_putstr(char const *str);
    int	my_strcmp(char const *s1, char const *s2);
    char **str_to_word_array (char *str, char separator);
    int my_strlen(char const *str);
    int my_atoi(char *str);

#endif
