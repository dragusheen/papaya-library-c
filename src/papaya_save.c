/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"
#include "utils.h"

void write_semicolon(int fd, lnode_t *data)
{
    if (data->next != NULL)
        write(fd, ";", 1);
}

void write_keys(int fd, lnode_t *keys)
{
    char *key;

    for (lnode_t *node = keys; node != NULL; node = node->next) {
        key = (char *)node->data;
        write(fd, key, strlen(key));
        write_semicolon(fd, node);
    }
    write(fd, "\n", 1);
}

void write_datas(int fd, lnode_t *datas)
{
    lnode_t *data;
    mini_map_t *map;

    for (lnode_t *node = datas; node != NULL; node = node->next) {
        data = node->data;
        for (lnode_t *tmp = data; tmp != NULL; tmp = tmp->next) {
            map = (mini_map_t *)tmp->data;
            write(fd, map->value, strlen(map->value));
            write_semicolon(fd, tmp);
        }
        if (node->next != NULL)
            write(fd, "\n", 1);
    }
}

void saving_content(papaya_t *papaya)
{
    char *filepath = msmerge(3, papaya->path, papaya->name, ".papaya");
    int fd = open(filepath, O_CREAT | O_TRUNC | O_RDWR, 0644);

    if (fd == -1) {
        fprintf(stderr, "Error: open failed\n");
        return;
    }
    write_keys(fd, papaya->keys);
    write_datas(fd, papaya->datas);
    close(fd);
    free(filepath);
}

void papaya_save(papaya_t *papaya)
{
    if (papaya->keys == NULL || papaya->datas == NULL)
        return;
    saving_content(papaya);
}
