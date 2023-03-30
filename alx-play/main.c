//
//  main.c
//  alx-play
//
//  Created by Emmanuel Adjei-Frimpong on 3/26/23.
//

#include "higher_order_funcs.h"

int contains_a(char *s);
void test_filter_strings_func(void);
void print_strings(const char **s, unsigned int size);
void print(Array_s *ptr);
void free_s(Array_s *ptr);

int iseven(int n){
	return n % 2 == 0;
}

int main(int argc, const char *argv[])
{
	
	test_filter_strings_func();
	return 0;
}

int contains_a(char *s)
{
	if (strchr(s, 'a') || strchr(s, 'A'))
		return 1;
	return 0;
}

void test_filter_strings_func()
{
	char *strs[] = {
		"dog",
		"cat",
		"lyn",
		"great",
		"meet"
	};
	unsigned int size = sizeof(strs) / sizeof(char *);
	//printf("size: %d\n", size);
	
	Array_s ptr;;
	ptr.strings = strs;
	ptr.size = size;
	
	//print(&ptr);
	
	Array_s *filtered_s = filter_strings(&ptr, contains_a);
	
	print(filtered_s);
	
	free_s(filtered_s);
}

void print_strings(const char **s, unsigned int size)
{
	for (int i = 0; i < size; i++) {
		printf("%s\n", *(s + i));
	}
}

void print(Array_s *ptr)
{
	printf("Filtered array:\n");
	print_strings((const char **)ptr->strings, ptr->size);
	printf("Size: %d\n", ptr->size);
}

void free_s(Array_s *ptr) {
	for (int i = 0; i < ptr->size; i++) {
		free(ptr->strings[i]);
	}
	free(ptr->strings);
	free(ptr);
}

void test_filter_int_func()
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
}
