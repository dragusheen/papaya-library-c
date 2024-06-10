/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"

int tablen(char **tab)
{
    int len = 0;

    for (int i = 0; tab[i] != NULL; i++)
        len++;
    return len;
}

char **duptab(char **tab)
{
    int len = tablen(tab);
    char **new_tab = malloc(sizeof(char *) * (len + 1));

    if (new_tab == NULL)
        return NULL;
    for (int i = 0; tab[i] != NULL; i++)
        new_tab[i] = strdup(tab[i]);
    new_tab[len] = NULL;
    return new_tab;
}

void freetab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
