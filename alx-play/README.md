#  Array functions implementation in C

## TODO:
[ ] filter
[ ] map
[ ] reduce


```
int *_filter(const int array[], int size, int (*callback)(int))
```
This is a C function that takes an array of integers, a size, and a callback function as arguments, and returns a new dynamically allocated array that contains only the elements that satisfy the callback function.

The function first allocates memory for a new array that can hold all the elements of the original array, plus one extra element to store the length of the filtered array.

Then, it loops through the original array, and for each element that satisfies the callback function, it adds it to the new array at the next available index.

After the loop, the function stores the length of the filtered array in the first index of the new array and reallocates memory to resize the array to the exact size needed.

Finally, it returns the pointer to the new array.

Note that the callback function passed to this function must be a function that takes an integer argument and returns a boolean value indicating whether the integer satisfies some condition. The callback function is called on each element of the original array to determine whether it should be included in the filtered array.

```
Array* _filter_generic_v1(const Array* ar, int (*callback)(const void*))
```
This implementation takes in a pointer to an Array struct, which has an integer size and a void pointer a that can point to any type of array.

The function iterates over the elements of the input array, and uses memcpy to copy elements that pass the callback function to the new filtered array. The sizeof(void*) is used to ensure that the function works with arrays of any type.

After the filtering is complete, the function sets the size of the new array to the number of elements that passed the filter, and resizes the array to the correct size using realloc.

Finally, the function returns a pointer to the filtered Array struct.
