/*
** EPITECH PROJECT, 2024
** dragusheen linked_list-library
** File description:
** library
*/

#include "dlist.h"

void insert_in_list(lnode_t **head, void *data,
    bool cmp(void *, void *), lnode_t *new_node)
{
    lnode_t *tmp = *head;

    if (cmp(data, (*head)->data)) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next) {
        if (cmp(data, tmp->next->data)) {
            new_node->next = tmp->next;
            tmp->next = new_node;
            return;
        }
    }
    tmp->next = new_node;
}

void dl_insert(lnode_t **head, void *data, bool cmp(void *, void *))
{
    lnode_t *new_node = malloc(sizeof(lnode_t));

    if (new_node == NULL)
        return;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    insert_in_list(head, data, cmp, new_node);
}
