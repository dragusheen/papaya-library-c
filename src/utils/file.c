/*
** EPITECH PROJECT, 2024
** dragusheen papaya
** File description:
** library
*/

#include "papaya.h"

char *read_file(char *filepath)
{
    struct stat file;
    int fd;
    int size;
    char *str;

    stat(filepath, &file);
    size = file.st_size + 1;
    str = (char *)malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    fd = open(filepath, O_RDONLY);
    read(fd, str, size);
    return str;
}
