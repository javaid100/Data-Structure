// Decimal-to-Binary Conversion using Stacks.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct stack
{
 int data[MAX];
 int top;
};
typedef struct stack STACK;

void push (STACK *s, int x)
{
 if (s->top == MAX-1)
   {
    printf("Stack Overflow\n");
   }
 else
   {
    s->top = s->top+1;
    s->data[s->top] = x;
   }
}

int pop(STACK *s)
{
 if (s->top == -1)
   {
    return 1;
   }
 else
   {
    int x;
    x= s->data[s->top];
    s->top = s->top - 1;
    return x;
   }
}

void main()
{
 STACK s;
 int n, rem;
 s.top = -1;

 printf("Enter the value you want to convert: ");
 scanf("%d", &n);
 printf("The Binary Converted Value: ");

 while (n!=0)
   {
    rem= n%2;
    push(&s, rem);
    n= n/2;
   }

 while (s.top != -1)
   {
    n= pop(&s);
    printf("%d",n);
   }

 printf("\n");
}
