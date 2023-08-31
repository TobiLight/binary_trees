/*
 * File: 100-binary_trees_ancestor.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

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
	const binary_tree_t *ancestor = first;

	if (first == NULL || second == NULL)
		return (NULL);

	while (ancestor != NULL)
	{
		while (second != NULL)
		{
			if (ancestor == second)
				return ((binary_tree_t *)ancestor);
			if (ancestor->parent == second)
				return ((binary_tree_t *)ancestor->parent);

			second = second->parent;
		}
		ancestor = ancestor->parent;
	}

	return (NULL);
}
