
#include <stdio.h>

#include "queue.h"

struct queue queue;

int a = 1;
int b = 2;
int c = 3;
int *data;

int queue_test()
{
	queue_init(&queue);

	queue_enqueue(&queue, &a);
	queue_enqueue(&queue, &b);
	queue_enqueue(&queue, &c);


	queue_dequeue(&queue, (void **)&data);
	printf("%d \n", *data);
}

int main()
{
	queue_test();
	return 0;
}
