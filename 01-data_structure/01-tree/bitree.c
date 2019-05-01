#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitree.h"

void bitree_rem_left(struct bitree *tree, struct bitree_node *node);
void bitree_rem_right(struct bitree *tree, struct bitree_node *node);
struct bitree_node *bitree_left(struct bitree_node *tree);
struct bitree_node *bitree_right(struct bitree_node *tree);


void bitree_init(struct bitree *tree)
{
	tree->size = 0;
	tree->root = NULL;
}

int bitree_size(struct bitree *tree)
{
	if (NULL == tree)
		return 0;
	return tree->size;
}

void bitree_destroy(struct bitree *tree)
{
	bitree_rem_left(tree, NULL);
	
	memset(tree, 0, sizeof(struct bitree));
	return;
}

int bitree_insert_left(struct bitree *tree, 
		       struct bitree_node *node, int data)
{
	struct bitree_node *new_node, **position;
	
	/*需要考虑根节点为空的情况*/
	if (node == NULL) {
		if (bitree_size(tree) > 0)
			return -1;
		position = &tree->root;
	} else {
		if (bitree_left(node) != NULL)
			return -1;
		position = &node->left;
	}

	new_node = (struct bitree_node *)malloc(sizeof(struct bitree_node));
	if (new_node == NULL)
		return -1;
	
	new_node->b_data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	tree->size++;

	return 0;
}

int bitree_insert_right(struct bitree *tree,
			struct bitree_node *node, int data)
{
	struct bitree_node *new_node, **position;

	if (node == NULL) {
		if (bitree_size(tree) > 0)
			return -1;
		
		position = &tree->root;
	} else {
		position = &node->right;
	}

	new_node = (struct bitree_node *)malloc(sizeof(struct bitree_node));
	if (NULL == new_node) {
		return -1;
	}

	new_node->b_data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	*position = new_node;
	tree->size ++;

	return 0;
}

void bitree_rem_left(struct bitree *tree, struct bitree_node *node)
{
	struct bitree_node **position;
	
	if (bitree_size(tree) == 0)	
		return;

	if (NULL == node)
		position = &tree->root;
	else
		position = &node->left;

	if (&position != NULL) {
		bitree_rem_left(tree, *position);
		bitree_rem_right(tree, *position);
		
		free(*position);
		*position = NULL;

		tree->size --;
	}

	return;
}

void bitree_rem_right(struct bitree *tree, struct bitree_node *node)
{
	struct bitree_node **position;

	if (bitree_size(tree) == 0)
		return;

	if (NULL == node)
		position = &tree->root;
	else
		position = &node->right;

	if (&position != NULL)
	{
		bitree_rem_left(tree, *position);
		bitree_rem_right(tree, *position);

		free(*position);
		*position = NULL;

		tree->size --;
	}
	
	return;
}

int bitree_is_eob(struct bitree_node *node)
{
	if (NULL == node) {
		return 1;
	} else {
		return 0;
	}
}


int bitree_is_leaf(struct bitree_node *node)
{
	if (NULL == node) {
		return -1;
	}

	if (NULL == node->left && NULL == node->right) {
		return 1;
	} else {
		return 0;
	}
}

struct bitree_node *bitree_left(struct bitree_node *node)
{
	if (NULL == node) {
		return NULL;
	}
	
	return node->left;
}

struct bitree_node *bitree_right(struct bitree_node *node)
{
	if (NULL == node) {
		return NULL;
	}

	return node->right;
}

int bitree_preorder(struct bitree_node *node)
{	
	int ret = 0; 

	if (!bitree_is_eob(node)) {
		printf("%d ", node->b_data);
		
		if (!bitree_is_eob(bitree_left(node))) {
			ret = bitree_preorder(bitree_left(node));
			if (ret != 0)
				return -1;
		}

		if (!bitree_is_eob(bitree_left(node))) {
			ret = bitree_preorder(bitree_right(node));
			if (ret != 0)
				return -1;
		}
	}	
	return 0;
}

struct bitree tree;
int init_tree()
{
	bitree_init(&tree);	
	
	bitree_insert_left(&tree, NULL, 1);
	bitree_insert_left(&tree, tree.root, 2);
	bitree_insert_right(&tree, tree.root, 3);
	
	bitree_insert_left(&tree, tree.root->left, 4);
	bitree_insert_right(&tree, tree.root->left, 5);
	
	bitree_insert_left(&tree, tree.root->right, 6);
}

int main()
{
	init_tree();
	bitree_preorder(tree.root);
	return 0;
}
