/* Brian Robinson
 * br7pc
 * Lab Section B
 * Lab 4
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

typedef enum category {

	SEATS,
	MILEAGE,

} Category;

void sort(int low, int high, Category x, int length);
Car* scan_cars(char* filename, int length);
void print_to_file(char* filename, Car* garage, int length);

int main (int argc, char* argv[])
{

	if (argc != 4)
	{
		printf("Incorrect usage");
	}

	int length = atoi(argv[1]);

	Car* garage = malloc(sizeof(Car) * length);

	garage = scan_cars(argv[2], length)
	char* out_file = argv[3];
	int low = 0;
	int high = 9999;

*int i, j;
	for (i = 0; i < length)
	{
		low = i;
		for (j = i+1; j < n; j++)
		{
			if (garage.

	sort(low, high, SEATS, garage);
	sort(low, high, MILEAGE, garage);
	print_to_file(out_file, garage, length);
	printf("The array has been sorted by seats and mileage and has been output to output.txt");

	free(garage);

	return 0;
}

Car* scan_cars(char* filename, int length)
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
                (My_cars+i)->color = malloc(sizeof(char)*6);
                fscanf(fp, "%s %d %d", (My_cars+i)->color, &(My_cars+i)->seats, &(My_cars+i)->mileage);
                i++;
        }

        return My_cars;
}

void sort(int low, int high, Category x, Car* garage)
{
	int lh, rh, i;
	Car temp;
	temp.color = malloc(sizeof(char)*6);
	if (x == SEATS)
	{
		for (lh = low; lh < length; lh++)
		{
			rh = high;
			for ( i = lh; i < ; i++)
			{
				if (garage[i].seats < garage[rh].seats) rh = i;
				temp = garage[lh];
				garage[lh] = garage[rh];
				garage[rh] = temp;
			}
		}

	}

	if (x == MILEAGE)
	{
		for (lh = low; lh < length; lh++)
		{
			rh = high;
			for ( i = lh; i < ; i++)
			{
				if (garage[i].mileage < garage[rh].mileage) rh = i;
				temp = garage[lh];
				garage[lh] = garage[rh];
				garage[rh] = temp;
			}
		}

	}

}

void print_to_file(char* filename, Car* garage, int length)
{
	FILE* file = fopen(filename, "w");

	int i = 0;
	if (file == NULL)
	{
		printf("NULL FILE");
	}

	for (i = 0; i < length; i++)
	{
		fprintf(file, "%s\n %d %d\n", (garage + i)->color, (garage + i)->seats, (garage + i)->mileage);
	}

	fclose(file);
}
