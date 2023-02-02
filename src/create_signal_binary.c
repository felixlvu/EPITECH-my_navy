/*
** EPITECH PROJECT, 2023
** navy
** File description:
** create_signal_binary
*/

#include "../include/navy_function.h"

char **create_array(char *path)
{
    char *buffer = NULL;
    buffer = malloc(sizeof(char) * 64);
    int fd = open(path, O_RDONLY);
    read(fd, buffer, 64);
    char **dictionary = str_to_word_array(buffer, ':');
    return dictionary;
}

char *copy_dictio_bin(char *coo, char* binary_code)
{
    char **dictio_letter = create_array("src/txt/dictionary_letter.txt");
    char **dictio_nbr = create_array("src/txt/dictionary_nbr.txt");
    int event = 0;
    int i = 0;
    for (i; event != 1; i += 2) {
        if (coo[0] == dictio_letter[i][0])
            event = 1;
    }
    for (int j = 0; j != 3; j++)
        binary_code[j] = dictio_letter[i - 1][j];
    for (i = 0; event != 0; i += 2) {
        if (coo[1] == dictio_nbr[i][0])
            event = 0;
    }
    for (int j = 0; j != 3; j++)
        binary_code[j + 3] = dictio_nbr[i - 1][j];
    binary_code[7] = '\0';
    return binary_code;
}

void hand(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1) {
        global = 0;
    }
    if (signum == SIGUSR2) {
        global = 1;
    }
}

void send_signal(char *buff, int pid)
{
    struct sigaction act;
    act.sa_sigaction = hand;
    for (int i = 0; i != 6; i++) {
        if (buff[i] == '0') {
            kill(pid, SIGUSR1);
        } else {
            kill(pid, SIGUSR2);
        }
        sigaction(SIGUSR1, &act, NULL);
        pause();
    }
}

void receive_signal(Navy_t *navy)
{
    global = -1;
    char *binary = malloc(sizeof(char) * 7);
    binary[6] = '\0';
    struct sigaction act;
    act.sa_sigaction = hand;

    for (int index = 0; index != 6; index++) {
        sigaction(SIGUSR1, &act, NULL);
        sigaction(SIGUSR2, &act, NULL);
        pause();
        if (global == 0) {
            binary[index] = '0';
        }
        if (global == 1) {
            binary[index] = '1';
        }
        kill(navy->playerpid2, SIGUSR1);
    }
}
