/* Brian Robinson
 * br7pc
 * Lab Section B
 * Prelab 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct car {
char* color;
int seats;
int mileage;
} Car;

void bubble_sort_mileage(Car* garage, int length);
Car* import_cars(char* filename, int length);

int main (char argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Incorrect usage");
	}
	
	int length = atoi(argv[1]);
	printf("\n%d\n",length);
	Car* garage = malloc(sizeof(Car) * length);

	garage = import_cars(argv[2], length)

	return 0;	
}

Car* import_cars(char* filename, int length) 
{ 
        FILE* fp = fopen(filename, "r"); 
        if (fp == NULL) 
        { 
        printf("\nNULL FILE\n\n\n"); 
                return NULL; 
         
        } 
     
        Car* My_cars = malloc(sizeof(Car)*length); 
        int i = 0; 
        while (i < length) 
        { 
                (My_cars+i)->license_plate = malloc(sizeof(char)*LICENSEPLATELENGTH); 
                fscanf(fp, "%s %d %d", (My_cars+i)->color, &(My_cars+i)->seats, &(My_cars+i)->mileage); 
                i++; 
        } 
         
        return My_cars;
}

void bubble_sort_mileage(Car* garage, int length)
{
	Car hold;
	hold.color = malloc(sizeof(char)*7);

	int pass;
	
	for (pass = 0; pass < length; pass++)
	{
		int i;
		for (i = 0; i < (length - 1); i++)
		{
			if (garage[i] > garage[i+1]); //do this for each of the three struct members
			{
				
				hold = garage[i+1];

				

				garage[i+1] = garage[i];



				garage[i] = hold;
			}
		}
	}	
}

