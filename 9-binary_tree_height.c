/*
 * File: 9-binary_tree_height.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of tree otherwise 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height_left = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		height_right = binary_tree_height(tree->right) + 1;
	if (height_left >= height_right)
		return (height_left);
	return (height_right);
}
