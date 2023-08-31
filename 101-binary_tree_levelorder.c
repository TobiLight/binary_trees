/*
 * File: 101-binary_tree_levelorder.c
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
 * binary_tree_lo_helper - Helper function that goes through a binary tree
 *                         using post-order traverse
 * @tree: Pointer to the root node of the tree to traverse.
 * @level: Level of the tree.
 * @func: Pointer to a function to call for each node.
 */

void binary_tree_lo_helper(const binary_tree_t *tree, size_t level,
						   void (*func)(int))
{
	if (level == 1)
		func(tree->n);
	else
	{
		binary_tree_lo_helper(tree->left, level - 1, func);
		binary_tree_lo_helper(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *                          traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 *
 * Return: nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_height, i;

	if (tree == NULL || func == NULL)
		return;

	tree_height = calculate_height(tree) + 1;

	for (i = 1; i <= tree_height; i++)
		binary_tree_lo_helper(tree, i, func);
}
