/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"
#include "utils.h"

void destroy_mini_map_remove(void *data)
{
    mini_map_t *map = (mini_map_t *)data;

    free(map->key);
    free(map->value);
    free(map);
}

void destroy_datas_remove(void *data)
{
    lnode_t *node = (lnode_t *)data;

    dl_clear(&node, &destroy_mini_map_remove);
}

bool is_key(void *v, void *data)
{
    lnode_t *node = (lnode_t *)data;
    mini_map_t *map;
    char **info = stot((char *)v, "=");

    for (lnode_t *tmp = node; tmp != NULL; tmp = tmp->next) {
        map = (mini_map_t *)tmp->data;
        if (strcmp(map->key, info[0]) == 0 &&
            strcmp(map->value, info[1]) == 0) {
            freetab(info);
            return true;
        }
    }
    freetab(info);
    return false;
}

void papaya_remove(papaya_t *papaya, char *key, char *value)
{
    char *tmp = msmerge(3, key, "=", value);

    dl_erase(&papaya->datas, tmp, &is_key, &destroy_datas_remove);
    free(tmp);
}
