/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** network
*/

#include "papaya.h"

char *smerge(char *string1, char *string2)
{
    size_t len_tot = strlen(string1) + strlen(string2);
    char *string = malloc(sizeof(char) * len_tot + 1);
    size_t l1 = strlen(string1);

    string[len_tot] = '\0';
    for (size_t i = 0; i < l1; i++)
        string[i] = string1[i];
    for (size_t i = l1; i < len_tot; i++)
        string[i] = string2[i - l1];
    return string;
}

char *msmerge(int nb, ...)
{
    va_list list;
    char *string = strdup("");
    char *tmp = NULL;

    va_start(list, nb);
    for (int i = 0; i < nb; i++) {
        tmp = smerge(string, va_arg(list, char *));
        free(string);
        string = strdup(tmp);
        free(tmp);
    }
    va_end(list);
    return string;
}
