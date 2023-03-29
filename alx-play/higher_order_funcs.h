//
//  higher_order_funcs.h
//  alx-play
//
//  Created by Emmanuel Adjei-Frimpong on 3/28/23.
//

#ifndef higher_order_funcs_h
#define higher_order_funcs_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int *a;
	int size;
} Array_i;

int *_filter(const int array[], int size, int (*callback)(int));
Array_i *_filter_v1(const Array_i *ar, int (*callback)(int));


#endif /* higher_order_funcs_h */
