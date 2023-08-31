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
	if (first == NULL || second == NULL)
		return (NULL);

	if (first->parent == NULL || second->parent == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	while (second != NULL)
	{
		if (first == second->parent)
			return ((binary_tree_t *)first);
		if (first->parent == second->parent)
			return ((binary_tree_t *)first->parent);
		second = second->parent;
	}

	return (NULL);
}
