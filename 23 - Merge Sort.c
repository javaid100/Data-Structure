/* Merge Sort by using Double Linked List  */

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

Node *split(struct Node *head)
{
 Node *fast = head, *slow = head;
 while (fast->next && fast->next->next)
      {
       fast = fast->next->next;
       slow = slow->next;
      }
 Node *temp = slow->next;
 slow->next = NULL;
 return temp;
}

Node *merge(Node *first, Node *second)
{
 if (!first)     {  return second;  }
 if (!second)    {  return first;   }

 Node* t = first->next;
 if (first->data < second->data)
   {
    first->next = merge(first->next,second);
    first->next->prev = first;
    first->prev = NULL;
    return first;
   }
 else
   {
    second->next = merge(first,second->next);
    second->next->prev = second;
    second->prev = NULL;
    return second;
   }
}

Node* MergeSort (Node* head)
{
 if (!head || !head->next)
   {
    return head;
   }
 Node *second = split(head);
 head = MergeSort(head);
 second = MergeSort(second);
 return merge(head,second);
}

void main()
{
 printf("============= DOUBLY LINKED LIST =================== \n");
 printf(" 1  -  Insert at Head               \n");
 printf(" 2  -  Insert at Tail               \n");
 printf(" 3  -  Traverse from Head           \n");
 printf(" 4  -  Traverse from Tail           \n");
 printf(" 5  -  Merge Sort                   \n");
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
                     printf("Sorting with Merge Sort: \n");
                     head = MergeSort(head);
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


