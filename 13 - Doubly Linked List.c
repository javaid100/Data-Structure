// Double Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 int data;
 struct Node* next;
 struct Node* prev;
} Node;

Node* head = NULL;    // Pointer to Head Node
Node* tail = NULL;    // Pointer to Tail Node

void InsertAtHead (int x);
void InsertAtTail (int x);
void Search (int x);
void DeleteFromHead();
void DeleteFromTail();
void TraverseFromHead();
void TraverseFromTail();

Node* GetNewNode (int x)
{
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = x;
 newNode->next = NULL;
 newNode->prev = NULL;
 return newNode;
}

void InsertAtHead (int x)
{
 Node* temp = GetNewNode(x);
 if (head == NULL)
   {
    head = temp;
    return;
   }
 head->prev = temp;
 temp->next = head;
 head = temp;
}

void InsertAtTail (int x)
{
 Node* temp = head;
 Node* newNode = GetNewNode(x);
 if (head == NULL)
   {
    head = newNode;
    return;
   }
 while (temp->next != NULL)  { temp = temp->next; }   // Going to last Node
 temp->next = newNode;
 newNode->prev = temp;
}

void Search (int x)
{
 int pos = 0;
 if (head == NULL)
   {
    printf("Doubly Linked List is empty");
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
          printf("%d does not exist in the Doubly Linked List \n\n", x);
          break;
         }
      }
}

void DeleteFromHead()
{
 Node* temp = head;
 if (head == NULL)
   {
    printf("Doubly Linked List is empty. No elements to delete. \n\n");
    return;
   }
 head = head->next;
 if (head != NULL)     { head->prev = NULL; }
 printf("%d is deleted from the Doubly Linked List \n\n", temp->data);
 free(temp);
}

void DeleteFromTail()
{
 Node** s = &head;
 Node* temp = head;
 if (head == NULL)
   {
    printf("Doubly Linked List is empty. No elements to delete. \n\n");
    return;
   }
 while (temp->next !=  NULL)  { temp = temp->next; }
 Node* t = temp->prev;
 if ((*s)->next == NULL)      { *s = NULL;      }
 else                         { t->next = NULL; }
 printf("%d is deleted from the Doubly Linked List \n\n", temp->data);
 free(temp);
}

void TraverseFromHead()
{
 Node* temp = head;
 if (temp == NULL)
   {
    printf("Doubly linked list is empty.");
    return;
   }
 printf("Traverse from Head: ");
 while (temp != NULL)
      {
       printf("%d  ", temp->data);
       temp = temp->next;
      }
}

void TraverseFromTail()
{
 Node* temp = head;
 if (temp == NULL)
   {
    printf("Doubly linked list is empty.");
    return;
   }
 while (temp->next != NULL)  { temp = temp->next; }   // Going to last Node
 printf("Traverse from Tail: ");
 while (temp != NULL)
      {
       printf("%d  ", temp->data);
       temp = temp->prev;
      }
}

void main()
{
 printf("============= DOUBLY LINKED LIST =================== \n");
 printf(" 1  -  Insert at Head              \n");
 printf(" 2  -  Insert at Tail               \n");
 printf(" 3  -  Search                       \n");
 printf(" 4  -  Delete from Head              \n");
 printf(" 5  -  Delete from Tail              \n");
 printf(" 6  -  Traverse from Head           \n");
 printf(" 7  -  Traverse from Tail           \n");
 printf(" 8  -  Exit                       \n\n");

 int ch, y;

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
                     printf("Enter the value to search: ");
                     scanf("%d", &y);
                     Search(y);
                     break;
              case 4:
                     DeleteFromHead();
                     break;
              case 5:
                     DeleteFromTail();
                     break;
              case 6:
                     TraverseFromHead();
                     printf("\n\n");
                     break;
              case 7:
                     TraverseFromTail();
                     printf("\n\n");
                     break;
              case 8:
                     exit(0);
              default:
			          printf("Wrong Choice Option. Try Again.\n\n");      
            }
      }
}
