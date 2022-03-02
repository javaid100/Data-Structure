/* Insertion Sort by using Double Linked List  */

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

void insert(Node** head, Node* t1)
{
 Node* t2;
 if (*head == NULL)
   {
    *head = t1;
   }
 else if ((*head)->data >= t1->data)
    {
     t1->next = *head;
     t1->next->prev = t1;
     *head = t1;
    }
 else
    {
     t2 = *head;
     while (t2->next != NULL && t2->next->data < t1->data)
          {
           t2 = t2->next;
          }
     t1->next = t2->next;
     if (t2->next != NULL)
       {
        t1->next->prev = t1;
       }
     t2->next = t1;
     t1->prev = t2;
    }
}

void InsertionSort (Node** head)
{
 Node* s1 = NULL;
 Node* s2 = *head;
 while (s2 != NULL)
      {
       Node* next = s2->next;
       s2->prev = s2->next = NULL;
       insert(&s1, s2);
       s2 = next;
      }
 *head = s1;
}

void main()
{
 printf("============= DOUBLY LINKED LIST =================== \n");
 printf(" 1  -  Insert at Head               \n");
 printf(" 2  -  Insert at Tail               \n");
 printf(" 3  -  Traverse from Head           \n");
 printf(" 4  -  Traverse from Tail           \n");
 printf(" 5  -  Insertion Sort                   \n");
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
                     printf("Sorting with Insertion Sort: \n");
                     InsertionSort(&head);
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


