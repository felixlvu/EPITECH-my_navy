/*
** EPITECH PROJECT, 2022
** my.r
** File description:
** my.r
*/

#ifndef MYR_H
    #define MYR_H

    typedef struct {
        int count_t;
        int playerpid1;
        int playerpid2;
        int return_error;
        char **player1;
        char **player2;
        char **player1_nmi;
        char **player2_nmi;
    } Navy_t;

    typedef struct init {
        char **init_p1;
        char **init_p2;
    } init_t;

#endif
