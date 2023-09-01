/*
 * File: 123-avl_remove.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

int bst_successor(bst_t *node);
int bst_replace_with_successor(bst_t *root);
int bst_remove_node(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);
void avl_balance(avl_t **tree);
int avl_successor(avl_t *node);
int avl_remove_node(avl_t *node);

/**
 * bst_successor - Gets the next successor
 * @node: Tree to check
 *
 * Return: Minimum value of the tree.
 */
int bst_successor(bst_t *node)
{
	int left;

	if (node == NULL)
		return (0);

	left = bst_successor(node->left);
	return ((left == 0) ? node->n : left);
}

/**
 * bst_replace_with_successor - Helper function to get the next successor using
 *                           the minimum value in the right subtree, and then
 *                           replace the node value for this successor
 * @root: Node with two children.
 *
 * Return: Value
 */
int bst_replace_with_successor(bst_t *root)
{
	int new_value = 0;

	new_value = bst_successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 * bst_remove_node - Helper function to remove a node
 * @node: Node to remove
 *
 * Return: 0 if no children otherwise other value.
 */

int bst_remove_node(bst_t *node)
{
	if (node->left == NULL && node->right == NULL)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((node->left == NULL && node->right) ||
			 (node->right == NULL && node->left))
	{
		if (node->left == NULL)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (node->right == NULL)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
		return (bst_replace_with_successor(node));
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the desired
 *         value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = bst_remove_node(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_balance - Measures the balance of an AVL Tree.
 * @tree: Double pointer to the root node of the tree to measure the balance
 *        factor.
 *
 * Return: Balance factor count otherwise If tree is NULL, return 0.
 */
void avl_balance(avl_t **tree)
{
	int bf;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	avl_balance(&(*tree)->left);
	avl_balance(&(*tree)->right);
	bf = binary_tree_balance((const binary_tree_t *)*tree);
	if (bf > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bf < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * avl_successor - Gets the next successor
 * @node: Tree to check
 *
 * Return: Minimum value of the tree.
 */
int avl_successor(avl_t *node)
{
	int left;

	if (node == NULL)
		return (0);

	left = avl_successor(node->left);
	return ((left == 0) ? node->n : left);
}

/**
 * avl_remove_node - Helper function to remove a node
 * @node: Node to remove
 *
 * Return: 0 if no children otherwise other value.
 */

int avl_remove_node(avl_t *node)
{
	int new_value = 0;

	if (node->left == NULL && node->right == NULL)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((node->left == NULL && node->right) ||
			 (node->right == NULL && node->left))
	{
		if (node->left == NULL)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (node->right == NULL)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
	{
		new_value = avl_successor(node->right);
		node->n = new_value;
		return (new_value);
	}
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the
 *         desired value, and after rebalancing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node = (avl_t *)bst_remove((bst_t *)root, value);

	if (node == NULL)
		return (NULL);
	avl_balance(&node);
	return (node);
}
