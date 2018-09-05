/* Brian Robinson br7pc
 * Lab 8
 * Last lab
 */

#include <stdio.h>
#include <stdlib.h>

int load_data(char*, int *, int *, int*, int*, int);
void print_data(int *, int*, int*, int*, int);
float* average_score(int*, int*, int*, int);
char *calculate_grade(float*, int);
int write_data(char*, int*, int*, int*, int*, float*, char*, int);

int main (int argc, char** argv)
{
	if (argc != 4)
	{
		printf("\nInsufficient arguments\n");
	}
	char *ptr = argv[1];
	int n = atoi(argv[2]);
	int *id = malloc(sizeof(int)*n);
	int *sc1 = malloc(sizeof(int)*n);
	int *sc2 = malloc(sizeof(int)*n);
	int *sc3 = malloc(sizeof(int)*n);
	int s = load_data(argv[1], id, sc1, sc2, sc3, n);
	float *average = average_score(sc1, sc2, sc3, n);
	char *grade = calculate_grade(average, n);
	//print_data(id, sc1, sc2, sc3, n); 
	printf("\n------------------------------------------------------------------\n");
	printf("\tID\t\tCourse 1\tCourse 2\tCourse 3\n");
	printf("------------------------------------------------------------------\n");
	print_data(id, sc1, sc2, sc3, n);
	printf("------------------------------------------------------------------\n");
	int s2 = write_data(argv[3], id, sc1, sc2, sc3, average, grade, n);
	if (s == 0)
	{
		printf("\nUnable to open input file\n");
		return 0;
	}
	
	return 0;
}

int load_data(char* filename, int *id, int *sc1, int *sc2, int *sc3, int size)
{
	int i = 0;
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		return 0;
	}

	for (i = 0; i < size; i++)
	{
		fscanf(file, "%d %d %d %d", &*(id+i), &*(sc1+i), &*(sc2+i), &*(sc3+i));
	}
	fclose(file);
	return 1;
}
void print_data(int * id, int *sc1, int *sc2, int *sc3, int size)
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		printf("%d\t \t\t%d\t \t%d\t \t%d\n", *(id+i), *(sc1+i), *(sc2+i), *(sc3+i));
	}
}
float* average_score(int* sc1, int* sc2, int* sc3, int size)
{
	float *ptr = malloc(sizeof(float)*size);
	int i;
	float total = 0;
	for (i = 0; i < size; ++i)
	{
		total = *(sc1+i) + *(sc2+i) + *(sc3+i);
		*(ptr+i) = ((float)total)/3;
	}
	return ptr;
}
char *calculate_grade(float* average, int size)
{
	char *calc_grade = malloc(sizeof(char)*size);
	int i;
	for (i = 0; i < size; ++i)
	{
		if (*(average+i) >= 90 && *(average+i) <= 100)
			*(calc_grade+i) = 'A';
		if (*(average+i) >= 80 && *(average+i) < 90)
			*(calc_grade+i) = 'B';
		if (*(average+i) >= 70 && *(average+i) < 80)
			*(calc_grade+i) = 'C';
		if (*(average+i) >= 60 && *(average+i) < 70)
			*(calc_grade+i) = 'D';
		if (*(average+i) < 60)
			*(calc_grade+i) = 'F';
	}
	return calc_grade;
}
int write_data(char* filename, int* id, int* sc1, int* sc2, int* sc3, float* average, char* grade, int size)
{
	int i = 0;
	FILE* file = fopen(filename, "w");
	if (file == NULL)
	{
		return 0;
	}
	for (i = 0; i < size; i++)
	{
		fprintf(file, "%d\n", *(id+i), *(sc1+i), *(sc2+i), *(sc3+i), *(average+i), *(grade+i));
	}
	fclose(file);
	return 1;
}
