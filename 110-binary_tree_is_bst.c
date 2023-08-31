/*
 * File: 110-binary_tree_is_bst.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

int binary_tree_is_bst_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst_helper - Helper function to check if a binary tree is a
 *                             valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, otherwise 0.
 */
int binary_tree_is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);
	return (binary_tree_is_bst_helper(tree->left, min, tree->n - 1) &&
			binary_tree_is_bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_is_bst_helper(tree, INT_MIN, INT_MAX));
}
