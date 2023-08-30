/*
 * File: 14-binary_tree_balance.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor count otherwise If tree is NULL, return 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_count = 0, left_node_count = 0, right_node_count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_node_count = binary_tree_balance(tree->left) + 1;
	if (tree->right != NULL)
		right_node_count = binary_tree_balance(tree->right) + 1;

	balance_count = left_node_count - right_node_count;
	return (balance_count);
}
