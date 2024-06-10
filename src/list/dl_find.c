/*
** EPITECH PROJECT, 2024
** dragusheen linked_list-library
** File description:
** library
*/

#include "dlist.h"

void *dl_find_data(lnode_t *head, void *ref, bool cmp(void *, void *))
{
    for (; head != NULL; head = head->next)
        if (cmp(ref, head->data))
            return head->data;
    return NULL;
}

lnode_t *dl_find_node(lnode_t *head, void *ref, bool cmp(void *, void *))
{
    for (; head != NULL; head = head->next)
        if (cmp(ref, head->data))
            return head;
    return NULL;
}
