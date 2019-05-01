
#include <stdio.h>

#include "list.h"

struct list list;

int init_list()
{
	list_init(&list);
	
	list_insert_next(&list, NULL, 1);
	list_insert_next(&list, NULL, 2);
	list_insert_next(&list, NULL, 3);

}



int main()
{
	init_list();
	list_print(&list);
	return 0;
}
