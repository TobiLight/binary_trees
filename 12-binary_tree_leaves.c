/*
 * File: 12-binary_tree_leaves.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: Pointer to the root node of the tree to count the number of leaves.
 *
 * Return: Number of leaves otherwise if tree is NULL, the function must
 *         return 0
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_count = 0;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->right)
		leaves_count += 2;
	else
		leaves_count += 1;

	return (leaves_count);
}
