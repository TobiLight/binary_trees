/*
 * File: 133-heap_extract.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * max_node - Finds the maximum node in a tree.
 * @tree: The pointer to the root of the tree.
 *
 * Return: The node with the maximum value.
 */
heap_t *max_node(heap_t *tree)
{
	heap_t *curr, *left, *right;

	if (tree->left == NULL)
		return (tree);
	left = max_node(tree->left);
	if (left->n > tree->n)
		curr = left;
	else
		curr = tree;
	if (tree->right != NULL)
	{
		right = max_node(tree->right);
		if (right->n > curr->n)
			curr = right;
		else
			curr = tree;
	}
	return (curr);
}

/**
 * extract_heap - Extracts the max from the tree.
 * @tree: The pointer to the root of the tree.
 *
 * Return: nothing
 */
void extract_heap(heap_t *tree)
{
	heap_t *sub_tree_max, *right_tree_max = NULL;

	if (tree->left == NULL)
		return;
	sub_tree_max = max_node((tree)->left);
	if (tree->right != NULL)
		right_tree_max = max_node(tree->right);
	if (right_tree_max && right_tree_max->n > sub_tree_max->n)
		sub_tree_max = right_tree_max;
	tree->n = sub_tree_max->n;
	if (sub_tree_max->left == NULL)
	{
		if (sub_tree_max->parent != NULL &&
			sub_tree_max->parent->left == sub_tree_max)
			sub_tree_max->parent->left = NULL;
		if (sub_tree_max->parent != NULL &&
			sub_tree_max->parent->right == sub_tree_max)
			sub_tree_max->parent->right = NULL;
		free(sub_tree_max);
	}
	else
		extract_heap(sub_tree_max);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: The value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int value;

	if (root == NULL || *root == NULL)
		return (0);
	value = (*root)->n;
	if ((*root)->left == NULL)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}
	extract_heap(*root);
	return (value);
}
