
#ifndef LIST_H
#define LIST_H


struct list_node
{
	int data;
	struct list_node *next;
};


struct list
{
	int size;
	struct list_node *head;
	struct list_node *tail;
};

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)

#define list_next(node) ((node)->next)


int list_insert_next(struct list *list, struct list_node *node, int data);
int list_rem_next(struct list *list, struct list_node *node, int *data);
void list_print(struct list* list);

#endif
