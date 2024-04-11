#include "sort.h"

/**
* dlistint_len - a function that returns the number
* of elements in a linked list
*@list: the list
* Return: return the len of the list
**/

size_t dlistint_len(listint_t *list)
{
	unsigned int i, len = 0;

	for (i = 0; list != NULL; i++)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 *swap_pointer - swap a node for his previous one
 *@current: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */

listint_t *swap_pointer(listint_t *current, listint_t **list)
{
    listint_t *tmp = current->prev;
    listint_t *node = current;

    tmp->next = node->next;

    if (node->next)
        node->next->prev = tmp;
    node->next = tmp;
	node->prev = tmp->prev;
	tmp->prev = node;
	if (node->prev)
		node->prev->next = node;
	else
		*list = node;
	return (node);
}

void insertion_sort_list(listint_t **list)
{
    unsigned int i, len = 0;
    listint_t *current = (*list)->next;

    if (list == NULL)
        return;

    len = dlistint_len(*list);

    for (i= 0; i < len; i++)
    {
        while ((current->prev) && (current->prev->n > current->n))
        {
            current = swap_pointer(current, list);
            print_list(*list);
        }
        i = 0;
        current = current->next;
    }

}