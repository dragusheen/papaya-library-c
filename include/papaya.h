/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** network
*/

#ifndef PAPAYA_H_
    #define PAPAYA_H_

    /*  ---- INCLUDE ----*/

    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdarg.h>

    #include "dlist.h"


    /*  ---- STRUCTURE ----*/

typedef struct papaya_structure {
    char *path;
    char *name;
    lnode_t *keys;
    lnode_t *datas;
} papaya_t;

typedef struct mini_map_structure {
    char *key;
    char *value;
} mini_map_t;


    /*  ---- FUNCTION ----*/

/**
 * @brief Add a data to a papaya object
 *
 * @param papaya The papaya to add the data
 * @param data The data to add
 *
 * @warning The data array must be NULL terminated.
*/
void papaya_add(papaya_t *papaya, char **data);

/**
 * @brief Create a papaya object
 *
 * @param path The path for the papaya
 * @param name The name of the papaya
 * @param keys The keys for the datas
 *
 * @warning The keys array must be NULL terminated.
 *
 * @return papaya_t* The created papaya
*/
papaya_t *papaya_create(char *path, char *name, char **keys);

/**
 * @brief Delete a papaya object
 *
 * @param papaya The papaya to delete
*/
void papaya_destroy(papaya_t *papaya);

/**
 * @brief Load a papaya object
 *
 * @param path The path of the papaya
 * @param name The name of the papaya
 *
 * @return papaya_t* The loaded papaya
*/
papaya_t *papaya_load(char *path, char *name);

/**
 * @brief Remove a data from a papaya object
 *
 * @param papaya The papaya to remove the data
 * @param key The key of the data
 * @param value The value of the data
*/
void papaya_remove(papaya_t *papaya, char *key, char *value);

/**
 * @brief Save a papaya object
 *
 * @param papaya The papaya to save
*/
void papaya_save(papaya_t *papaya);


#endif /* PAPAYA_H_ */
