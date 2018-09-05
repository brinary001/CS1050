#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) 
{
	char *str;
	str = malloc(sizeof(char)*10);
	
	scanf("%s", str);	
	if (argc < 2) 
	{
		printf("\n Not enough parameters \n");
		return 0; 
	}
		char *x = argv[1]; 
		char *y = copy(x);
		int len = length(x);
		printf("\n Input string is %s ", x);
		printf("\n Length of the string is %d ", len); 
		printf("\n Copy of the string is %s ", y);
		char *rev=reverse(x);
		printf("\n Reverse of the string %s is %s \n",x, rev);
		clear(y); 
		clear(rev);
		return 0;
}
void copy(char *s)
{
	int i;

	int len = length(s);

	/*for(i=0; i<len; i++)
	{
		
	}*/
}
int length(char *a)
{
	int length = 0, i = 0;

	while(*(a+i) != '\0')
	{
		i++;
		length++;
	}

	return length;
}
void clear(char *s)
{
	
}
char* reverse(char *s)
{
	
}