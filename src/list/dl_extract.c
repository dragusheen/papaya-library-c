/*
** EPITECH PROJECT, 2024
** dragusheen linked_list-library
** File description:
** library
*/

#include "dlist.h"

void *dl_extract(lnode_t **head, void *ref, bool cmp(void *, void *))
{
    lnode_t *prev = NULL;
    lnode_t *curr = *head;
    void *data;

    while (curr != NULL) {
        if (cmp(ref, curr->data))
            break;
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        return NULL;
    if (prev == NULL)
        *head = curr->next;
    else
        prev->next = curr->next;
    data = curr->data;
    free(curr);
    return data;
}
