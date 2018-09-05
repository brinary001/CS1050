/* Brian Robinson
 * br7pc
 * Arrays
 */

#include <stdio.h>
#include <time.h>

int check_error(int);
void initialize_array(int[], int);
void print_array(int[], int);
int max(int[], int);
int min(int[], int);
float average(int[], int);
void compute_stats(int[], int);
int count_numbers(int[], int, int);

#define MAX 100

int main (void)
{
	srand(time(NULL));

	int array[MAX];

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
	
	initialize_array(array, size);
	printf("\nInput array\n");
	print_array(array, size);
	
	compute_stats(array, size);
	
	int number;
	printf("\nEnter a number to count: ");
	scanf("%d", &number);
	int count = count_numbers(array, size, number);
	if (count == 0)
		printf("The number %d is not present in the array\n", number);
	else
		printf("The number %d is present %d times in the array\n", number, count);

	return 0; 
}
int check_error(int size)
{
	if (size <= 0 || size > 100)
		return 0;
	else
		return 1;
}
void initialize_array(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 10;
	}
}
void print_array(int array[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

}
int max(int array[], int size)
{
	int i;
	int a=array[0];
		

	for (i = 0; i < size; i++)
	{
		if( array[i]>a)
		{
			a = array[i];
		}
	}
	return a;
}
int min(int array[], int size)
{
	int i;
	int a = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] < a)
		{
			a = array[i];
		}
	}
	return a;
}	
float average(int array[], int size)
{
	int i;
	int a;
	int total=0;

	for (i = 0; i < size; i++)
	{	
		total += array[i];
	}
	float array_average = ((float) total / (float) size);
	return array_average;
}
void compute_stats(int array[], int size)
{
	printf("\nLargest number is %d\n", max(array, size));
	printf("Smallest number is %d\n", min(array, size));
	printf("Average of numbers is %.3f\n", average(array, size));
}
int count_numbers(int array[], int size, int number)
{
	int i;
	int counter = 0;	
	for (i = 0; i < size; i++)
	{
		if (number == array[i])
			counter++;
	}
	return counter;
}
