#include <stdio.h>

void print_data(int *data, int nitems);

void insert_sort(int *data, int nitems, int offset, int gap)
{
	int sorted_pos = 0;
	int cur_pos = 0;
	int count = nitems / gap;
	int cur_data = 0;

	for (sorted_pos = offset; sorted_pos < nitems - gap + offset; sorted_pos = sorted_pos + gap) {
		if (sorted_pos + gap >= nitems) {
			cur_data = data[nitems - 1];
		} else {
			cur_data = data[sorted_pos + gap];
		}
		for (cur_pos = sorted_pos; cur_pos >= offset; cur_pos -= gap ) {
			if (cur_data < data[cur_pos]) {
				data[cur_pos + gap] = data[cur_pos];	
			} else {
				break;
			}
		}
		data[cur_pos + gap] = cur_data;
	}
}

/* 描述： 希尔排序，该函数最终将数据排列成升序。 */
void shell_sort(int *data, int nitems)
{
	int gap = nitems / 2;
	int offset = 0;

	while (gap >= 1) {
		printf("\n");
		for (offset = 0; offset < gap; ++ offset ) {
			insert_sort(data, nitems, offset, gap);
			print_data(data, nitems);
		}
		gap = gap /2;
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
	int data[] = {9, 7, 5, 4, 6, 8, 2, 3, 1};
	print_data(data, sizeof(data)/sizeof(int));
	shell_sort(data, sizeof(data)/sizeof(int));
	print_data(data, sizeof(data)/sizeof(int));
}
