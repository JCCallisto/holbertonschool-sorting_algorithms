#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)

{
	listint_t *current, *next_node, *insert_pos;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;
		insert_pos = current->prev;

		/* Find the correct position to insert current node */
		while (insert_pos != NULL && insert_pos->n > current->n)
		{
			insert_pos = insert_pos->prev;
		}

		/* If current is already in correct position */
		if (insert_pos == current->prev)
		{
			current = next_node;
			continue;
		}

		/* Remove current from its current position */
		if (current->next != NULL)
			current->next->prev = current->prev;
		current->prev->next = current->next;

		/* Insert current after insert_pos */
		if (insert_pos == NULL)
		{
			/* Insert at the beginning */
			current->prev = NULL;
			current->next = *list;
			(*list)->prev = current;
			*list = current;
		}
		else
		{
			/* Insert after insert_pos */
			current->prev = insert_pos;
			current->next = insert_pos->next;
			if (insert_pos->next != NULL)
				insert_pos->next->prev = current;
			insert_pos->next = current;
		}

		/* Print the list after each swap */
		print_list(*list);

		current = next_node;
	}
}
