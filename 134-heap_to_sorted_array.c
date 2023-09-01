/*
 * File: 134-heap_to_sorted_array.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * heap_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree otherwise If tree is NULL, the function
 *         must return 0.
 */

size_t heap_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 1, left_tree_size = 0, right_tree_size = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_tree_size += heap_tree_size(tree->left);

	if (tree->right != NULL)
		right_tree_size += heap_tree_size(tree->right);

	tree_size += (left_tree_size + right_tree_size);
	return (tree_size);
}

/**
 * heap_to_sorted_array - M
 * @heap: h
 * @size: s
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *array = NULL;

	if (heap == NULL || !size)
		return (NULL);

	*size = heap_tree_size(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (array == NULL)
		return (NULL);

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
