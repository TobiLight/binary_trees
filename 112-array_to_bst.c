/*
 * File: 112-array_to_bst.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{

	unsigned int i;
	bst_t *root;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	printf("root: %d\n", root->n);
	return (root);
}