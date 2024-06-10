/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"
#include "utils.h"


static void *create_mini_map(void *key, void *value)
{
    mini_map_t *map = malloc(sizeof(mini_map_t));

    map->key = strdup((char *)key);
    map->value = strdup((char *)value);
    return map;
}

static papaya_t *empty_papaya(char *path, char *name)
{
    papaya_t *papaya = malloc(sizeof(papaya_t));

    papaya->path = strdup(path);
    papaya->name = strdup(name);
    papaya->keys = NULL;
    papaya->datas = NULL;
    return papaya;
}

void load_keys(papaya_t *papaya, char *line)
{
    char **keys = stot(line, ";");

    for (int i = 0; keys[i] != NULL; i++)
        dl_push_back(&papaya->keys, strdup(keys[i]));
    freetab(keys);
}

void load_datas(papaya_t *papaya, char *line)
{
    char **datas = stot(line, ";");
    lnode_t *data = NULL;
    int i = 0;

    for (lnode_t *tmp = papaya->keys; tmp != NULL; tmp = tmp->next) {
        dl_push_back(&data, create_mini_map(tmp->data, datas[i]));
        i++;
    }
    dl_push_back(&papaya->datas, data);
    freetab(datas);
}

papaya_t *load_papaya(char *path, char *name, char *filepath)
{
    char *content = read_file(filepath);
    char **lines = stot(content, "\n");
    papaya_t *papaya = empty_papaya(path, name);

    for (int i = 0; lines[i] != NULL; i++) {
        if (i == 0)
            load_keys(papaya, lines[i]);
        else
            load_datas(papaya, lines[i]);
    }
    freetab(lines);
    free(content);
    return papaya;
}

papaya_t *papaya_load(char *path, char *name)
{
    papaya_t *papaya;
    char *filepath = malloc((strlen(path) +
        strlen(name) + strlen(".papaya") + 1));

    filepath = strcat(filepath, path);
    filepath = strcat(filepath, name);
    filepath = strcat(filepath, ".papaya");
    if (access(filepath, F_OK) == -1) {
        free(filepath);
        fprintf(stderr, "Error: papaya not found\n");
        return NULL;
    }
    papaya = load_papaya(path, name, filepath);
    free(filepath);
    return papaya;
}
