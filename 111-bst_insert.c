/*
 * File: 111-bst_insert.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp, *new_node, *node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	temp = *tree;
	while (temp != NULL)
	{
		node = temp;
		if (value == temp->n)
			return (NULL);
		if (value > temp->n)
			temp = temp->right;
		else
			temp = temp->left;
	}

	new_node = binary_tree_node(NULL, value);

	if (node == NULL)
		node = new_node;
	if (value < node->n)
	{
		node->left = new_node;
		new_node->parent = node;
	}
	else
	{
		node->right = new_node;
		new_node->parent = node;
	}
	return (new_node);
}
