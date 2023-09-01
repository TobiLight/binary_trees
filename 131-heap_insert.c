/*
 * File: 131-heap_insert.c
 * Author: Oluwatobiloba Light
 */

#include "binary_trees.h"

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
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swtch;
	int temp, size, bit, leaves, subtree, level;

	if (root == NULL)
		return (NULL);
	if ((*root) == NULL)
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, subtree = 1; leaves >= subtree; subtree *= 2, level++)
		leaves -= subtree;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	swtch = new_node;
	for (; swtch->parent && (swtch->n > swtch->parent->n);
		 swtch = swtch->parent)
	{
		temp = swtch->n;
		swtch->n = swtch->parent->n;
		swtch->parent->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}
