

#ifndef QUEUE_H
#define QUEUE_H
#include "../00-list/list.h"

#define queue list
#define queue_init list_init
#define queue_size list_size

int queue_enqueue(struct queue *queue, void *data);
int queue_dequeue(struct queue *queue, void **data);

#endif
