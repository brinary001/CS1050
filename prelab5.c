#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_error(int);
void initialize_array(int[], int);
void print_array(int[], int);
int replace(int [], int, int, int);

#define MAX 100

int main(void) 
{
	srand(time(NULL));
	
	int size;
	
	printf("Enter the size of the input: ");
	scanf("%d", &size);
	
	int error = check_error(size);
	
	while (error == 0)
	{
		printf("Invalid input enter the size of the input again: ");
		scanf("%d", &size);
		error = check_error(size);
	}
	int array[size];
	initialize_array(int array, int size)
	print_array(int array, int size)
}
int check_error(int size)
{
	if (size <= 0 || size > 100)
		return 0;
	else
		return 1;
}
void initialize_array(int array[], int size)
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		array[i] = (rand() % 10);
	}
}
void print_array(int array[], int size)
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
	}
}
int replace(int array[], int size, int index, int number)
{
	
}