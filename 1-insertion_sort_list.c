#include "sort.h"

/**
 * swap_nodes - funciton that swaps nodes from a list
 *
 * @node_a: firs node.
 * @node_b: second node.
 * @list: linked list.
 */
void swap_nodes(listint_t **node_a, listint_t **node_b, listint_t **list)
{
	/* if nodes are not the firs/end of the list*/
	if ((*node_b)->next != NULL && (*node_a)->prev != NULL)
	{
		(*node_a)->prev->next = *node_b;
		(*node_b)->next->prev = *node_a;
	}

	/* if second node is the last node of the list */
	else if ((*node_b)->next == NULL && (*node_a)->prev !=NULL)
		(*node_a)->prev->next = *node_b;

	/* if first node is the first node of the list*/
	else if ((*node_a)->prev == NULL && (*node_b)->next !=NULL)
	{
		(*node_b)->next->prev = *node_a;
		*list = *node_b;
	}
	/* last condition for two nodes */
	else if ((*node_a)->prev == NULL && (*node_b)->next == NULL)
		*list = *node_b;

	/* normal scenario linking */
	/*ascending order linking */
	(*node_a)->next = (*node_b)->next;
	(*node_b)->next = *node_a;

	/* descending order linking */
	(*node_b)->prev = (*node_a)->prev;
	(*node_a)->prev = *node_b;
}

/**
 * insertion_sort_list - Sort by insertion.
 *
 * @list: Linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	/* (*(*list)).member this algo will manipulate the list */
	listint_t *ref_ptr, *current_ptr, *next_ptr; /* ptrs (*) must be modifiable */

	/* edge cases */

	/* compatible pointer type initialization */
	ref_ptr = *list;
	/* traverse the list with the ref ptr */
	while (ref_ptr->next)
	{
		current_ptr = ref_ptr;
		next_ptr = (*ref_ptr).next;
		if (ref_ptr->n > next_ptr->n)
		{
			/* swap the nodes */
			swap_nodes(&current_ptr, &next_ptr, list);
			print_list(*list);
			/* reset the loop */
			ref_ptr = *list;
		}
		/* otherwise, next node*/
		else
			ref_ptr = (*ref_ptr).next;
	}
}
