/*  Circular Linked List  */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 int data;
 struct Node* next;
} Node;

Node* tail = NULL;

void InsertAtStart (int x);
void InsertAtNthPos (int data, int n);
void Search();
void DeleteFromStart();
void DeleteFromNthPos (int n);
int NodeCount();
void Traverse();

Node* GetNewNode (int x)
{
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = x;
 newNode->next = NULL;
 return newNode;
}

void InsertAtStart (int x)
{
 Node* temp = GetNewNode(x);
 if (tail == NULL)
   {
    temp->next = temp;
    tail = temp;
    return;
   }
 else
   {
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
   }
}

void InsertAtNthPos (int data, int n)
{
 if (n > NodeCount()+1)
   {
    printf("Unable to locate the position \n");
    return;
   }
 Node* newNode = GetNewNode(data);
 Node* temp = tail->next;
 if (n == 1)
   {
    InsertAtStart(data);
    return;
   }
 else
   {
    for (int i=0; i<=n-3; i++)
       {
        temp = temp->next;
       }
    newNode->next = temp->next;
    temp->next = newNode;
   }
}

void Search (int x)
{
 int pos = 0;
 if (tail == NULL)
   {
    printf("Circular Linked List is empty");
    return;
   }
 Node* temp = tail->next;
 while (temp != NULL)
      {
       pos++;
       if (temp->data == x)
         {
           printf("%d is found at position %d \n\n", x, pos);
           return;
          }
        if (temp->next != NULL)
          {
           temp = temp->next;
          }
        else
          {
           printf("%d does not exist in the Circular Linked List \n\n", x);
           break;
          }
      }
}

void DeleteFromStart()
{
 Node* t1 = tail;
 Node* t2 = tail->next;
 if (tail == NULL)
   {
    printf("Circular Linked List is empty. No elements to delete. \n\n");
    return;
   }
 t1->next = t2->next;
 printf("%d is deleted from the Circular Linked List \n\n", t2->data);
 free(t2);
}

void DeleteFromNthPos (int n)
{
 if (n > NodeCount()+1)
   {
    printf("Unable to locate the position \n");
    return;
   }
 Node* t1 = tail->next;
 for (int i=0; i<n-2; i++)
    {
     t1 = t1->next;
    }
 Node* t2 = t1->next;
 t1->next = t2->next;
 printf("%d is deleted from the Circular Linked List \n\n", t2->data);
 free(t2);
}

int NodeCount()
{
 int count = 0;
 Node* temp = tail;
 if (tail != NULL)
   {
    do
      {
	   temp = temp->next;
 	   count++;
      }
    while (temp != tail);
   }
 return count;
}

void Traverse()
{
 Node* temp = tail;
 if (temp == NULL)
   {
    printf("Circular Linked list is empty.\n");
    return;
   }
 printf("Traversal: ");
 while (temp->next != tail)
      {
       temp = temp->next;
       printf("%d  ", temp->data);
      }
 printf("%d\n", temp->data);
}

int main ()
{
 printf("============ CIRCULAR LINKED LIST =================== \n");
 printf(" 1  -  Insert at Start              \n");
 printf(" 2  -  Insert at nth Position       \n");
 printf(" 3  -  Search                       \n");
 printf(" 4  -  Delete from Start            \n");
 printf(" 5  -  Delete from nth Position     \n");
 printf(" 6  -  Node Count                   \n");
 printf(" 7  -  Traversal                    \n");
 printf(" 8  -  Exit                       \n\n");

 int ch, y, z;

 while (-1)
      {
       printf("Enter the choice: ");
       scanf("%d", &ch);
       switch (ch)
             {
              case 1:
                     printf("Enter the value: ");
                     scanf("%d", &y);
                     InsertAtStart(y);
                     printf("\n");
                     break;
              case 2:
                     printf("Enter the value: ");
                     scanf("%d", &y);
                     printf("Enter the position: ");
                     scanf("%d", &z);
                     InsertAtNthPos (y, z);
                     printf("\n");
                     break;
              case 3:
                     printf("Enter the value to search: ");
                     scanf("%d", &y);
                     Search(y);
                     break;
              case 4:
                     DeleteFromStart();
                     break;
              case 5:
                     printf("Enter the position: ");
                     scanf("%d", &z);
                     DeleteFromNthPos (z);
                     break;
              case 6:
                     printf("Total Number of Nodes: %d\n", NodeCount());
                     printf("\n");
                     break;
              case 7:
                     Traverse();
                     printf("\n");
                     break;
              case 8:
                     exit(0);
              default:
                      printf("Wrong Choice Option. Try Again.\n\n");
            }
      }
}
