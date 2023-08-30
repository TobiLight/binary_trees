/*
 * File: 13-binary_tree_nodes.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: Pointer to the root node of the tree to count the number of nodes.
 *
 * Return: Number of nodes otherwise If tree is NULL, the function must
 *         return 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_node_count = 0, right_node_count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		left_node_count += binary_tree_nodes(tree->left);
		right_node_count += binary_tree_nodes(tree->right);
	}
	else
		return (left_node_count + right_node_count);

	return (left_node_count + right_node_count + 1);
}
