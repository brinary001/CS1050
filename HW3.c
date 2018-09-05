#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototypes
int *create_id(int);
int* create_score(int);
float* average_score(int*, int*, int*, int);
char* calculate_grade(float*, int);
float median(int*, int);
void print_scorecard(int*, int*, int*, int*, float*, char*, int);
int search_id(int*, int, int);
void histogram(char*, int);


int main(int argc, char **argv)
{
	srand(time(NULL));
	
	if (argc < 2)
	{
		printf("Not enough parameters\n");
		return 0;
	}	
		
	int size = atoi(argv[1]);
   
   	int *ID = create_id(size);
    
    int input_id;
    
    int *c1score = create_score(size);
    int *c2score = create_score(size);
    int *c3score = create_score(size);
    
	float *average = average_score(c1score, c2score, c3score, size);
    
	char *grades = calculate_grade(average, size);
    
	//float med = median(scores, size);
        
	print_scorecard(ID, c1score, c2score, c3score, average, grades, size);
	printf("Enter the ID to search: ");
	scanf("%d", &input_id);
    	int validate_id = search_id(ID, size, input_id);
    	while (validate_id < 0) 
	{
        	printf("\nInvalid ID. Please enter another ID: ");
        	scanf("%d", &input_id);
        	validate_id = search_id(ID, size, input_id);
    	}
    
            printf("Course 1: %d\n", c1score[validate_id]);
            printf("Course 2: %d\n", c2score[validate_id]);
            printf("Course 3: %d\n", c3score[validate_id]);
            printf("Average Score: %.2f\n", *average);
            printf("Grade %c\n", *grades);
	    //printf("Median score for course 1 is %.2f\n", med);
	    //printf("\nMedian score for course 2 is %.2f\n", med);
            //printf("\nMedian score for course 3 is %.2f\n", med);

	        histogram(grades, size);
        
	
	
}


int *create_id(int size)
{
    int *ptr = malloc(size * sizeof(int));
    
	int id;
	id = (rand() % 900 )+ 99;
	
	int i;
	for (i=0; i < size; i++) 
	{
        	*(ptr+i) = (rand() % 99) + 900;
    	}
	
    
	return ptr;
}


int* create_score(int size)
{
	int *ptr = malloc(sizeof(int)*size);
	int i;
	for (i = 0; i < size; i++) {
		*(ptr+i) = rand() % 51 + 50;
	}
	return ptr;
}


float* average_score(int* course1, int* course2, int* course3, int size)
{
	float *ptr = malloc(sizeof(float)*size);
	int i, total;
	for (i = 0; i < size; ++i)
	{
		total = *(course1+i) + *(course2+i) + *(course3+i);
		*(ptr+i) = ((float)total)/3;
	}
	
	return ptr;
}


char *calculate_grade(float* grade, int size)
{
	char *ptr = malloc(sizeof(char) * size);
	int i;
	for (i = 0; i < size; i++)
	{
		if (*(grade+i) >= 90 && *(grade+i) <= 100) {
			*(ptr+i) = 'A';
        }
        else if (*(grade+i) >= 80 && *(grade+i) < 90) {
           		*(ptr+i) = 'B';
        }
		else if (*(grade+i) >= 70 && *(grade+i) < 80) {
			*(ptr+i) = 'C';
        }
		else if (*(grade+i) >= 60 && *(grade+i) < 70) {
			*(ptr+i) = 'D';
        }
		else if (*(grade+i) < 60)  {
			*(ptr+i) = 'F';
        }
		
	}
	return ptr;
}

float median(int *scores, int size)
{
	float med_scores;
	int i, j;
    
	for (i = 0; i < *scores - 1; i++)
	{
		for (j = i + 1; j < *scores; j++)
		{
			if (*(scores+j) < *(scores+i))
			{
				med_scores = *(scores+i);
				*(scores+i) = *(scores+j);
				*(scores+j) = med_scores;
			}
		}
	}

	int mid = size / 2;
	if(size % 2 == 0)
	{
	
		
		med_scores=((float)*(scores+mid)+*(scores+mid -1))/2;
	}
	else
	{
		med_scores = *(scores +mid);
	}
	return med_scores;
}


void print_scorecard(int* ID, int* course1, int* course2, int* course3, float* average, char* grades, int size)
{
	printf("----------------------------------------------------------------------------------------\n");
	printf("\tID\tCourse 1\tCourse 2\tCourse 3\tAverage \tGrade\n");
	printf("----------------------------------------------------------------------------------------\n");
    	int i;
	for (i = 0; i < size; i++) 
	{
        	printf("%10d %10d %15d %15d %16.2f  %11c\n", *(ID+i), *(course1+i), *(course2+i), *(course3+i), *(average+i), *(grades+i));
    	}
}


int search_id(int* IDs, int size, int id)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		if (*(IDs+i) == id)
		{
			return i;
		}
	}
	return -1;
}
void histogram(char* grade, int size)
{
   	printf("\nGrade Histogram\n");
    
    int a, b, c, f = 0;
    int d = 0;
	int i,j;
	for (i = 0; i < size; i++) {
        switch (*(grade + i)) {
            case 'A':
                a++;
                break;
            case 'B':
                b++;
                break;
            case 'C':
                c++;
                break;
            case 'D':
                d++;
                break;
            case 'F':
                f++;
                break;
                
            default:
                break;
        }
    }
    
    printf("\nA: ");
    for (int i=0;i<a; i++)
        printf("*");
    printf("\nB: ");
    for (int i=0;i<b; i++)
        printf("*");
    printf("\nC: ");
    for (int i=0;i<c; i++)
        printf("*");
    printf("\nD: ");
    for (int i=0;i<d; i++)
        printf("*");
    printf("\nF: ");
    for (int i=0;i<f; i++)
        printf("*");

    printf("\n");
}

