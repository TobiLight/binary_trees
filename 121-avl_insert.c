/*
 * File: 121-avl_insert_helper.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * avl_insert_helper - Helper function that inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the
 *        value
 * @value: Value to store in the node to be inserted
 * @new_node: Double pointer to the root node of the AVL tree for inserting
 *            the value
 * @parent: Parent node of AVL.
 * @value: Value to be inserted in AVL Tree.
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_helper(avl_t **tree, int value, avl_t **new_node,
						 avl_t *parent)
{
	int bf;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_helper(&(*tree)->left, value, new_node,
										  *tree);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert_helper(&(*tree)->right, value,
										   new_node, *tree);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (NULL);
	bf = binary_tree_balance(*tree);
	if (bf > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (bf > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bf < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (bf < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the
 *        value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	avl_insert_helper(tree, value, &new_node, *tree);

	return (new_node);
}
