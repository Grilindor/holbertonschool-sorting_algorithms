#include "sort.h"

/**
 *swap_pointer - swap a node for his previous one
 *@current: node
 *@list: Dobule linked list to sort
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

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 * Return: void
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL)
		return;


	while (current)
	{
		while ((current->prev) && (current->prev->n > current->n))
		{
			current = swap_pointer(current, list);
			print_list(*list);
		}
		current = current->next;
	}
}
