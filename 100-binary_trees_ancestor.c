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
		if (first == second)
			return ((binary_tree_t *)first);

		if (first == second->parent)
			return ((binary_tree_t *)first);

		if (first->parent == second->parent)
			return ((binary_tree_t *)first->parent);

		if (first->parent == second)
			return ((binary_tree_t *)first->parent);

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
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node to calculate the depth of
 *
 * Return: depth of the node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
