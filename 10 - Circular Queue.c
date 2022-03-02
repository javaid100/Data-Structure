/* Implementation of Circular Queue using an Array  */

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define false (1==0)
#define true  (1==1)

#define MAX 5

int queue_array[MAX];
int front = -1, rear =-1;

bool isFull()
{
 if ((front == rear+1) || (front == 0 && rear == MAX-1))
   {
    return true;
   }
 else
   {
    return false;
   }
}

bool isEmpty()
{
 if (front == -1)
   {
    return true;
   }
 else
   {
    return false;
   }
}

void enQueue (int element)
{
 if (isFull())
   {
    printf("\n\nQueue Overflow!! \n");     // Overflow and Full are same terms
   }
 else
   {
    if (front == -1)
      {
       front = 0;
      }
    rear = (rear+1)%MAX;
    queue_array[rear] = element;
    printf("\nInserted -> %d", element);
   }
}

void deQueue()
{
 if (isEmpty())
   {
    printf("Queue is empty !! \n");
   }
 else
   {
    if (front == rear)
      {
       front = -1;
       rear = -1;
      }              /* Queue has only one element, so we reset the queue after dequeing it. */
    else
      {
       front = (front+1)%MAX;
      }
     printf("\nDeleted element -> %d \n", queue_array[front]);
    }
}

void display()
{
 int i;
 if (isEmpty())
   {
    printf(" \nEmpty Queue\n");
   }
 else
   {
    printf("\nFront -> %d ",front);
    printf("\nItems -> ");
    for (i=front; i!=rear; i=(i+1)%MAX)
       {
        printf("%d ",queue_array[i]);
       }
    printf("%d ",queue_array[i]);
    printf("\nRear -> %d \n", rear);
   }
}

void main()
{
 deQueue();

 enQueue(1);
 enQueue(2);
 enQueue(3);
 enQueue(4);
 enQueue(5);

 // Fails to enqueue because front == 0 && rear == MAX - 1
 enQueue(6);

 display();

 deQueue();

 display();

 enQueue(7);
 display();

 // Fails to enqueue because front == rear + 1
 enQueue(8);
}
