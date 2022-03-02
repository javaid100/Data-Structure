/* Implementation of Stack using Pointers.  */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Defining the stack structure
struct stack
{
 int stk[MAX];
 int top;
};
typedef struct stack STACK;

void push();
int pop();
void display();

// Initializing the stack (i.e. top= -1 )
void init_stk (STACK *st)
{
 st->top = -1;
}

// Entering the elements into stack
void push (STACK *st)
{
 int num;
 if (st->top == MAX-1)
   {
    printf("Stack Overflow\n");
    return;
   }
 else
   {
    printf("Enter the element to be pushed: ");
    scanf("%d",&num);
    st->top++;
    st->stk[st->top] = num;
   }
}

// Deleting an element from the stack
int pop (STACK *s)
{
 int num;
 if (s->top == -1)
   {
    printf("Stack is Empty");
    return s->top;
   }
 else
   {
    num = s->stk[s->top];
    printf("Popped element is = %d\n", num);
    s->top--;
   }
 return num;
}

// Displaying the stack
void display (STACK *s)
{
 int i;
 if (s->top == -1)
   {
    printf("Stack is empty\n");
   }
 else
   {
    printf("The status of the stack is \n");
    for (i=s->top; i>=0; i--)
       {
        printf("%d\n", s->stk[i]);
       }
   }
}

void main()
{
 int option, choice;
 STACK ptr;
 init_stk(&ptr);

 printf("Stack Operations ----------------------\n");
 printf(" 1  -->  PUSH                \n");
 printf(" 2  -->  POP                 \n");
 printf(" 3  -->  DISPLAY             \n");
 printf(" 4  -->  EXIT                \n");
 printf("---------------------------------------\n");

 while (1)
      {
       printf("\nEnter your option: ");
       scanf("%d", &choice);

       switch (choice)
             {
              case 1:
                     push(&ptr);
                     break;
              case 2:
                     pop(&ptr);
                     break;
              case 3:
                     display(&ptr);
                     break;
              case 4:
                     exit(0);
              default:
                     printf("\nEnter correct option! Try again.");
             }
      }
}
