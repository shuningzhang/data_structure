#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


void list_init(struct list *list, 
	       void (*print_node)(void *data))
{
	list->size = 0;
	list->print_node = print_node;

	list->head = NULL;
	list->tail = NULL;
	return;
}

void list_destroy(struct list *list)
{
	;
}

/* 在node后插入一个新元素， 如果node为NULL，则
 * 在链表头部插入一个新元素。 */
int list_insert_next(struct list *list, 
		     struct list_node *node,
		     void *data)
{
	struct list_node *new_node;

	if (NULL == list) {
		return -1;
	}	

	new_node = (struct list_node*)malloc(sizeof(struct list_node));
	if (NULL == new_node) {
		return -1;
	}

	new_node->data = data;
	if (NULL == node) {
		if (list_size(list) == 0)
			list->tail = new_node;
		new_node->next = list->head;
		list->head = new_node;		
	} else {
		if (NULL == node->next) {
			list->tail = new_node;
		}
		new_node->next = node->next;
		node->next = new_node;
	}
	
	list->size ++;
	return 0;
}


/* 移除链表中node后的元素。 如果node为NULL，则
 * 移除链表头元素。data存储已经移除的元素的数据。*/
int list_rem_next(struct list *list,
		  struct list_node *node,
		  void **data)
{
	struct list_node *tmp;

	if (NULL == list || list_size(list) == 0) {
		*data = NULL;
		return -1;
	}

	if (NULL == node) {
		tmp = list->head;
		list->head = list->head->next;
		if (NULL == list->head) {
			list->tail = NULL;
		}
	} else {
		tmp = node->next;
		if (NULL == tmp) {
			return -1;
		}
		node->next = tmp->next;
		if (NULL == node->next) 
			list->tail = node;
	}

	list->size --;
	*data = tmp->data;
	free(tmp);
	tmp = NULL;
	
	return 0;
}

void list_traversal(struct list* list)
{
	struct list_node *tmp;
	
	tmp = list->head;
	while (tmp) {
		if (list->print_node) {
			list->print_node(tmp->data);
		}
		tmp = tmp->next;
	}

	printf("\n");
}

