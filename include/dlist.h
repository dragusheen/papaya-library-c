/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** network
*/

#ifndef D_LIST_H_
    #define D_LIST_H_

    /*  ---- INCLUDE ----*/

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>


    /*  ---- STRUCTURE ----*/

typedef struct linked_list_node {
    void *data;
    struct linked_list_node *next;
} lnode_t;


    /*  ---- FUNCTION ----*/

/**
 * @brief Iterates through the linked list and applies the given function to
 * the data of each element. Do nothing if the list is empty or if the given
 * function is NULL.
 *
 * @param head A pointer to the head of the linked list.
 * @param func A function that takes a void pointer as an argument and returns
 * void.
 *
 * @warning The function assumes that the given list is valid with a NULL at
 * the end. If this is not the case, the behavior is undefined.
*/
void dl_apply_data(lnode_t *head, void func(void *));

/**
 * @brief Iterates through the linked list and applies the given function to
 * the node. Do nothing if the list is empty or if the given function is NULL.
 *
 * @param head A pointer to the head of the linked list.
 * @param func A function that takes a lnode_t pointer as an argument and
 * returns void.
 *
 * @warning The function assumes that the given list is valid with a NULL at
 * the end. If this is not the case, the behavior is undefined.
*/
void dl_apply_node(lnode_t *head, void func(lnode_t *));

/**
 * @brief Clears the linked list and send the data of each element to the
 * given function.
 *
 * @param head A pointer to the head of the linked list.
 * @param free_func A function that takes a void pointer as an argument
 * and returns void. Or NULL if no function is needed.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
*/
void dl_clear(lnode_t **head, void free_func(void *));

/**
 * @brief Checks if the linked list is empty.
 *
 * @param head A pointer to the head of the linked list.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 *
 * @return Return true if the list is empty, false otherwise.
*/
bool dl_empty(lnode_t *head);

/**
 * @brief Erases an element from the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param ref A comparative value to find the element to erase.
 * @param cmp A function that takes two void pointers as arguments and returns
 * a boolean. The first argument is the given ref and the second is the data
 * of the current element.
 * @param del A function that takes a void pointer as an argument and
 * returns void. Or NULL if no function is needed.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
*/
void dl_erase(lnode_t **head, void *ref,
    bool cmp(void *, void *), void del(void *));

/**
 * @brief Extracts an element from the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param ref A comparative value to find the element to extract.
 * @param cmp A function that takes two void pointers as arguments and returns
 * a boolean. The first argument is the given ref and the second is the data
 * of the current element.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 *
 * @return Return the data of the extracted element. NULL if the element
 * was not found or in case of error
*/
void *dl_extract(lnode_t **head, void *ref, bool cmp(void *, void *));

/**
 * @brief Finds the data of an element in the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param ref A comparative value to find the element.
 * @param cmp A function that takes two void pointers as arguments and returns
 * a boolean. The first argument is the given ref and the second is the data
 * of the current element.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 *
 * @return Return the data of the found element. NULL if the element was not
 * found or in case of error.
*/
void *dl_find_data(lnode_t *head, void *ref, bool cmp(void *, void *));

/**
 * @brief Finds an element in the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param ref A comparative value to find the element.
 * @param cmp A function that takes two void pointers as arguments and returns
 * a boolean. The first argument is the given ref and the second is the data
 * of the current element.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 *
 * @return Return founded element. NULL if the element was not found or in
 * case of error.
*/
lnode_t *dl_find_node(lnode_t *head, void *ref, bool cmp(void *, void *));

/**
 * @brief Inserts a new element in the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param data The data to be added to the list.
 * @param cmp A function that takes two void pointers as arguments and returns
 * a boolean. The first argument is the given data and the second is the data
 * of the current element.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
*/
void dl_insert(lnode_t **head, void *data, bool cmp(void *, void *));

/**
 * @brief Returns the length of the linked list.
 *
 * @param head A pointer to the head of the linked list.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 *
 * @return Return the length of the list. 0 if the list is empty or in case
 * of error.
*/
int dl_length(lnode_t *head);

/**
 * @brief Removes the last element of the linked list and returns its data.
 *
 * @param head A pointer to the head of the linked list.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 *
 * @return Return the data of the first element of the list. NULL if the list
 * is empty or in case of error.
*/
void *dl_pop_back(lnode_t **head);

/**
 * @brief Removes the first element of the linked list and returns its data.
 *
 * @param head A pointer to the head of the linked list.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 *
 * @return Return the data of the first element of the list. NULL if the list
 * is empty or in case of error.
*/
void *dl_pop_front(lnode_t **head);

/**
 * @brief Adds a new element at the end of the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param value The value to be added to the list.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 */
void dl_push_back(lnode_t **head, void *data);

/**
 * @brief Adds a new element at the beginning of the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param value The value to be added to the list.
 *
 * @warning The function assumes that the given list is valid with a NULL
 * at the end. If this is not the case, the behavior is undefined.
 */
void dl_push_front(lnode_t **head, void *data);


#endif /* D_LIST_H_ */
