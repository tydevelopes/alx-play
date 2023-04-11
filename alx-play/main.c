#include <stdio.h>
#include "bit_manipulation.h"

void mye(int n){
	if (n < 5) {
		printf("Num < 5\n");
		exit(2);
	}
	printf("Num > 4\n");
}
void gree(void){
	printf("Hello\n");
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	mye(4);
	gree();
	return (0);
}


