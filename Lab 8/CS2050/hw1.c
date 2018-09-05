/* Brian Robinson
 * br7pc
 * HW1
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// LICENSEPLATELENGTH - the maximum size of the license plate
#define LICENSEPLATELENGTH 10

/* Structure Variables
 *
 *
 * license_plate - the license plate of the car
 * parking_spot - the parking spot the car is parked in
 * num_tickets - The number of tickets that have been issued to that car
 * time_left - The amount of time (in minutes) remaining on the car’s parking spot
 */

typedef struct Car {
	char *license_plate;
	int parking_spot;
	int num_tickets;
	int time_left;
} Car;

Car* import_cars(char* filename, int numCars);
void adjust_cars(Car* garage, int numCars);
int find_car(Car* garage, int spot, int numCars);
void add_time(Car* garage, int numCars);
void free_garage(Car* garage, int numCars);
void check_car(Car* garage, int numCars);
void print_to_file(char* filename, Car* garage, int numCars);

int main (int argc, char* argv[])
{

	if (argc != 3)
	{
		printf("Incorrect input\nCorrect usage ./a.out <numCars> <input/output file>\n");
		return 0;
	}

	int choice = 0;

	int numCars = atoi(argv[1]);
    	printf("\nnumCars: %d\n\n", numCars);
	Car* garage = malloc(sizeof(Car) * numCars);

    	garage = import_cars(argv[2], numCars);


    do {
        printf("\nTo add time enter '1'\n");
        printf("To check time enter '2'\n");
        printf("To exit enter '-1'\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_time(garage, numCars);
                break;
            case 2:
                check_car(garage, numCars);
                break;
            default:
                printf("Invalid choice");
                break;
        }

    }
	while (choice != -1);

        adjust_cars(garage, numCars);
		print_to_file(argv[2], garage, numCars);

		free_garage(garage, numCars);


	return 0;

}


/* Parameters
 *
 * filename - the name of the input file
 * numCars - the number of cars in the garage
 *
 * Return - An array full of cars
 *
 */
Car* import_cars(char* filename, int numCars)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
        printf("\nNULL FILE\n\n\n");
		return NULL;

	}

	Car* My_cars = malloc(sizeof(Car)*numCars);
   	 int i = 0;
	while (i < numCars)
	{
		(My_cars+i)->license_plate = malloc(sizeof(char)*LICENSEPLATELENGTH);
		fscanf(fp, "%s", (My_cars+i)->license_plate);
		fscanf(fp, "%d %d %d", &(My_cars+i)->parking_spot, &(My_cars+i)->num_tickets, &(My_cars+i)->time_left);
		i++;
	}

	return My_cars; //kasgfkas
}


/* Parameters
 *
 * garage- the array of cars
 * numCars - the number of cars in the garage
 *
 * This function will be called after the user exits
 * the system. It will subtract 30 minutes from the
 * time_left on each car. If the time left is <= 0 after subtraction, a
 * ticket will be added to the car and the time_left
 * will be reset to 60.
 *
 */
void adjust_cars(Car* garage, int numCars)
{
	int i = 0;

	while ((garage+i)->time_left >= 0)
	{
		(garage+i)->time_left -= 30;
	}
	if ((garage+i)->time_left <= 0)
	{
		(garage+i)->num_tickets++;
		(garage+i)->time_left = 60;
	}

}


/* Parameters
 *
 * garage - an array of cars
 * spot - the parking spot the car is located in
 * numCars - the number of cars in the array
 *
 * Return - this function will search the array
 * of cars by the parking spot the car is located
 * in. If it is found, the function will return the
 * index of the array that the car was found in. If
 * the car is not found the function should return -1
 *
 */
int find_car(Car* garage, int spot, int numCars)
{
	int i;
	for (i = 0; i < numCars; i++)
	{
		if ((garage+i)->parking_spot == spot)
		{
			return i;
		}
	}
	return -1;
}


/* Parameters
 *
 * garage - the array of cars
 * numCars- The number of cars in the garage
 *
 * description - this function allows the user
 * to add time (in minutes) for the parking spot specified.
 * It may be beneficial to use the
 * find car function inside this function.
 *
 */
void add_time(Car* garage, int numCars)
{
	int time;
	int spot;


	printf("Enter the parking spot of the car: ");
	scanf("%d", &spot);

    	int car = find_car(garage, spot, numCars);

    	if(car == -1) {
        printf("\nThere is no car parked in that spot.\n");
    	}

	else {
        printf("Enter the amount of time you would like to add: ");
	scanf("%d", &time);
        (garage + car)->time_left = (garage + car)->time_left + time;

    }

}


/*Parameters
 *
 * garage - the array of cars
 * numCars - the number of cars in the garage
 *
 * description - This function will show the
 * user the information stored in the garage
 * struct on the car in the spot specified. It may be beneficial
 * to call the find_car function inside this function
 *
 */
void check_car(Car* garage, int numCars)
{
	int spot;


	printf("Enter the parking spot of the car: ");
	scanf("%d", &spot);

    	int car = find_car(garage, spot, numCars);

    	if(car == -1) {
        printf("\nThere is no car parked in that spot.\n");
    	}

	else {
        printf("\nLicense Plate: %s", (garage + car)->license_plate);
        printf("\nParking Spot: %d", (garage + car)->parking_spot);
        printf("\nNumber of Tickets: %d", (garage + car)->num_tickets);
        printf("\nTime Left: %d minutes\n", (garage + car)->time_left);
    }
}


/* Parameters
 *
 * filename - the name of the output file
 * garage - the array of cars
 * numCars - the number of cars in the garage
 *
 * description - this function will output the final
 * array of cars to the file. This means after the cars
 * have been updated with the time adjustments and
 * tickets from an above function.
 *
 */
void print_to_file(char* filename, Car* garage, int numCars)
{
	FILE* file = fopen(filename, "w");

	int i = 0;
	if (file == NULL)
	{
        printf("\nNULL FILE\n\n\n");
	}


	for(i = 0; i< numCars; i++)
	{
		fprintf(file, "%s\n %d %d %d\n", (garage + i)->license_plate, (garage + i)->parking_spot, (garage + i)->num_tickets, (garage + i)->time_left);

	}

    fclose(file);

}


/*Parameters
 *
 * garage - the array of cars
 * numCars - the number of cars in the garage
 *
 * discription - this function will free the
 * space allocated for the cars. Be sure to free
 * all the memory that applies.
 *
 */
void free_garage(Car* garage, int numCars)
{
	free(garage);
}
