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

Array* _filter_generic_v1(const Array* ar, int (*callback)(const void*))
{
	int i, j;
	Array* ptr = malloc(sizeof(Array));
	ptr->a = malloc(ar->size * sizeof(void*));
	
	for (i = 0, j = 0; i < ar->size; i++) {
		const void* elem = (const char*)ar->a + i * sizeof(void*);
		if (callback(elem)) {
			memcpy((char*)ptr->a + j++ * sizeof(void*), &elem, sizeof(void*));
		}
	}
	ptr->size = j;
	ptr->a = realloc(ptr->a, j * sizeof(void*));
	
	return ptr;
}


