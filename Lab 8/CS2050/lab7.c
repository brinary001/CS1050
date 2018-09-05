/* Brian Robinson
 * br7pc
 * Section B
 * Lab 7
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {

        int number;
        struct node* next;

} node;

//node* add_node(node* head, int number);
node* read_file(char* filename);
void print_list(node* head);
void free_list(node* head);
node* delete_from_file(char* filename, node* head);

int main (int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Incorrect input\nCorrect input: ./a.out <input file> <delete file>");
		return -1;
	}
	node* head = NULL;
	head = read_file(argv[1]);
	printf("List before nodes have been deleted\n");	
	print_list(head);
	head = delete_from_file(argv[2], head);
	printf("List after nodes have been deleted\n");
	print_list(head);
	free_list(head);
	return 0;
}

node* read_file(char* filename) //Read in file contents
{
	int num, i;
	node* head = (node*)malloc(sizeof(node));
	FILE* fp = fopen(filename, "r");
	fscanf(fp, "%d", &num);
	if (fp == NULL)
	{
		printf("File not found\n");
		return NULL;
	}
	head->number = num;
	head->next = NULL;
	for (i = 0; i < 13; i++)
	{
		fscanf(fp, "%d", &num);
		node* currentNode = (node*)(malloc(sizeof(node)));
		currentNode->number = num;
		currentNode->next = NULL;
		if (head->next == NULL)
		{
			head->next = currentNode;
		}
		else
		{
			node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = currentNode;
		}
	}
	fclose(fp);
	return head;
}

void print_list(node* head)//Print the contents of the list both before and after deleting
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

void free_list(node* head)//Free nodes in the list
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
			free(next_node);
                }
        } 
}      

node* delete_from_file(char* filename, node* head)//Read in file and delete the matching numbers
{
	node* prev;
	node* current;
	node* temp;
	
	FILE* file = fopen(filename, "r");
	int delete, i;
	
	for (i = 0; i < 5; i++)
	{
		fscanf(file, "%d", &delete);
		if (delete == head->number)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		else
		{
			prev = head;
			current = head->next;
			while (current != NULL && current->number != delete)
			{
				prev = current;
				current = current->next;
			}
			if (current != NULL)
			{
				temp = current;
				prev->next = current->next;
				free(temp);
			}
		}
	}
	fclose(file);
	return head;
}
