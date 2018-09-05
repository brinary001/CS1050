#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100

//prototypes
void display_menu();
int check_option(int option);
int check_size(int size);
void initialize_2Darray(int x[][MAX], int size);
void print_2Darray(int x[][MAX], int size);
void initialize_1Darray(int y[], int size);
void print_1Darray(int y[], int);
int search_min(int x[][MAX], int r, int c, int size);
int count_match(int x[][MAX], int y[], int size, int r);
int closest_row(int x[][MAX], int y[], int size);
void sort_1Darray(int y[], int size);
void sort_2Darray(int x[][MAX], int size);


int main(void) 
{
	srand(time(NULL));
	
	int array1D[MAX];
    int array2D[MAX][MAX];
	
	int size;
	
	printf("Enter the size: ");
	scanf("%d", &size);
    
    
    
	int error = check_size(size);
	while (error == 0)
	{
		printf("Invalid input enter the size of the array again: ");
		scanf("%d", &size);
		error = check_size(size);
	}
	
	
	initialize_1Darray(array1D, size);
	initialize_2Darray(array2D, size);
    

	display_menu();
	int option;
	
	printf("\nEnter the operation you want to perform: ");
	scanf("%d", &option);
	while (check_option(option) == 0)
	{
		printf("Invalid option, enter the operation again: ");
		scanf("%d", &option);
	}
	
	switch(option)
	{
		case 1:
			printf("Search Min Operation\n");
			print_2Darray(array2D, size);
			int row = 0;
			int col = 0;
			printf("Enter the row: ");
			scanf("%d", &row);
			while (row < 0 || row > size)
			{
				printf("Invalid row enter a row between 0 and %d: ", size);
			}
			printf("Enter the column: ");
			scanf("%d", &col);
			while (col < 0 || col > size)
			{
				printf("Invalid column enter a column between 0 and %d: ", size);
			}
			printf("The smallest number present in row %d and column %d is %d", row, col, search_min(array2D, row, col, size));
			break;
            
		case 2:
			printf("Count Match Operation\n");
			printf("2D Array\n");
			print_2Darray(array2D, size);
			printf("1D Array\n");
			print_1Darray(array1D, size);
			printf("\nEnter the row: ");
			scanf("%d", &row);
			int count = count_match(array2D, array1D, size, row-1);
			if (count == 0)
			{
				printf("There are no numbers from 1D array present in 2D array");
			}
			else
			{
				printf("\nCOUNT: %d\n", count);
			}
			break;
		
		case 3:
			printf("Closest Row Operation\n");
			printf("2D Array\n");
			print_2Darray(array2D, size);
			printf("1D Array\n");
			print_1Darray(array1D, size);
			printf("\nRow closest to the 1D array is row %d", closest_row(array2D, array1D, size));
			break;
			
		case 4:
			printf("Sort 1D Array");
			printf("\n1D array before sorting\n");
			print_1Darray(array1D, size);
			sort_1Darray(array1D, size);
			printf("\n1D array after sorting\n");
			print_1Darray(array1D, size);
			break;
            
		case 5:
			printf("Sort 2d Array");
			printf("\n2D array before sorting\n");
			print_2Darray(array2D, size);
			sort_2Darray(array2D, size);
			printf("\n2D array after sorting\n");
			print_2Darray(array2D, size);
			break;
            
		case 6:
			break;
			
		
	}
	
}//end main

int check_size(int size)
{
	if (size <= 0 || size > 100)
		return 0;
	else
		return 1;
}
void initialize_1Darray(int y[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		y[i] = rand() % 10;
	}
}

void initialize_2Darray(int x[][MAX], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
            int r = (rand()%10);

            x[i][j] = r;
		}
	}
}
int search_min(int x[][MAX], int r, int c, int size)
{
	int min = 0;
	int i = 0;

	for (i = 0; i < size; i++)
	{
		int j = 0;
		for (j = 0; j < size; j++)
		{
			if (x[r][i] == x[j][c])
			{
				if (x[r][i] < min)
				{
					min = x[r][i];
				}
			}
		}
		
	}
		return min;
}
void display_menu()
{
	printf("1: Search Min\n2: Count Matches\n3: Closest Row\n4: Sort 1D Array\n5: Sort 2D Array	\n6: Exit");
}
void print_1Darray(int y[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", y[i]);
	}
}
void print_2Darray(int x[][MAX], int size)
{
	int i = 0;
	for(i = 0; i < size; i++) 	
	{
		int j = 0;
		for(j = 0; j < size; j++) 
		{
			printf("%d ", x[i][j]);
		}
		printf("\n"); 
	}
}
int check_option(int option)
{
	if (option <= 0 || option > 6)
		return 0;
	else 
		return 1;
}
int closest_row(int x[][MAX], int y[], int size)
{
	int closest_value = 100; 
	int closest_row = 0;
	int i = 0;
	for(i = 0; i < size; i++) 
	{
		int t = 0; 
		int j = 0;
		for(j = 0; j < size; j++) 
		{
			t += abs(x[i][j]-y[j]); 
		}
		if (t < closest_value)
		{
			closest_value = t; 
			closest_row = i; 
		}
	}
	return closest_row;
}
void sort_1Darray(int y[], int size)
{
		int hold = 0;
	  	int pass;
	  	for (pass = 0; pass < size; pass++)
	  	{
			  int i;
		  	  for(i = 0; i < (size-1); i++)
		  	  {
			 	 if(y[i] > y[i+1]) 
			  	{
				  hold = y[i+1];
				  y[i+1] = y[i]; 
				  y[i] = hold; 
			  	}
		  	}
	  	}
}
void sort_2Darray(int x[][MAX], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		sort_1Darray(x[i], size); 
	}
}
int count_match(int x[][MAX], int y[], int size, int r)
{
	int i;
	int counter = 0;
    sort_1Darray(y, size);
	for (i = 0; i < size; i++)
	{
        if (y[i] != y[i+1])
        {
            for (int j = 0; j < size; j++)
            {
            
                if (y[i] == x[r][j])
                {
                    counter++;
                }
			
            }
        }
	}
	
	
	return counter;
}