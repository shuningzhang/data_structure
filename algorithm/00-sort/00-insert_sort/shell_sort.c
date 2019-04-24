#include <stdio.h>

/* 描述： 直接插入排序，该函数最终将数据排列成升序。 */
void shell_sort(int *data, int nitems)
{
}

void print_data(int *data, int nitems)
{
	int index = 0;
	if (data == NULL) {
		return;
	}
	
	for (index = 0; index < nitems; index ++) {
		printf("%d ", data[index]);
	}
	printf("\r\n");
}
int main(void)
{
	int data[] = {9, 7, 2, 3, 6, 8, 5, 4, 1};
	print_data(data, sizeof(data)/sizeof(int));
	shell_sort(data, sizeof(data)/sizeof(int));
	print_data(data, sizeof(data)/sizeof(int));
}
