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
Array_i *_filter_v1(const Array_i *ar, int (*callback)(int));
```
This is a C function called _filter_v1 that takes in a pointer to an Array_i struct and a pointer to a callback function that takes an int argument and returns an int.

The Array_i struct contains an array of integers (a) and the size of the array (size).

The purpose of the _filter_v1 function is to iterate through each element in the array pointed to by ar, apply the callback function to each element, and create a new Array_i struct containing only the elements that satisfy the condition specified in the callback function.

The function does this by first allocating memory for a new Array_i struct and its a array using malloc. It then loops through each element in the input Array_i struct (ar) and applies the callback function to it. If the result of the callback function is non-zero, the current element is added to the new Array_i struct (ptr).

Once all the elements have been processed, the function updates the size of the new Array_i struct (ptr) to reflect the number of elements that satisfied the condition specified in the callback function. It then shrinks the size of the a array to fit only the elements that were added to it using realloc, and returns the new Array_i struct.

Note that the caller of this function is responsible for freeing the memory allocated for the new Array_i struct and its a array using free.
