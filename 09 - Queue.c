/*  C Program to Implement a Queue using an Array  */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_array[MAX];
int rear = - 1;
int front = - 1;

// Insert element to queue
void enQueue()
{
 int item;
 if (rear == MAX-1)
   {
    printf("Queue Overflow \n");
   }
 else
   {
    if (front == - 1)
      {
       front = 0;
      }
    printf("Inset the element in queue : ");
    scanf("%d", &item);
    rear++;
    queue_array[rear] = item;
   }
}

// Delete element from queue
void deQueue()
{
 if (front == - 1 || front > rear)
   {
    printf("Queue is Empty \n");
   }
 else
   {
    printf("Element deleted from queue is : %d\n", queue_array[front]);
    front++;
   }
}

// Display all elements of queue
void display()
{
 if (front == -1)
   {
    printf("Queue is empty \n");
   }
 else
   {
    printf("Queue is : \n");
    for (int i=front; i<=rear; i++)
       {
        printf("%d ", queue_array[i]);
       }
    printf("\n");
   }
}

void main()
{
 int choice;

 printf("-----------------------------------------\n");
 printf(" 1  -->  enQUEUE                \n");
 printf(" 2  -->  deQUEUE                \n");
 printf(" 3  -->  DISPLAY                \n");
 printf(" 4  -->  Exit                   \n");
 printf("-----------------------------------------\n");

 for (int j=0; j<1000; j++)
    {
     printf("\nEnter your choice : ");
     scanf("%d", &choice);

     switch (choice)
           {
            case 1:
                   enQueue();
                   break;
            case 2:
                   deQueue();
                   break;
            case 3:
                   display();
                   break;
            case 4:
                   exit(0);
            default:
                    printf("Invalid choice \n");
           }
    }
}
