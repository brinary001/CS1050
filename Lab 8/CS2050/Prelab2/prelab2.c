#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double* read_file(FILE* file, int length);
void min_max(double* array, int length, FILE* outputfile);
void write_to_file(char* filename, double* array, int length);

int main (int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("\nIncorrect Usage");
		return 69;
	}

	int length = atoi(argv[1]);
	double* array = length;
	FILE* file = argv[2];

	write_to_file(argv[3], array, n);

	free(array);

	return 0;
}

double* read_file(FILE* file, int length)
{
	if (file == NULL)
	{
    printf("Read file error.\n");
    exit(0);
	}
  FILE* file = fopen(file, "r");

	double* array = malloc(sizeof(double) * length);
	int i;
	for (i = 0; i < length; i++)
	{
		fscanf(file, "%lf", &array[i]);
	}
	return array;
	close(0);
	close(1);
	close(2);

	fclose(file);
}

void min_max(double* array, int length, FILE* outputfile)
{
	if (array == NULL || length < 1)
	{
		printf("Invalid argument passed to min_max\nExiting.");

		if (array != NULL)
		{
			free(array);
			exit(0);
		}
		exit(0);
	}

	int i = 0;
	double min = *(array+i);
	i++;

	while (i < length)
	{
		if (*(array+i) < min)
		{
			min = *(array+i);
		}
		i++;
	}

	if (array == NULL || length < 1)
	{
		printf("Invalid argument passed to find_max\nExiting.");

		if (array != NULL)
		{
			free(array);
			exit(0);
		}
		exit(0);
	}

	int j = 0;
	double max = *(array+j);
	j++;

	while (j < length)
	{
		if (*(array+j) > max)
		{
			max = *(array+j);
		}
		j++;

		FILE* file = fopen(outputfile, "w");

		fprintf(outputfile, "min: %.2lf\n", min);
		fprintf(outputfile, "max: %.2lf\n", max);
	}
}
