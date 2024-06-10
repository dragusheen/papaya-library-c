/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"
#include "utils.h"

void *create_mini_map(void *key, void *value)
{
    mini_map_t *map = (mini_map_t *)malloc(sizeof(mini_map_t));

    map->key = strdup((char *)key);
    map->value = strdup((char *)value);
    return map;
}

void add_infos(papaya_t *papaya, char **datas)
{
    lnode_t *node = NULL;
    int i = 0;

    for (lnode_t *tmp = papaya->keys; tmp != NULL; tmp = tmp->next) {
        dl_push_back(&node, create_mini_map(tmp->data, datas[i]));
        i++;
    }
    dl_push_back(&papaya->datas, node);
}

void papaya_add(papaya_t *papaya, char **datas)
{
    if (tablen(datas) != dl_length(papaya->keys)) {
        fprintf(stderr, "Error: invalid number of datas\n");
        return;
    }
    add_infos(papaya, datas);
}
