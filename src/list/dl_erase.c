/*
** EPITECH PROJECT, 2024
** dragusheen linked_list-library
** File description:
** library
*/

#include "dlist.h"

void dl_erase(lnode_t **li, void *ref,
    bool cmp(void *, void *), void del(void *))
{
    lnode_t *prev = NULL;
    lnode_t *curr = *li;

    while (curr != NULL) {
        if (cmp(ref, curr->data))
            break;
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        return;
    if (prev == NULL)
        *li = curr->next;
    else
        prev->next = curr->next;
    if (del != NULL)
        del(curr->data);
    free(curr);
}
