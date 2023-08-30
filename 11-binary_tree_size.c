/*
 * File: 11-binary_tree_size.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree otherwise If tree is NULL, the function
 *         must return 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 1, left_tree_size = 0, right_tree_size = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_tree_size += binary_tree_size(tree->left);

	if (tree->right != NULL)
		right_tree_size += binary_tree_size(tree->right);

	tree_size += (left_tree_size + right_tree_size);
	return (tree_size);
}
