
#include <stdio.h>

#include "list.h"

struct list list;

void node_print(void *data)
{
	int *true_data = (int *)data;
	printf("%d ", *true_data);
}

int a = 1;
int b = 2;
int c = 3;

int init_list()
{
	list_init(&list, node_print);
	
	list_insert_next(&list, NULL, &a);
	list_insert_next(&list, NULL, &b);
	list_insert_next(&list, NULL, &c);

}



int main()
{
	init_list();
	list_traversal(&list);
	return 0;
}
