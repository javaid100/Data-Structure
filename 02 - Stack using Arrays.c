/*  C Program to implement Stack using an Array  */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct stack
{
    int stk[MAX];
    int top;
};
typedef struct stack STACK;
STACK s;

void push();
int pop();
void display();

// Entering the elements into stack
void push()
{
 int num;
 if (s.top == (MAX-1))
   {
    printf("Stack Overflow\n");
    return;
   }
 else
   {
    printf("Enter the element to be pushed: ");
    scanf("%d",&num);
    s.top++;
    s.stk[s.top] = num;
   }
}

// Deleting an element from the stack
int pop()
{
 int num;
 if (s.top == -1)
   {
    printf("Stack is Empty");
    return s.top;
   }
 else
   {
    num = s.stk[s.top];
    printf("Popped element is = %d\n", num);
    s.top--;
   }
 return num;
}

// Displaying the stack
void display()
{
 int i;
 if (s.top == -1)
   {
    printf("Stack is empty\n");
   }
 else
   {
    printf("The status of the stack is \n");
    for (i=s.top; i>=0; i--)
      {
       printf("%d\n", s.stk[i]);
      }
   }
}

void main()
{
 int choice;
 int option = -1;
 s.top = -1;

 printf("Stack Operations ----------------------\n");
 printf(" 1  -->  PUSH                \n");
 printf(" 2  -->  POP                 \n");
 printf(" 3  -->  DISPLAY             \n");
 printf(" 4  -->  EXIT                \n");
 printf("---------------------------------------\n");

 for (int i=0; i<1000; i++)
    {
     printf("\nEnter your choice: ");
     scanf("%d", &choice);

     switch (choice)
           {
            case 1:
                   push();
                   break;
            case 2:
                   pop();
                   break;
            case 3:
                   display();
                   break;
            case 4:
                   exit(0);
            default:
                   printf("\nEnter correct option! Try again.");
           }
    }
}
