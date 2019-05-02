
#include <stdio.h>

#include "queue.h"


int queue_enqueue(struct queue *queue, void *data)
{
	return list_insert_next(queue, list_tail(queue), data);
}

int queue_dequeue(struct queue *queue, void **data)
{
	return list_rem_next(queue, NULL, data);
}
