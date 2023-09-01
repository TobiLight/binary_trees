/*
 * File: 133-heap_extract.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of tree otherwise 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height_left = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		height_right = binary_tree_height(tree->right) + 1;
	if (height_left >= height_right)
		return (height_left);
	return (height_right);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree otherwise If tree is NULL, the function
 *         must return 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 1, left_tree_size = 0, right_tree_size = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_tree_size += binary_tree_size(tree->left);

	if (tree->right != NULL)
		right_tree_size += binary_tree_size(tree->right);

	tree_size += (left_tree_size + right_tree_size);
	return (tree_size);
}

/**
 * preorder_traversal - goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @node: Node in the tree
 * @height: Tree height
 *
 * Return: nothing
 */
void preorder_traversal(heap_t *tree, heap_t **node, size_t height)
{
	if (tree == NULL)
		return;

	if (!height)
		*node = tree;
	height--;

	preorder_traversal(tree->left, node, height);
	preorder_traversal(tree->right, node, height);
}
/**
 * heap_tree - Heaps a max binary heap
 * @root: Pointer to the binary heap
 *
 * Return: nothing
 */
void heap_tree(heap_t *root)
{
	int value;
	heap_t *temp1, *temp2;

	if (root == NULL)
		return;

	temp1 = root;

	while (1)
	{
		if (temp1->left == NULL)
			break;
		if (temp1->right == NULL)
			temp2 = temp1->left;
		else
		{
			if (temp1->right->n < temp1->left->n)
				temp2 = temp1->right;
			else
				temp2 = temp1->left;
		}
		if (temp1->n > temp2->n)
			break;
		value = temp1->n;
		temp1->n = temp2->n;
		temp2->n = value;
		temp1 = temp2;
	}
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
	heap_t *heap_r, *node;

	if (root == NULL || *root == NULL)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	preorder_traversal(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->left != NULL)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	free(node);
	heap_tree(heap_r);
	*root = heap_r;
	return (value);
}
