#include <string.h>
#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - alforithm with bubble sorting method.
 * @array: input pointer to array to be sorted.
 * @size: array size.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, cmp = 0, aux = 0;

	/* traverse the array until null */
	for (i = 0; i < (size - 1); i++)
	{
		/* We need to sort the elements from size - 1 */
		for (cmp = 0; cmp < (size - 1 - i); cmp++)
		{
			/* if the next position is not greater than current */
			if (*(array + cmp) > *(array + cmp + 1))
			{
				/* aux = next */
				aux = *(array + cmp);
				/* next = current*/
				/* current = aux */
				*(array + cmp) = *(array + cmp + 1);
				*(array + cmp + 1) = aux;
				print_array(array, size);
			}
		}
	}
}
