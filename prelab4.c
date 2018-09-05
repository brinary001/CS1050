#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function prototypes
void display_option();
int check_option (int);
int cube (int);
float division (int, int);

int main(void)
{
	srand(time(NULL));
	int x,y;
	x = generate_number();
	
	display_option();
	
	int option;
	printf("Enter your choice: ");
	scanf("%d", &option);
	
	while (check_option(option) < 1 || check_option(option) > 2)
	{
		display_option();
		printf("Invalid choice enter the choice again: ");
		scanf("%d", &option);
	}
	
	while (option == 1 || option == 2)
	{
		switch (option)
		{
			case 1:
				printf("Cube of %d is %d", x, cube(x));
				
			case 2:
				printf("Div(%d,%d)= %.2f", x, y, division (x, y));
		}		
	}
	
	return 0;
}

void display_option()
{
	printf("1 : Cube\n2 : Division\n");
}
int check_option (option)
{
	if (option < 1 || option > 2)
		return 0;
	else 
		return 1;
}
int generate_number(void)
{
	return rand() % 10;
}
int cube (x)
{
	return x * x * x;
}
float division (x, y)
{
	return (float) x / (float) y;
}