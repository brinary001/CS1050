#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double* read_file(char* filename, int length);
double find_min(double* array, int length);
double find_max(double* array, int length);
void write_to_file(char* filename, double* array, int length);

int main (int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("Command line not used correctly.\n");
		printf("Correct usage: <./a.out> <file length> <input file> <output file>");
		return 1;
	}
	int length = atoi(argv[1]);
	//printf("length: %d\n", length);
	char* input_file = argv[2];
	char* output_file = argv[3];

	double* ayeray = read_file(input_file, length);
	if (ayeray == NULL)
	{
		printf("File not found\n");
		return -1;
	}

	double max = find_max(ayeray, length);
	double min = find_min(ayeray, length);
	printf("The max is %.2lf\n", max);
	printf("The min is %.2lf\n", min);

	write_to_file(output_file, ayeray, length);
	free(ayeray);
	close(0);
	close(1);
	close(2);

	return 0;	
}

double* read_file(char* filename, int length)
{
	if (filename == NULL || length < 1)
	{
		printf("Read file error\n");
		exit(0);
	}

	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error attempting to open file %s", filename);
		exit(0);
	}
	
	double* ayeray = malloc(sizeof(double)*length);
	if( ayeray == NULL)
	{
		printf("Error attempting to read file %s", filename);
		exit(0);
	}
	
	int i = 0;
	while (i < length)
	{
		fscanf(fp,"%lf", (ayeray+i));
		printf("%lf\n", *(ayeray+i));
		i++;
	}
	fclose(fp);	
	return ayeray;
}

double find_min(double* array, int length)
{
	if (array == NULL || length < 1)
	{
		printf("Invalid argument passed to find_min\nExiting.");
	
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
	return 0;
}

double find_max(double* array, int length)
{
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

	int i = 0;
	double max = *(array+i);
	i++;
	
	while (i < length)
	{
		if (*(array+i) > max)
		{
			max = *(array+i);
		}
		i++;
	}
	return 0;
}

void write_to_file(char* filename, double* array, int length)
{
	if (filename == NULL || length < 1 || array == NULL)
	{
		printf("Read file error\n");
		exit(0);
	}

	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
	{
		printf("Error attempting to open file %s", filename);
		exit(0);
	}
	
	int i = 0;
	while (i < length)
	{
		fprintf(fp,"%lf", *(array+i));
		i++;
	}
	fclose(fp);

}

