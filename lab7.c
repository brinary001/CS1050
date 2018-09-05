/* Brian Robinson
 * Lab 7
 * Pointers
*/
#include <stdio.h>
#include <stdlib.h>

char * copy(char *);
void clear(char *);
int length(char *);
char *  reverse(char *);
int search(char *, char);
char * merge(char *, char *);

int main (int argc, char **argv)
{
	
	if (argc < 1)
	{
		printf("Not enough paramters");
		return 0;
	}
	
	char *ptr = argv[1];
	int len = length(ptr);
	char *str = copy(ptr);
	char *rev = reverse(ptr);
	printf("First string is %s", ptr);
	printf("\nLength of string %s is %d", ptr, len);
	printf("\nCopy of the first string is %s", str);
	printf("\nReverse of the string %s is %s", ptr, rev);
	char character;
	printf("\nEnter a character for the search operation: ");
	scanf("%c", &character);
	int num = search(ptr, character);
	printf("Character %c is present at index %d in the string %s", character, num, ptr);
	char new_string[100];
	printf("\nEnter a string for the merge operation: ");
	scanf("%s", new_string);
	printf("Merged string is %s", merge(ptr, new_string));
	clear(str);

	return 0;
}

int length(char *s)
{
	int i = 0;
	while(*(s+i)!='\0')
	{
		i++;
	}
	return i;
}
char* copy(char *s)
{
	char *ptr = malloc(sizeof(char)*length(s)+1);
	
	int i;
	
	for (i = 0; *(s+i) != '\0'; ++i)
	{
		*(ptr+i) = *(s+i); 
	}
	return ptr;
}
void clear(char *s)
{
	free(s);
}
char* reverse(char *s)
{
	char *ptr = malloc(sizeof(char)*length(s)+1);
	int i;
	
	int len = length(s);
	for (i = 0; i < len; i++)
	{
		*(ptr+len-1-i)  = *(s+i);
		*(ptr+len) = '\0';
	}
	return ptr;
}
int search(char *s, char c)
{
	int i;
	int len = length(s);
	for (i = 0; i < len; i++)
	{
		if (*(s+i)  == c)
		{
			return i;
		}
	}
	return -1;	
}
char* merge(char* s, char* s1)
{
	char *ptr = malloc(sizeof(char)*(length(s)+length(s1)+1));
	int i,j;
	for (i = 0; *(s+i) != '\0'; ++i)
	{
		*(ptr+i) = *(s+i);
	}
	for (j = 0; *(s1+j) != '\0'; ++j)
	{
		*(ptr+i) = *(s1+j);
		i++;
	}
	*(ptr+i) = '\0';
	return ptr;
}	


