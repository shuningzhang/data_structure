
#include <stdio.h>

#include "bitree.h"
#include "../03-queue/queue.h"

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

/* 计算二叉树的节点的数量, 递归方法 */
int bitree_calc_count(struct bitree_node *node)
{
	int left_count = 0;
	int right_count = 0;

	if (node == NULL) {
		return 0;
	}

	if (node->left == NULL && node->right == NULL) {
		return 1;
	}
	
	left_count = bitree_calc_count(node->left);
	right_count = bitree_calc_count(node->right);

	return left_count + right_count + 1;
}

/* 计算二叉树的节点数量， 非递归方法 */
int bitree_calc_count_ex(struct bitree_node *node)
{
	int count = 0;

	return count;
}

/* 计算树的高度， 递归方法 */
int bitree_calc_height(struct bitree_node *node)
{
	int left_height = 0;
}

int main()
{
	init_tree();
	//bitree_preorder_ex(tree.root);
	//bitree_levelorder(tree.root);
	printf("%d \n", bitree_calc_count(tree.root));
	return 0;
}
