/*
 * File: 14-binary_tree_balance.c
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
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor count otherwise If tree is NULL, return 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = (int)calculate_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		right_height = (int)calculate_tree_height(tree->right) + 1;

	return (left_height - right_height);
}
