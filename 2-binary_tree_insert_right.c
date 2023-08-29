/*
 * File: 2-binary_tree_insert_right.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another
 *                            node.
 * @parent: Pointer to the parent node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is
 *         NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary_tree;

	if (parent == NULL)
		return (NULL);

	new_binary_tree = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (new_binary_tree == NULL)
		return (NULL);

	new_binary_tree->parent = parent;
	new_binary_tree->n = value;
	new_binary_tree->right = NULL;
	new_binary_tree->left = NULL;

	if (parent->right != NULL)
	{
		new_binary_tree->right = parent->right;
		parent->right->parent = new_binary_tree;
	}

	parent->right = new_binary_tree;
	return (new_binary_tree);
}
