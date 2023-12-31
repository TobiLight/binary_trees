/*
 * File: 102-binary_tree_is_complete.c
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

/**
 * binary_tree_is_complete_helper - Helper function to check if a binary
 *                                  tree is complete
 * @tree: Pointer to the root node of the tree to check.
 * @size: Number of nodes in the tree
 * @idx: Index of the node
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete_helper(const binary_tree_t *tree, size_t size,
								   size_t idx)
{
	if (tree == NULL)
		return (1);

	if (size <= idx)
		return (0);

	return (binary_tree_is_complete_helper(tree->left, size, 2 * idx + 1) &&
			binary_tree_is_complete_helper(tree->right, size, 2 * idx + 2));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_size;

	if (tree == NULL)
		return (0);

	tree_size = binary_tree_size(tree);

	return (binary_tree_is_complete_helper(tree, tree_size, 0));
}
