/*
 * File: 132-array_to_heap.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL
 *         on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i = 0;
	heap_t *root = NULL;

	while (i < size;)
	{
		heap_insert(&root, array[i]);
		i++;
	}
	return (root);
}
