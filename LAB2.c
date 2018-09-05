/*Brian Robinson
 * br7pc
 * June 13, 2016
 */
#include<stdio.h>
#include<math.h>
int main (void)
{
	

	int a,b,c;

	printf("\nEnter the first side: ");

	scanf("%d",&a); 
	while (a <= 0) {
		printf("\nInvalid value enter the side again: ");
		scanf("%d", &a);
	}
	
	printf("Enter the second side:");
	scanf("%d", &b);

	while (b <= 0) {
		printf("\nInvalid value enter the side again: ");
		scanf("%d", &b);
	}
	printf("Enter the third side: \n");
	scanf("%d", &c);

	while (c <= 0 ) {
		printf("Invalid value enter the side again: \n");
		scanf("%d", &c);
	}
	
	if(a+b >c && b+c>a && c+a>b) { 
		
	float p = ((float)a+b+c)/2;
	float area = (float) sqrt(p*(p-a)*(p-b)*(p-c));
	printf("Area of the traingle is %f", area);
	
	}
	else { 
	printf("Three sides do not form a triangle");
}
}


