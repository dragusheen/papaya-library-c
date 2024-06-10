/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"
#include "utils.h"

papaya_t *papaya_create(char *path, char *name, char **keys)
{
    papaya_t *papaya = malloc(sizeof(papaya_t));

    if (papaya == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }
    papaya->path = strdup(path);
    papaya->name = strdup(name);
    papaya->keys = NULL;
    for (int i = 0; keys[i] != NULL; i++)
        dl_push_back(&papaya->keys, strdup(keys[i]));
    papaya->datas = NULL;
    return papaya;
}
