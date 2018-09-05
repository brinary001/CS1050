/*Brian Robinson
 * br7pc
 *HW1 is due on Wednesday
 */

#include <stdio.h>

int main (void)
{
	int choice;
	int year;
	float amount;
	float checking_interest;
	float savings_interest;
	float fixed_interest;
    float checking_amount;
	float amount_ci;
	
    int i;
    float product=1.0;
		
	printf("Bank account type\n");
	printf("1. Checking\n");
	printf("2. Saving\n");
	printf("3. Fixed Deposit\n");
	printf("Please make a selection: ");
	scanf("%d", &choice);

	
	
	while (choice < 1 || choice > 3)
	{
		printf("Incorrect choice\n");
		printf("Bank account type\n");
		printf("1. Checking\n");
		printf("2. Saving\n");
		printf("3. Fixed Deposit\n");
		printf("Please make a selection: ");
		scanf("%d", &choice);
	}
	switch (choice)
	{
		case 1:
			printf("Enter a year: ");
			scanf("%d", &year);
			
			while (year < 1 || year > 10)
			{
				printf("Incorrect value year should be between 1-10\n");
				printf("Enter a year: ");
				scanf("%d", &year);
			}
			printf("Enter the amount: ");
			scanf("%f", &amount);
			
			while (amount <= 0)
			{
				printf("Incorrect value enter the amount again: ");
				scanf("%f", &amount);
			}
			
			checking_interest = .0125;
			
			product=1.0;
			for (i=0; i<year; i++ )
			{
				product=product*1.0125;
			}
			
			float amount_ci = product*amount;
			float  checking_interest = amount_ci - amount;
			printf("Total amount after %d years is $%.2f\n", year, amount_ci );
			printf("Total interest earned on the amount $%.2f is $%.2f", amount, checking_interest);
		break;
		case 2:
			printf("Enter a year: ");
			scanf("%d", &year);
			
			while (year < 1 || year > 10)
			{
				printf("Incorrect value year should be between 1-10\n");
				printf("Enter a year: ");
				scanf("%d", &year);
			}
			
			printf("Enter the amount: ");
			scanf("%f", &amount);
			
			while (amount <= 0)
			{
				printf("Incorrect value enter the amount again: ");
				scanf("%f", &amount);
			}
			
			savings_interest = .033;
			
			product = 1.0;
			for (i = 0; i < year; i++)
			{
				product = product * 1.033;
			}
			
			amount_ci = product*amount;
			savings_interest = amount_ci - amount;
			printf("Total amount after %d years is $%.2f\n", year, amount_ci);
			printf("Total interest earned on the amount $%.2f is $%.2f", amount, savings_interest);
		break;
		case 3:
			printf("Enter a year: ");
			scanf("%d", &year);
			
			while (year < 1 || year > 10)
			{
				printf("Incorrect value year should be between 1-10\n");
				printf("Enter a year: ");
				scanf("%d", &year);
			}
			
			printf("Enter the amount: ");
			scanf("%f", &amount);
			
			while (amount <= 0)
			{
				printf("Incorrect value enter the amount again: ");
				scanf("%f", &amount);
			}
			
			fixed_interest = .0575;

                        product = 1.0;
                        for (i = 0; i < year; i++)
                        {
                                product = product * 1.0575;
                        }

                        amount_ci = product*amount;
                        fixed_interest = amount_ci - amount;
                        printf("Total amount after %d years is $%.2f\n", year, amount_ci);
                        printf("Total interest earned on the amount $%.2f is $%.2f", amount, fixed_interest);
		break;
		
}

}	
