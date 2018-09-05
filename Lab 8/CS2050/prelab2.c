#include <stdio.h>
#include <stdlib.h>

double* read_file(char* filename, int length);
double find_min(double* array, int length);
double find_max(double* array, int length);
void write_to_file(char* filename, double* array, int length);
double median(double* array, int length);
double mode(double* array, int length);

int main (int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("\nIncorrect Usage");
		return 0;
	}
	
	int n = atoi(argv[1]);
	double* array2 = read_file(argv[2], n);
	write_to_file(argv[3], array2, n);
	
	free(array2);

	return 0;
}

double* read_file(char* filename, int length)
{
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		return 0;
	}
	
	double* array = malloc(sizeof(double) * length);
	int i;
	for (i = 0; i < length; i++)
	{
		fscanf(file, "%lf", &array[i]);
	}
	return array;
	
	fclose(file);
}
double find_min(double* array, int length)
{
	int i = 0;

	double min = array[i];
	for (i = 0; i < length; i++)
	{
		if (array[i] < min)
			min = array[i];
	}
	
	return min;
}
double find_max(double* array, int length)
{
	int i = 0;

	double max = array[i];
	for (i = 0; i < length; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return max;
}
double median(double* array, int length)
{
	double med;
	int i, j;
	//sort the array in ascending order
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (array[j] < array[i])
			{
				med = array[i];
				array[i] = array[j];
				array[j] = med;
			}
		}
	}	
	int mid = length/2;
	//if there's an even number of elements, return the mean of two elements in the middle
	if (length % 2 == 0)
	{
		med = ((double)(*(array+mid))+(*(array+mid -1)))/2;
	}
	//else just use element in the middle
	else
	{
		med = *(array + mid);
	}
	return med;
}
double mode(double* array, int length)
{
	int i, j, max, m;
	//to hold the length
	int total[length];
	//step through the length
	for (i = 0; i < length; i++)
	{
		total[array[i]]++;
	}
	max = 0;
	m = 0;
	//step through length again and find max (the mode)
	for (j = 0; j < length; j++)
	{
		if (total[j] > max)
		{
			max = total[j];
			m = j;
		}
	return m;
}			
void write_to_file(char* filename, double* array, int length)
{
	printf("min: %.2lf\n", find_min(array, length));
	printf("max: %.2lf\n", find_max(array, length));
	printf("median: %.2lf", median(array, length));
	FILE* file = fopen(filename, "w");
	
	if (file==NULL)
		printf("File not found");
	
	int i;
	for (i = length -1; i != -1; i--)
	{
		fprintf(file, "%.2lf\n", array[i]);
	}
	fclose(file);
}

