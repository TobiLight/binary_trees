/*
 * File: 0-binary_tree_node.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_node - Ceates a new binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary_tree;

	new_binary_tree = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (new_binary_tree == NULL)
		return (NULL);

	new_binary_tree->parent = parent;
	new_binary_tree->n = value;
	new_binary_tree->left = NULL;
	new_binary_tree->right = NULL;

	return (new_binary_tree);
}
