#include <stdio.h>
#include <stdlib.h>


int load_data(char* , int *, int *, int*, int*);
void print_data(int *, int*, int*, int*,int);


int main(int argc, char** argv)
{
	
	if (argc != 3)
	{
		printf("\n Insufficient arguments \n ");
		return 0;
	}
	
	int n = atoi(argv[2]);  //argv[2] contains the number 10 as string
	
	
	//Allocate space to pointers (id and score for three courses) using n

	
	int size;

	// Call load_data function. File name is in argv[1].
	
	
	
	if (size == 0)
	{
		printf("\n Unable to open the input file \n");
		return 0;
	}
	
	//Call print_data function here
	
	//Free the allocated space
	
	return 0;
}


int load_data(char* filename, int *id, int *sc1, int *sc2, int *sc3)
{
	int i = 0;
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		return 0;
	}
	
	int size;
	
	fscanf(file, "%d" , &size);
		
	
	for (i = 0; i < size; i++)
	{
		fscanf(file, "%d %d %d %d", &*(id+i), &*(sc1+i), &*(sc2+i), &*(sc3+i));
		//Call fscanf function and load data from the text file into the four integer arrays
	}
		
	
	fclose(file);
	return 1;
}


void print_data(int * id, int *sc1, int *sc2, int *sc3, int size)
{

	int i;
	
	for (i = 0; i < size; i++)
	{
		printf("%d %d %d %d", id, sc1, sc2, sc3);
	}

}


