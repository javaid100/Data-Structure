/* Selection Sort by using Double Linked List  */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
 int data;
 struct Node* next;
 struct Node* prev;
} Node;

Node* head;

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
 while (temp->next != NULL)  { temp = temp->next; }
 temp->next = newNode;
 newNode->prev = temp;
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
 while (temp->next != NULL)  { temp = temp->next; }
 printf("Traverse from Tail: ");
 while (temp != NULL)
      {
       printf("%d  ", temp->data);
       temp = temp->prev;
      }
}

Node* SelectionSort (Node* head)
{
 Node* t1 = NULL;
 Node* t2 = NULL;
 int x;
 while (head)
      {
       t1 = head;
       t2 = head->next;
       while (t2)
            {
             if (t2->data < t1->data)
               {
                t1 = t2;
               }
             t2 = t2->next;
            }
       if (t1 != head)
         {
          x = t1->data;
          t1->data = head->data;
          head->data = x;
         }
       head = head->next;
      }
}

void main()
{
 printf("============= DOUBLY LINKED LIST =================== \n");
 printf(" 1  -  Insert at Head               \n");
 printf(" 2  -  Insert at Tail               \n");
 printf(" 3  -  Traverse from Head           \n");
 printf(" 4  -  Traverse from Tail           \n");
 printf(" 5  -  Selection Sort                   \n");
 printf(" 6  -  Exit                       \n\n");

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
                     TraverseFromHead();
                     printf("\n\n");
                     break;
              case 4:
                     TraverseFromTail();
                     printf("\n\n");
                     break;
              case 5:
                     printf("Sorting with Selection Sort: \n");
                     SelectionSort(head);
                     TraverseFromHead();
                     printf("\n");
                     TraverseFromTail();
                     printf("\n\n");
                     break;
              case 6:
                     exit(0);
              default:
                      printf("Wrong Choice Option. Try Again.");
                      printf("\n\n");
             }
      }
}


