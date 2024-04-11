#include "sort.h"
/**
 * swap_elements - Swap two elements of an array.
 * @a: The first element to swap.
 * @b: The second element to swap.
 */
void swap_elements(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (array[i] != array[min])
		{
			swap_elements(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
