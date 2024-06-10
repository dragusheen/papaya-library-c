/*
** EPITECH PROJECT, 2024
** dragusheen linked_list-library
** File description:
** library
*/

#include "dlist.h"

void dl_clear(lnode_t **head, void free_func(void *))
{
    lnode_t *tmp;

    while (*head) {
        tmp = (*head)->next;
        if (free_func != NULL)
            free_func((*head)->data);
        free(*head);
        *head = tmp;
    }
}
