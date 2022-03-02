// INFIX to PREFIX Conversion

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;
char infix[MAX], prefix[MAX];

push(char item)
{
 if (top >= MAX-1)
   {
    printf("\nStack Overflow");
    exit(0);
   }
 else
   {
    stack[++top] = item;
   }
}

char pop()
{
 if (top == -1)
   {
    printf("\n !! Stack is Empty !! ");
   }
 else
   {
    return stack[top--];
   }
}

int Precedence(char symbol)
{
 switch (symbol)
       {
        case '#':
                 return 0;
        case ')':
                 return 1;
        case '-':
                 return 2;
        case '+':
                 return 3;
        case '*':
                 return 4;
        case '/':
                 return 6;
        case '^':
                 return 7;
       }
}

void InfixToPrefix (char infix[], char prefix[])
{
 char item, x;
 int i=0, j=0;

 push('#');
 strrev(infix);

 while ((item = infix[i++]) != '\0')
      {
       if ( item == ')')
         {
          push(item);
         }
       else if (isalnum(item))
         {
          prefix[j++] = item;
         }
       else if ( item == '(')
         {
          while ( stack[top] != ')')
               {
                prefix[j++] = pop();
               }
          x= pop();
         }
       else
         {
          while ( Precedence(stack[top]) >= Precedence(item) )
               {
                prefix[j++] = pop();
               }
          push(item);
         }
      }
 while ( stack[top] != '#')
      {
       prefix[j++]=pop();
      }
 prefix[j]= NULL;
 strrev(prefix);
 strrev(infix);
}

void main()
{

 printf("Enter Infix Expression: ");
 scanf("%s",infix);

 InfixToPrefix (infix, prefix);
 printf("Prefix Expression: %s\n", prefix);
}
