/*
 * File: 120-binary_tree_is_avl.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * calculate_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of tree otherwise 0 if tree is NULL
 */

size_t calculate_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height_left = calculate_height(tree->left) + 1;
	if (tree->right != NULL)
		height_right = calculate_height(tree->right) + 1;
	if (height_left >= height_right)
		return (height_left);
	return (height_right);
}

/**
 * is_avl_helper - Check if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the binary tree to check.
 * @min: The minimum value constraint for the current subtree.
 * @max: The maximum value constraint for the current subtree.
 *
 * Return: Returns 1 if the binary tree is an AVL tree, and 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + calculate_height(tree->left) : 0;
	path_r = tree->right ? 1 + calculate_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is AVL Tree otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
