/*Brian Robinson
 *Lab 6
 *Strings
*/

#define MAX 25

int length(char[]);
int replace(char[], int);
void copy(char[], char[]);
void reverse(char[], char[]);
void merge(char[], char[], char[]);
int prefix(char[], char[]);

int main (void)
{
	char str[MAX];
	char s2[MAX];
	char s3[MAX];
	
	printf("Enter first string: ");
	scanf("%s", str);
	printf("First string is %s", str);
	printf("Length of the string is %d\n", length(str));
	copy(str, s2);
	printf("Copy of first string is %s",  str);
	reverse(str, s2);
	printf("Reverse of the string %s is %s", str, s2);

	int position;
	replace(str, position);
	printf("Enter a position for the replacement operation: ");
	scanf("%d", &position);
	if (position == 0)
		printf("Invalid position");
	else
		printf("String after replacement operation is %s", str);
	
	printf("Enter second string: ");
	scanf("%s", s2);
	printf("Second string is %s", s2);
	merge(str, s2, s3);
	printf("Merged string is %s", s3);
	printf("Reverse of the string %s is %s", s2, s3);
	 
}


int length(char s[])
{
	int i;
	int counter = 0;

	while (s[i]!= '\0')
	{
		counter++;
		i++;
	}
	return counter;

}
void reverse(char s[], char s2[])
{
	int i;

	int len = length(s);
	for (i = 0; i < len; i++)
	{
		s2[len-1-i] = s[i];
		s2[len] = '\0';
	}
}
void copy(char s[], char s2[])
{
	int i;
	
	for (i = 0; s[i]!= '\0'; ++i)
	{
		s2[i] = s[i];
	}
	s2[i] = '\0';
}
int replace(char s[], int i)
{
	
	int num;
	num = length(s);
	if(i > num || i < 0)
	{
		return 0;
	}
	else
	{
		s[i] = '#';
		return 1;
	}
}
void merge(char s[], char s1[], char s3[])
{
	
}
int prefix(char s[], char s2[])
{
	
}	 
