/*  Linked-List   */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 int data;
 struct Node* next;
} Node;

Node* head = NULL;

void InsertAtHead (int x);
void InsertAtTail (int x);
void InsertAtNthPos (int data, int n);
void Search();
void DeleteFromHead();
void DeleteFromTail();
void DeleteFromNthPos (int n);
void Traverse();

int count = 0;

Node* GetNewNode (int x)
{
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = x;
 newNode->next = NULL;
 return newNode;
}

void InsertAtHead (int x)
{
 Node* temp = GetNewNode(x);
 count++;
 if (head == NULL)
   {
    head = temp;
    return;
   }
 temp->next = head;
 head = temp;
}

void InsertAtTail (int x)
{
 Node* temp = head;
 Node* newNode = GetNewNode(x);
 count++;
 if (head == NULL)
   {
    head = newNode;
    return;
   }
 while (temp->next != NULL)    { temp = temp->next; }
 temp->next = newNode;
}

void InsertAtNthPos (int data, int n)
{
 if (n > count+1)
   {
    printf("Unable to locate the position \n");
    return;
   }
 Node* newNode = GetNewNode(data);
 Node* temp = head;
 if (n == 1)
   {
    count++;
    InsertAtHead(x);
    return;
   }
 for (int i=0; i<n-2; i++)
    {
     temp = temp->next;
    }
 count++;
 newNode->next = temp->next;
 temp->next = newNode;
}

void Search (int x)
{
 int pos = 0;
 if (head == NULL)
   {
    printf("Linked List is empty");
    return;
   }
 Node* temp = head;
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
           printf("%d does not exist in the Linked List \n\n", x);
           break;
          }
      }
}

void DeleteFromHead()
{
 Node* temp = head;
 if (head == NULL)
   {
    printf("Linked List is empty. No elements to delete. \n\n");
    return;
   }
 count--;
 head = head->next;
 printf("%d is deleted from the Linked List \n\n", temp->data);
 free(temp);
}

void DeleteFromTail()
{
 Node *t1, *t2;
 if (head == NULL)
   {
    printf("Linked List is empty. No elements to delete. \n\n");
    return;
   }
 if (head->next == NULL)
   {
    count--;
    printf("%d is deleted from the Linked List \n\n", head->data);
    free(head);
    head = NULL;
    return;
   }
 t1 = head;
 while (t1->next != NULL)
      {
       t2 = t1;
       t1 = t1->next;
      }
 count--;
 t2->next = NULL;
 printf("%d is deleted from the Linked List \n\n", t1->data);
 free(t1);
}

void DeleteFromNthPos (int n)
{
 if (n > count+1)
   {
    printf("Unable to locate the position \n");
    return;
   }
 Node* t1 = head;
 for (int i=0; i<n-2; i++)
    {
     t1 = t1->next;
    }
 count--;
 Node* t2 = t1->next;
 t1->next = t2->next;
 printf("%d is deleted from the Linked List \n\n", t2->data);
 free(t2);
}

void Traverse()
{
 Node* temp = head;
 if (temp == NULL)
   {
    printf("Linked list is empty.\n");
    return;
   }
 printf("There are %d elements in linked list.\n", count);
 printf("Traversal: ");
 while (temp->next != NULL)
      {
       printf("%d  ", temp->data);
       temp = temp->next;
      }
 printf("%d\n", temp->data);
}

int main ()
{
 printf("================ LINKED LIST =================== \n");
 printf(" 1  -  Insert at Head               \n");
 printf(" 2  -  Insert at Tail               \n");
 printf(" 3  -  Insert at nth Position       \n");
 printf(" 4  -  Search                       \n");
 printf(" 5  -  Delete from Head             \n");
 printf(" 6  -  Delete from Tail             \n");
 printf(" 7  -  Delete from nth Position     \n");
 printf(" 8  -  Traversal                    \n");
 printf(" 9  -  Exit                       \n\n");

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
                     InsertAtHead(y);
                     printf("\n");
                     break;
              case 2:
                     printf("Enter the value: ");
                     scanf("%d", &y);
                     InsertAtTail(y);
                     printf("\n");
                     break;
              case 3:
                     printf("Enter the value: ");
                     scanf("%d", &y);
                     printf("Enter the position: ");
                     scanf("%d", &z);
                     InsertAtNthPos (y, z);
                     printf("\n");
                     break;
              case 4:
                     printf("Enter the value to search: ");
                     scanf("%d", &y);
                     Search(y);
                     break;
              case 5:
                     DeleteFromHead();
                     break;
              case 6:
                     DeleteFromTail();
                     break;
              case 7:
                     printf("Enter the position: ");
                     scanf("%d", &z);
                     DeleteFromNthPos (z);
                     break;
              case 8:
                     Traverse();
                     printf("\n");
                     break;
              case 9:
                     exit(0);
              default:
                      printf("Wrong Choice Option. Try Again.\n\n");
            }
      }
}
