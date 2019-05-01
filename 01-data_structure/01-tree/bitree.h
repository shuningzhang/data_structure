#ifndef BITREE_H
#define BITREE_H

struct bitree_node {
	int b_data;
	struct bitree_node *left;
	struct bitree_node *right;
};

struct bitree {
	int size;
	struct bitree_node *root;
};


#endif
