# 0x1D. C - Binary trees

A binary tree is a type of data structure where each parent can have at most 2 children. It consists of nodes where each node contains a data item and the address of its left and right children.

- [Description](#description)
- [General Information](#general-information)
- [Compilation](#compilation)
- [Coding style](#coding-style)
- [Usage](#usage)
- [Files](#files)
- [More Info](#more-info)
- [Tasks](#tasks)
- [Author](#author)

## Description

Binary trees are hierarchical structures where each node has at most two children, typically referred to as the "left" child and the "right" child. They are widely used for tasks such as efficient searching, sorting, and organizing data. In this project, we will learn how to work with binary trees, understand their properties, and implement various functions to manipulate and traverse them.

## General Information

- **Editors**: vi, vim, emacs
- **Compilation**: Ubuntu 20.04 LTS using gcc with flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- **File Endings**: All files should end with a newline
- **README**: A README.md file is mandatory and should be placed at the root of the project folder
- **Coding Style**: Code should adhere to the Betty style. Use betty-style.pl and betty-doc.pl for checking
- **Global Variables**: Avoid using global variables
- **Function Limit**: Limit of 5 functions per file
- **Standard Library**: Allowed
- **Main Files**: You can use provided main.c files for testing, but you don't need to push them to your repository
- **Prototypes**: Prototypes of all functions should be included in the header file binary_trees.h
- **Header File**: Don't forget to push your header file with include guards

## Compilation

To compile your code, use the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

## Coding Style

Adhere to the Betty style which provides guidelines for clean and readable code. Use betty-style.pl and betty-doc.pl for checking.

## Usage

You can use the provided main.c files to test your functions, but they are not required to be pushed to your repository.

## Files

Here's a quick overview of the files you'll encounter in this project:

- **binary_trees.h**: Header file containing prototypes of functions to be implemented.
- **Other .c files**: These files will contain your function implementations related to binary trees.

## More Info

### Data structures

Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

### Basic Binary Tree

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### Binary Search Tree

```
typedef struct binary_tree_s bst_t;
```

### AVL Tree

```
typedef struct binary_tree_s avl_t;
```

### Max Binary Heap

```
typedef struct binary_tree_s heap_t;
```

## Tasks

* **[0-binary_tree_node.c](./0-binary_tree_node.c)** - Write a function that creates a binary tree node
  - Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);``
  - Where `parent` is a pointer to the parent node of the node to create
  - And `value` is the value to put in the new node
  - When created, a node does not have any child
  - Your function must return a pointer to the new node, or `NULL` on failure

* **[1-binary_tree_insert_left.c](./1-binary_tree_insert_left.c)** - Write a function that inserts a node as the left-child of another node
    - Prototype: `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`
    - Where `parent` is a pointer to the node to insert the left-child in
    - And `value` is the value to store in the new node
    - Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
    - If `parent` already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.

* **[2-binary_tree_insert_right.c](./2-binary_tree_insert_right.c)** - Write a function that inserts a node as the right-child of another node
    - Prototype: `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`
    - Where `parent` is a pointer to the node to insert the right-child in
    - And `value` is the value to store in the new node
    - Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
    - If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.

* **[3-binary_tree_delete.c](./3-binary_tree_delete.c)** - Write a function that deletes an entire binary tree
    - Prototype: `void binary_tree_delete(binary_tree_t *tree);`
    - Where `tree` is a pointer to the root node of the tree to delete
    - If `tree` is `NULL`, do nothing

* **[4-binary_tree_is_leaf.c](./4-binary_tree_is_leaf.c)** - Write a function that checks if a node is a leaf
    - Prototype: `int binary_tree_is_leaf(const binary_tree_t *node);`
    - Where `node` is a pointer to the node to check
    - Your function must return `1` if `node` is a leaf, otherwise `0`
    - If `node` is `NULL`, return `0`

* **[5-binary_tree_is_root.c](./5-binary_tree_is_root.c)** - Write a function that checks if a given node is a root
    - Prototype: `int binary_tree_is_root(const binary_tree_t *node);`
    - Where `node` is a pointer to the node to check
    - Your function must return `1` if `node` is a root, otherwise `0`
    - If `node` is `NULL`, return `0`

* **[6-binary_tree_preorder.c](./6-binary_tree_preorder.c)** - Write a function that goes through a binary tree using pre-order traversal
    - Prototype: `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`
    - Where `tree` is a pointer to the root node of the tree to traverse
    - And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
    - If `tree` or `func` is `NULL`, do nothing

* **[7-binary_tree_inorder.c](./7-binary_tree_inorder.c)** - Write a function that goes through a binary tree using in-order traversal
    - Prototype: `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`
    - Where `tree` is a pointer to the root node of the tree to traverse
    - And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
    - If `tree` or `func` is `NULL`, do nothing

* **[8-binary_tree_postorder.c](./8-binary_tree_postorder.c)** - Write a function that goes through a binary tree using post-order traversal
    - Prototype: `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`
    - Where `tree` is a pointer to the root node of the tree to traverse
    - And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
    - If `tree` or `func` is `NULL`, do nothing

* **[9-binary_tree_height.c](./9-binary_tree_height.c)** - Write a function that measures the height of a binary tree
    - Prototype: `size_t binary_tree_height(const binary_tree_t *tree);`
    - Where `tree` is a pointer to the root node of the tree to measure the height.
    - If `tree` is `NULL`, your function must return `0`

* **[10-binary_tree_depth.c](./10-binary_tree_depth.c)** - Write a function that measures the depth of a node in a binary tree
    - Prototype: `size_t binary_tree_depth(const binary_tree_t *tree);`
    - Where `tree` is a pointer to the node to measure the depth
    - If `tree` is `NULL`, your function must return `0`

* **[11-binary_tree_size.c](./11-binary_tree_size.c)** - Write a function that measures the size of a binary tree
    - Prototype: `size_t binary_tree_size(const binary_tree_t *tree);`
    - Where `tree` is a pointer to the root node of the tree to measure the size
    - If `tree` is `NULL`, the function must return `0`

* **[12-binary_tree_leaves.c](./12-binary_tree_leaves.c)** - Write a function that counts the leaves in a binary tree

    - Prototype: `size_t binary_tree_leaves(const binary_tree_t *tree);`
    - Where `tree` is a pointer to the root node of the tree to count the number of leaves
    - If `tree` is `NULL`, the function must return 0
    - A `NULL` pointer is not a leaf

* **[]()** - Write a function that counts the nodes with at least 1 child in a binary tree
    - Prototype: `size_t binary_tree_nodes(const binary_tree_t *tree);`
    - Where `tree` is a pointer to the root node of the tree to count the number of nodes
    - If `tree` is `NULL`, the function must return 0
    - A `NULL` pointer is not a node

* **[14-binary_tree_balance.c](./14-binary_tree_balance.c)** - Write a function that measures the balance factor of a binary tree
    - Prototype: `int binary_tree_balance(const binary_tree_t *tree);`
    - Where `tree` is a pointer to the root node of the tree to measure the balance factor
    - If `tree` is `NULL`, return `0`


* **[15-binary_tree_is_full.c](./15-binary_tree_is_full.c)** - Write a function that checks if a binary tree is full
    - Prototype: `int binary_tree_is_full(const binary_tree_t *tree);`
    - Where `tree` is a pointer to the root node of the tree to check
    - If `tree` is `NULL`, your function must return `0`


* **[16-binary_tree_is_perfect.c](./16-binary_tree_is_perfect.c)** - Write a function that checks if a binary tree is perfect
    - Prototype: `int binary_tree_is_perfect(const binary_tree_t *tree);`
    - Where `tree` is a pointer to the root node of the tree to check
    - If `tree` is `NULL`, your function must return `0`

* **[17-binary_tree_sibling.c](./17-binary_tree_sibling.c)** - Write a function that finds the sibling of a node
    - Prototype: `binary_tree_t *binary_tree_sibling(binary_tree_t *node);`
    - Where `node` is a pointer to the node to find the sibling
    - Your function must return a pointer to the sibling node
    - If `node` is `NULL` or the parent is `NULL`, return `NULL`
    - If `node` has no sibling, return `NULL`

* **[18-binary_tree_uncle.c](./18-binary_tree_uncle.c)** - Write a function that finds the uncle of a node
    - Prototype: `binary_tree_t *binary_tree_uncle(binary_tree_t *node);`
    - Where `node` is a pointer to the node to find the uncle
    - Your function must return a pointer to the uncle node
    - If `node` is `NULL`, return `NULL`
    - If `node` has no uncle, return `NULL`

* **[100-binary_trees_ancestor.c](./100-binary_trees_ancestor.c)** - Write a function that finds the lowest common ancestor of two nodes
    - Prototype: `binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);`
    - Where `first` is a pointer to the first node
    - And `second` is a pointer to the second node
    - Your function must return a pointer to the lowest common ancestor node of the two given nodes
    - If no common ancestor was found, your function must return `NULL`

* **[]()** - Write a function that goes through a binary tree using level-order traversal
    - Prototype: `void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));`
    - Where `tree` is a pointer to the root node of the tree to traverse
    - And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
    - If `tree` or `func` is `NULL`, do nothing

## Author
This project is authored by **Oluwatobiloba Light**. Feel free to reach out with any questions or suggestions. :)
