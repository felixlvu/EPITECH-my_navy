/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** navy_function
*/

#ifndef NAVY_FUNCTION_H_
    #define NAVY_FUNCTION_H_
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <signal.h>
    #include <fcntl.h>
    #include "myn.h"
    #include "my.h"

    extern int global;
    int main(int arc, char **arv);
    void flag_h(void);
    char **str_to_word_array (char *str, char separator);
    int create_map(Navy_t *navy, char **argv);
    int read_files_pos1(Navy_t *navy, char **arv);
    int rd_ps_1_ext(Navy_t *navy, init_t *init, int i);
    int same_nbr(Navy_t *navy, init_t *init, int i);
    int same_letter(Navy_t *navy, init_t *init, int i);
    int read_files_pos2(Navy_t *navy, char **arv);
    int rd_ps_2_ext(Navy_t *navy, init_t *init, int i);
    int same_nbr_2(Navy_t *navy, init_t *init, int i);
    int same_letter_2(Navy_t *navy, init_t *init, int i);
    void print_base(int arc, char **arv, Navy_t *navy);
    char *trans_coo_bin(char *coo);
    void send_signal(char *buff, int pid);
    void receive_signal(Navy_t *navy);
    int check_nbr_boat(char *buffer, Navy_t *navy);
    int check_letter(Navy_t *navy, char **buffer);
    int check_nbr(Navy_t *navy, char **buffer);
    int check_error(char *buffer, char **init, Navy_t *navy);
    int check_len (char *buffer, Navy_t *navy);
    int check_boat_lenght(char **str, Navy_t *navy);
    int check_diago(char **str, Navy_t *navy);
    char **create_array(char *path);
    void attack(int arc, char **arv, Navy_t *navy, char *pos);
    void print_pid(int arc, char **arv, Navy_t *navy);
    void start_receive(int arc, char **arv, Navy_t *navy);
    void start_attack(int arc, char **arv, Navy_t *navy, char *pos);
    char *copy_dictio_bin(char *coo, char* binary_code);

#endif /* !NAVY_FUNCTION_H_ */
