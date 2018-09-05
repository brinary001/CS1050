#include <stdio.h>
#include <stdlib.h>


typedef struct node {

        int number;
        struct node* next;

} node;

node* add_node(node* head, int number);
void print_list(node* head);
void free_list(node* head);

int main (int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Insufficient arguments");
		return -1;
	}
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("File not found\n");
		return -1;
	}
	int num;
	node* head = NULL;
	while (feof(fp) == 0)
	{
		fscanf(fp, "%d", &num);
		head = add_node(head, num);
	}
	
	fclose(fp);	
	print_list(head);
	free_list(head);
	return 0;
}

node* add_node(node* head, int number)
{
	node* new_node = (node*)malloc(sizeof(node));

	new_node->number = number;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
	}
	else 
	{
		node* next_node = head;
		while (next_node->next != NULL)
		{
			next_node = next_node->next;
		}
		next_node->next = new_node;
	}
	return head;
}

void print_list(node* head)
{
	if (head == NULL)
        {
        	printf("Head is null\n");
        }
        else 
        {
                node* next_node = head;
                while (next_node->next != NULL)
                {
			printf("%d\n", next_node->number);
                        next_node = next_node->next;
                }
	}         
}

void free_list(node* head)
{
	if (head == NULL)
        {
               return;
        }
        else 
        {
                node* next_node = head;
		node* prev_node = head;
                while (next_node->next != NULL)
                {
			prev_node = next_node;
                        next_node = next_node->next;
			free(prev_node);
                }
        } 
}      

