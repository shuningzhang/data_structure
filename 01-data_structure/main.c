#include <stdio.h>

#include "00-list/list.h"

struct list list;

int init_list()
{
	list_init(&list);
	
	list_insert_next(&list, NULL, 1);
	list_insert_next(&list, NULL, 2);
	list_insert_next(&list, NULL, 3);

}


list_test()
{
	init_list();
	list_print(&list);	
}

int main()
{
	list_test();
	return 0;
}
