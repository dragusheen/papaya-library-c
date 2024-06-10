/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"

void destroy_mini_map(void *data)
{
    mini_map_t *map = (mini_map_t *)data;

    free(map->key);
    free(map->value);
    free(map);
}

void destroy_datas(void *data)
{
    lnode_t *node = (lnode_t *)data;

    dl_clear(&node, &destroy_mini_map);
}

void papaya_destroy(papaya_t *papaya)
{
    if (papaya->path)
        free(papaya->path);
    if (papaya->name)
        free(papaya->name);
    if (papaya->keys)
        dl_clear(&papaya->keys, &free);
    if (papaya->datas)
        dl_clear(&papaya->datas, &destroy_datas);
    free(papaya);
}
