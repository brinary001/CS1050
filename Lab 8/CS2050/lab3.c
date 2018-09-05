/* Brian Robinson
 * br7pc
 * Section B
 * Lab 3
*/
#include <stdio.h>
#include <stdlib.h>

void int_to_binary(int number);
int ConvertBinaryToDecimal(int n);

int main (int argc, char* argv[])
{
	int dec;
	int i,x;
	FILE* fp;
	fp = fopen(argv[1], "r");
		
	if (fp == NULL)
	{
		printf("NULL FILE\n");
		return 0;
	}
	
	
	for (i = 0; i < 5; i++)
	{
		fscanf(fp, "%d", &x);
		dec = ConvertBinaryToDecimal(x);
		printf("%d in binary = % d in decimal", x, dec);
	}
	for (i = 0; i < 5; i++)
	{
		fscanf(fp, "%d", &x);
		int_to_binary(x);
	}
	fclose(fp);
	return 0; 
}

void int_to_binary(int number)
{
	if (number > 1)
	{
		int_to_binary(number/2);
	}
	printf("%d", number % 2);	
}

int ConvertBinaryToDecimal(int n)
{
	if (!(n/10)) return (n);
	return (n % 10 + ConvertBinaryToDecimal(n/10) * 2);
}

 
