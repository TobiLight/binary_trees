/*
 * File: 100-binary_trees_ancestor.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * is_ancestor - Helper function to check if two nodes have the same ancestor
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the ancestor of both nodes.
 */
binary_tree_t *is_ancestor(const binary_tree_t *first,
						   const binary_tree_t *second);

binary_tree_t *is_ancestor(const binary_tree_t *first,
						   const binary_tree_t *second)
{
	while (second != NULL)
	{
		if (first->parent == second->parent)
			return ((binary_tree_t *)first->parent);

		if (first == second->parent)
			return ((binary_tree_t *)second->parent);
		second = second->parent;
	}
	return (NULL);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 *         otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	while (first != NULL)
	{
		ancestor = is_ancestor(first, second);
		if (ancestor)
			return (ancestor);
		first = first->parent;
	}

	return (ancestor);
}
