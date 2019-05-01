
#ifndef LIST_H
#define LIST_H


struct list_node
{
	void *data;
	struct list_node *next;
};



struct list
{
	int size;
	void (*print_node)(void *data);
	struct list_node *head;
	struct list_node *tail;
};



#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)

#define list_next(node) ((node)->next)


int list_insert_next(struct list *list, struct list_node *node, void *data);
int list_rem_next(struct list *list, struct list_node *node, void **data);
void list_traversal(struct list* list);

#endif
