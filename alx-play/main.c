//
//  main.c
//  alx-play
//
//  Created by Emmanuel Adjei-Frimpong on 3/26/23.
//

#include "higher_order_funcs.h"

int iseven(int n){
	return n % 2 == 0;
}

int main(int argc, const char *argv[])
{
	int a[] = {100,2,30,4,6,12};
	int size = sizeof(a) / sizeof(a[0]);
	
	int *even_nums = _filter(a, size, iseven);
	
	Array_i nums;
	nums.a = a;
	nums.size = size;
	
	Array_i *filtered = _filter_v1(&nums, iseven);
	
	printf("Filtered array with _filter: ");
	for(int i = 1; i < even_nums[0]; i++){
		printf("%d ", even_nums[i]);
	}
	printf("\n");
	printf("Size: %d\n", even_nums[0]);
	
	printf("Filtered array with _filter_v1: ");
	for (int i = 0; i < filtered->size; i++) {
		printf("%d ", filtered->a[i]);
	}
	printf("\n");
	printf("Size: %d\n", filtered->size);
	
	free(even_nums);
	free(filtered->a);
	free(filtered);
	return 0;
}
