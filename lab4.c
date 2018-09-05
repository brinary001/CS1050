/* Brian Robinson
 * br7pc
 * random number generator
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_option();
int check_guess(int);
int throw_dice();
int lucky_seven(int, int);

int main (void)
{
	srand(time(NULL));

	int x;

	//x = random_number();

	
	display_option();
	
	int guess;
	printf("Please select an option: ");
	scanf("%d", &guess);

	while (check_guess(guess) == 0)
	{
		printf("Invalid choice\n");
		display_option();
		printf("Please select an option: ");
		scanf("%d", &guess);
	}
	
	int sum = throw_dice();
	
	int result = lucky_seven(sum,guess);	
	if (result == 1)
		printf("You won! Your guess is correct. The dice's sum is %d", sum);
	else if (result == 0)
		printf("You lost! Your guess is incorrect. The dice's sum is %d", sum);

}

void display_option()
{
	printf("Enter your guess (1) Lucky 7 (2) above 7 (3) below 7:\n");
}
int check_guess(int guess)
{
	if (guess < 1 || guess > 3)
		return 0;
	else
		return 1;
}
int throw_dice()
{
	int x,y;
	x = rand() % 6+1;
	y = rand() % 6+1;
	
	return x + y;  
}
int lucky_seven(int x, int guess)
{
	switch(guess)
	{
		case 1:
			if (x == 7)
				return 1;
			else
				return 0;
		case 2:
			if (x > 7)
				return 1;
			else
				return 0;
		case 3:
			if (x < 7)
				return 1;
			else
				return 0;
	}	
}	
