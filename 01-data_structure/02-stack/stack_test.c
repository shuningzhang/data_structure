
#include <stdio.h>

#include "stack.h"

struct stack stack;

int a = 1;
int b = 2;
int c = 3;

void test_stack()
{
	int *data;
	stack_init(&stack);
	stack_push(&stack, &a);
	stack_push(&stack, &b);
	stack_push(&stack, &c);

	stack_pop(&stack, (void **)&data);
	printf("%d\n", *data);
}


int main()
{
	test_stack();
	return 0;
}
