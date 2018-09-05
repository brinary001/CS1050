#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_array(int* array, int length);
void bubble_sort(int length, int* array);
void find_number(int* array, int length, int number);
void write_to_file(char* filename, int* array, int length);

int main (int argc, char* argv[])
{
	srand(time(NULL));
	if (argc != 2)
	{
		printf("\nIncorrect usage");
		return 0;
	}
	
	int amount;
	printf("Please choose the amount of numbers you would like in the array (1-100:\n)");
	scanf("%d", &amount);
	int *array = malloc(amount * sizeof(int));
	int i;
	for (i = 0; i < amount; i++)
	{
		array[i] = (rand() % 99) + 1;
	}
	print_array(array, amount);
	bubble_sort(amount, array);
	int num_search;
	printf("Please enter a number you would like to search for (1-100)\nEnter -1 if you wish to terminate the program: ");
	scanf("%d", &num_search);
	while (num_search != -1)
	{
		//printf("Please enter a number you would like to search for (1-100)\nEnter -1 if you wish to terminate the program: ");
		find_number(array, amount, num_search);
		break;		
	}
	write_to_file(argv[1], array, amount);
	free(array);
	
	return 0;
}
void print_array(int* array, int length)
{
	int i;
	
	for (i = 0; i < length; i++)
	{
		printf("\n%d .%5d\n", i+1, array[i]);
	}
	
}
void bubble_sort(int length, int* array)
{
	int hold = 0;
	int pass;
	
	for (pass = 0; pass < length; pass++)
	{
		int i;
		for (i = 0; i < (length - 1); i++)
		{
			if (array[i] > array[i+1]);
			{
				hold = array[i+1];
				array[i+1] = array[i];
				array[i] = hold;
			}
		}
	}
}
void find_number(int* array, int length, int number)
{
	int i;
	int found = 0;
	int location = 0;
	for (i = 0; i < length; i++)
	{
		if (*(array+i) == number)
		{
			found = 1;
			location = i + 1;
		}
	}
	if (found == 1)
	{
		printf("%d found at location %d", number, location);
	}
	else
	{
		printf("Not found!  %d is not present in the list.", number);
	}
}
void write_to_file(char* filename, int* array, int length)
{
	FILE* file = fopen(filename, "w");
	
	if (file == NULL)
	{
		printf("File not found");
	}
	int i;
	for ( i = length - 1; i != -1; i--)
	{
		fprintf(file, "%d\n", array[i]);
	}
	fclose(file);
}

