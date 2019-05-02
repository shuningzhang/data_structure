
#include <stdio.h>

#include "bitree.h"

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

	bitree_insert_left(&tree, tree.root->left->left, 7);
}

int main()
{
	init_tree();
	bitree_preorder_ex(tree.root);
	return 0;
}
