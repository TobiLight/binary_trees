/*
 * File: 114-bst_remove.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * bst_min_value - Find the minimum value in a Binary Search Tree.
 * @node: A pointer to the root node of the BST (or a subtree).
 *
 * Return: The minimum value found in the BST. If the tree is empty or
 *         the input node is NULL, 0 is returned.
 */
int bst_min_value(bst_t *node)
{
	int left = 0;
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		left = bst_min_value(node->left);
		if (left == 0)
		{
			return node->n;
		}
		return left;
	}
}

/**
 * bst_remove - Remove a node with a specific value from a Binary Search Tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to be removed from the BST.
 *
 * Return: A pointer to the root node of the BST after removal.
 *         If the value to be removed is not found, the original
 *         root node is returned.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int new_value = 0;

	if (root == NULL)
	{
		return (NULL);
	}
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;
			free(root);
			return (temp);
		}
		new_value = bst_min_value(root->right);
		root->n = new_value;
		root->right = bst_remove(root->right, new_value);
	}
	return (root);
}
