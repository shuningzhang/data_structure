
#include <stdio.h>
#include <stdlib.h>

#include "../00-list/list.h"
#include "stack.h"

int stack_push(struct stack *stack, void *data)
{
	return list_insert_next(stack, NULL, data);
}

int stack_pop(struct stack *stack, void **data)
{
	return list_rem_next(stack, NULL, data);
}


