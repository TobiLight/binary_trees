/*
 * File: 113-bst_search.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree.
 *
 * Return: Pointer to the node containing a value equals to value otherwise
 *         NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node;

	if (tree == NULL)
		return (NULL);

	node = (bst_t *)tree;
	while (node)
	{

		if (value == node->n)
			return (node);
		else if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}

	return (NULL);
}
