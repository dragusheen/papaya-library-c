/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** network
*/

#ifndef UTILS_H_
    #define UTILS_H_

    /*  ---- FUNCTION ----*/

void freetab(char **tab);

int tablen(char **tab);

char *read_file(char *filepath);
char *smerge(char *string1, char *string2);
char *msmerge(int nb, ...);

char **duptab(char **tab);
char **stot(const char *str, const char *sep);


#endif /* UTILS_H_ */
