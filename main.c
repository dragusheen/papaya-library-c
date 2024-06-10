/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"

void view_datas(void *data)
{
    lnode_t *node = (lnode_t *)data;
    mini_map_t *map;

    for (lnode_t *tmp = node; tmp != NULL; tmp = tmp->next) {
        map = (mini_map_t *)tmp->data;
        printf("key: %s\n", map->key);
        printf("value: %s\n", map->value);
    }
}

int main(void)
{
    char *keys[] = {"name", "age", "gender", NULL};
    papaya_t *info = papaya_create("", ".info", keys);
    char *data1[] = {"dragusheen", "19", "male", NULL};
    char *data2[] = {"albane", "15", "female", NULL};
    char *data3[] = {"test", "-1", NULL};

    papaya_add(info, data1);
    papaya_add(info, data2);
    papaya_add(info, data3);
    dl_apply_data(info->datas, view_datas);
    printf("\n\n");
    papaya_remove(info, "name", "dragusheen");
    dl_apply_data(info->datas, view_datas);
    papaya_save(info);
    papaya_destroy(info);
}
