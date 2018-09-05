#include <stdio.h>

//Prototypes
void display_menu();
int check_option(int);
int check_amount(float);
float calculate_tax(float, float);

//Global variable
int income = 1;

int main(void) 

{
	float rate;
	
	printf("Filing Status\n");
	
	display_menu();
	
	
	int option = 3;
	printf("\nPlease make a selection: ");
	scanf("%d", &option);
	while (check_option(option) == 0)
	{
		
		printf("\nInvalid choice, your choices are: \n");
		display_menu();
		printf("\nPlease make a selection: ");
		scanf("%d", &option);
		
	}
	while (option != 0)
	{
		switch (option)
		{
			case 0:
				printf("\nExiting the tax calculator");
				break;
				
			case 1:
				
				printf("Enter the annual income: ");
				scanf("%d", &income);
				while (check_amount(income) == 0)
				{
					printf("Invalid income, enter the income again: ");
					scanf("%d", &income);
				}
				if (income > 0 && income < 20000)
					rate = .10;
				else if (income >= 20000 && income < 50000)
					rate = .20;
				else if (income >= 50000 && income < 100000)
					rate = .30;
				else if (income >= 100000 && income < 250000)
					rate = .35;
				else if	(income > 250000)
					rate = .40;
				break;
				
			case 2:
				printf("Enter the annual income: ");
				scanf("%d", &income);
				while (check_amount(income) == 0)
				{
					printf("Invalid income, enter the income again: ");
					scanf("%d", &income);
				}
				if (income >= 0 && income < 30000)
					rate = .10;
				else if (income >= 30000 && income < 60000)
					rate = .20;
				else if (income >= 60000 && income < 125000)
					rate = .30;
				else if (income >= 125000 && income < 300000)
					rate = .35;
				else if (income >= 300000)
					rate = .40;
				break;
			
			case 3:
				printf("Enter the annual income: ");
				scanf("%d", &income);
				while (check_amount(income) == 0)
				{
					printf("Invalid income, enter the income again: ");
					scanf("%d", &income);
				}
				if (income >= 0 && income < 50000)
					rate = .10;
				else if (income >= 50000 && income < 100000)
					rate = .20;
				else if (income >= 100000 && income < 250000)
					rate = .30;
				else if (income >= 250000 && income < 500000)
					rate = .35;
				else if (income >= 500000)
					rate = .40;
				break;
				
			default:
				break;
		}	
			
			int tax_rate = (int)(rate * 100);
			printf("---------------------\n");
			printf("Your tax rate is: %d%%", tax_rate);
			float tax = calculate_tax(income, rate);
			double net_income = (income - tax);
			printf("\nYou pay $%.2f in taxes", tax);
			printf("\nAfter taxes your net income is: $%.2f", net_income);	
				
			break;
	}
		
		if (option == 0)
			printf("Exiting the program.");
			
	return 0;
}
void display_menu()
{
	printf("(1) Single\n(2) Married\n(3) Head of Household\n(0) Quit Program");
}

int check_option(int option)
{
	if (option < 0 || option > 3)
		return 0;
	else 
		return 1;
}
int check_amount(float income)
{
	if (income <= 0)
		return 0;
	else 
		return 1;
}
float calculate_tax(float income, float rate)
{
	float tax = (income * rate);
	return tax;
}