#include <stdio.h>

/* 描述： 直接插入排序，该函数最终将数据排列成升序。 */
void insert_sort(int *data, int nitems)
{
	int sorted_pos = 0;
	int cur_pos = 0;
	int cur_data;

	if (nitems == 1) {
		return;
	}

	for (sorted_pos = 0; sorted_pos < nitems; sorted_pos ++)
	{
		cur_data = data[sorted_pos + 1];
		for (cur_pos = sorted_pos ; cur_pos >= 0; cur_pos --)
		{
			if (cur_data < data[cur_pos]) {
				data[cur_pos + 1] = data[cur_pos];
			} else {
				break;
			} 
		}
		data[cur_pos + 1] = cur_data;
	}
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
	insert_sort(data, sizeof(data)/sizeof(int));
	print_data(data, sizeof(data)/sizeof(int));
}
