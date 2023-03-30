//
//  higher_order_funcs.c
//  alx-play
//
//  Created by Emmanuel Adjei-Frimpong on 3/28/23.
//

#include "higher_order_funcs.h"

int *_filter(const int array[], int size, int (*callback)(int))
{
	int *ptr = malloc(sizeof(int) * (size + 1));
	int i, j;
	
	for (i = 0, j = 1; i < size; i++)
	{
		if (callback(array[i]))
			ptr[j++] = array[i];
	}
	// store length of filtered array in 0 index
	ptr[0] = --j;
	
	ptr = realloc(ptr, sizeof(int) * j);
	
	return ptr;
}

Array_i *_filter_v1(const Array_i *ar, int (*callback)(int))
{
	int i, j;
	Array_i *ptr = malloc(sizeof(Array_i));
	ptr->a = malloc(sizeof(int) * ar->size);
	
	for (i = 0, j = 0; i < ar->size; i++) {
		if (callback(ar->a[i]))
			ptr->a[j++] = ar->a[i];
	}
	ptr->size = j;
	ptr->a = realloc(ptr->a, sizeof(int) * j);
	
	return ptr;
}

/**
 
 * Filters the strings in the given Array_s based on a given filter condition.
 * @param ar - The Array_s pointer containing the strings to be filtered.
 * @param callback - The filter condition to be applied to each string. A pointer to a function that takes a char pointer as an argument and returns an integer value (usually 0 or 1).
 * @return A new Array_s pointer containing only the strings from the original Array_s that meet the filter condition.
 */
Array_s *filter_strings(const Array_s *ar, int (*callback)(char *))
{
	unsigned int i, j;
	
	if (!ar || !ar->strings)
		return NULL;
	// allocate space for the whole struct
	Array_s *ptr = malloc(sizeof(Array_s));
	
	if (!ptr) {
		printf("Allocation fail for struct type Array_s\n");
		return NULL;
	}
	
	// allocate space for array of strings
	ptr->strings = malloc(sizeof(char *) * ar->size);
	
	if (!ptr->strings) {
		printf("Allocation fail for ptr->strings array\n");
		free(ptr);
		return NULL;
	}
	
	// allocate space for individual strings filter condition
	for (i = 0, j = 0; i < ar->size; i++)
	{
		if (callback(ar->strings[i])) {
			ptr->strings[j] = malloc(sizeof(char) * (strlen(ar->strings[i]) + 1));
			
			if (!ptr->strings[j]) {
				printf("Allocation fail for ptr->strings[%d] string\n", j);
				for (int i = 0; i < j; i++) {
					free(ptr->strings[i]);
				}
				free(ptr->strings);
				free(ptr);
				return NULL;
			}
			if (!ar->strings[i])
				return NULL;
			strcpy(ptr->strings[j], ar->strings[i]);
			j++;
		}
	}
	ptr->size = j;
	ptr->strings = realloc(ptr->strings, sizeof(char *) * j);
	
	return  ptr;
}
