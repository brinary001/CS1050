/*Brian Robinson
br7pc
Lab 8
*/
#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH 25

typedef struct Node {
  char* word;
  struct Node* nextWord;
} Node;

Node* remove_from_front(Node** head);
Node* add_to_back(Node* head, char* word);
Node* add_to_front(Node* head, char* word);
Node* remove_from_back(Node** head);
void print(Node* head);
void menu ();

int main(int argc, char* argv[])
{
  Node* head1 = (Node*)malloc(sizeof(Node));
  //Node* hold = NULL;
  //Node* head2 = (Node*)malloc(sizeof(Node));
  head1 = NULL;
  //head2 = NULL;

  if (argc != 1)
  {
    printf("Incorrect usage.  Just use './a.out'\n");
    return -1;
  }
  int choice;
  while (choice != -1)
  {
    menu();
    scanf("%d", &choice);
    char* word = malloc(sizeof(char)*MAX_LENGTH);
    if (choice == 1)
    {
      printf("Enter a word to add to the document: ");
      scanf("%s ", word);
      head1 = add_to_front(head1, word);
      print(head1);
    }
    /*if (choice == 2)
    {
      hold = remove_from_front(&head1);
      add_to_front(head1, word);

    }

    if (choice == 3)
    {

    }*/
  }

  return 0;
}

void menu()
{
  printf("\nEnter '1' to add a word to the sentence\n");
  printf("Enter '2' to undo\n");
  printf("Enter '3' to redo\n");
  printf("Enter '-1' to exit:");
}
Node* add_to_back(Node* head, char* word)
{
  Node* temp = (Node*)malloc(sizeof(Node));
  temp = head;
  while (temp != NULL)
  {
    temp = temp->nextWord;
  }
  temp->word = word;
  temp->nextWord = NULL;
  return head;
}
Node* add_to_front(Node* head, char* word)
{
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->word = word;
  temp->nextWord = head;
  head = temp;

  return head;
}
/*Node* remove_from_back(Node** head)
{

}*/
Node* remove_from_front(Node** head)
{
  if (head == NULL)
  {
    printf("No head");
    return NULL;
  }

    Node* temp = *head;
    *head = (*head)->nextWord;
    return temp;
}
void print(Node* head)
{
  Node* temp = head;
  while (temp != NULL)
  {
    printf("%s", temp->word);
    temp = temp->nextWord;
  }
}
