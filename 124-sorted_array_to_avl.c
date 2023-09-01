/*
 * File: 124-sorted_array_to_avl.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * sa_to_avl_helper - Helper function to build an AVL tree from an array
 * @array: Pointer to the first element in the array
 * @root: Double pointer to the root node of the subtree.
 * @low: Lower bound index
 * @high: Upper bound index
 */

void sa_to_avl_helper(int *array, avl_t **root, size_t low, size_t high)
{
	avl_t *new_node = NULL;
	size_t middle;

	if (high - low > 1)
	{
		middle = (high - low) / 2 + low;
		new_node = binary_tree_node(*root, array[middle]);
		if (array[middle] < (*root)->n)
			(*root)->left = new_node;
		else if (array[middle] > (*root)->n)
			(*root)->right = new_node;
		sa_to_avl_helper(array, &new_node, low, middle);
		sa_to_avl_helper(array, &new_node, middle, high);
	}
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on
 *         failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (array == NULL)
		return (NULL);
	middle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[middle]);

	sa_to_avl_helper(array, &tree, -1, middle);
	sa_to_avl_helper(array, &tree, middle, size);

	return (tree);
}
