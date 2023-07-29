#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
        list_t *new;
        unsigned int len = 0;

        while (str[len])
                len++;

        new = malloc(sizeof(list_t));
        if (!new)
                return (NULL);

        new->str = strdup(str);
        new->len = len;
        new->next = (*head);
        (*head) = new;

        return (*head);
}

root@69b778e79074:~/alx-low_level_programming/0x12-singly_linked_lists# cat^C
root@69b778e79074:~/alx-low_level_programming/0x12-singly_linked_lists# cat 4-free_list.c
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
        list_t *temp;

        while (head)
        {
                temp = head->next;
                free(head->str);
                free(head);
                head = temp;
        }
}
