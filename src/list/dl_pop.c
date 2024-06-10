/*
** EPITECH PROJECT, 2024
** dragusheen linked_list-library
** File description:
** library
*/

#include "dlist.h"

void *dl_pop_back(lnode_t **head)
{
    lnode_t *curr = *head;
    lnode_t *prev = NULL;
    void *data;

    if (head == NULL || *head == NULL)
        return NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    data = curr->data;
    if (prev != NULL)
        prev->next = NULL;
    else
        *head = NULL;
    free(curr);
    return data;
}

void *dl_pop_front(lnode_t **head)
{
    void *data;
    lnode_t *tmp;

    if (head == NULL || *head == NULL)
        return NULL;
    tmp = (*head)->next;
    data = (*head)->data;
    free(*head);
    *head = tmp;
    return data;
}
