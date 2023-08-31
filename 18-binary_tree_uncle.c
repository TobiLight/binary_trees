/*
 * File: 18-binary_tree_uncle.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node otherwise If node is NULL or node has no
 *         uncle, return NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;

	if (grandparent == NULL || grandparent->left == NULL ||
		grandparent->right == NULL)
		return (NULL);

	if (parent == grandparent->right)
		return (grandparent->left);

	return (grandparent->right);
}
