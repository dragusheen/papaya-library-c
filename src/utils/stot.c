/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** network
*/

#include "papaya.h"

bool is_sep(char test, const char *sep)
{
    for (int i = 0; sep[i] != '\0'; i++)
        if (test == sep[i])
            return true;
    return false;
}

int get_rows(const char *str, const char *sep)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_sep(str[i], sep))
            count++;
    return count;
}

int get_cols(const char *str, const char *sep, int index)
{
    int count = 0;

    for (int i = index; !is_sep(str[i], sep) && str[i] != '\0'; i++)
        count++;
    return count;
}

char **stot(const char *str, const char *sep)
{
    int rows = get_rows(str, sep);
    char **tab = malloc(sizeof(char *) * (rows + 1));
    int index = 0;
    int cols = 0;

    for (int i = 0; i < rows; i++) {
        cols = get_cols(str, sep, index);
        tab[i] = malloc(cols + 1);
        tab[i][cols] = '\0';
        for (int j = 0; j < cols; j++)
            tab[i][j] = str[index + j];
        index += cols + 1;
    }
    tab[rows] = NULL;
    return tab;
}
