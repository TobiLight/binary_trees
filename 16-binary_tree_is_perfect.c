/*
 * File: 16-binary_tree_is_perfect.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

size_t calculate_tree_height(const binary_tree_t *tree);

/**
 * calculate_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of tree otherwise 0 if tree is NULL
 */

size_t calculate_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height_left = calculate_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		height_right = calculate_tree_height(tree->right) + 1;
	if (height_left >= height_right)
		return (height_left);
	return (height_right);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if subtrees have only leaves otherwise 0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_tree, right_tree;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->left == NULL)
		return (0);

	left_tree = calculate_tree_height(tree->left);
	right_tree = calculate_tree_height(tree->right);

	if (left_tree == right_tree)
	{
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}
	return (0);
}
