#include <stdio.h>
#include <math.h>

int main(void) {
	int choice;
	int square_side;
	int rect_side1;
	int rect_side2;
	int radius;
	
	while (choice != 0)
	{
		printf("Area Calculation\n");
		printf("1. Square\n");
		printf("2. Rectangle\n");
		printf("3. Circle\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
	switch (choice)
	{
		case 0:
			printf("Exiting the program");
			break;
		case 1:
			
			printf("Enter the side of a square: ");
			scanf("%d", &square_side);
			
			if (square_side > 0) 
			{
				float area_square = (float) pow((int)square_side, 2);
				printf("Area of square with side %d is %.2f", square_side, area_square);
				break;
			}
			else
				printf("Invalid choice\n");
				printf("Enter the side again: ");
			break;
		
		case 2:
			
			printf("Enter the first side of a rectangle: ");
			scanf("%d", &rect_side1);
			
			while (rect_side1 <= 0)
			{
				printf("Invalid choice\n");
				printf("Enter the side again: ");
				scanf("%d", &rect_side1);
			}	
			
			printf("Enter the second side of a rectangle: ");
			scanf("%d", &rect_side2);

			while (rect_side2 <= 0)
			{
				printf("Invalid choice\n");
				printf("Enter the side again: ");
				scanf("%d", &rect_side2);
			} 
			
			float area_rect = (float) rect_side1 * rect_side2;
			printf("Area of the rectangle with sides %d and %d is %.2f", rect_side1, rect_side2, area_rect);
			
			break;
		
		case 3:
			
			printf("Enter ther radius of a circle: ");
			scanf("%d", &radius);
			
			while (radius <= 0)
			{
				printf("Invalid choice\n");
				printf("Enter the radius again: ");
				scanf("%d", &radius);
			}	
			
			float area_circle = (float) 3.14 * radius * radius;
			printf("The area of a circle with radius %d is %.2f", radius, area_circle);
			
		default:
			printf("Invalid choice\n");
			break;
	}
}
}