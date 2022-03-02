// INFIX to POSTFIX Conversion

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define bool int
#define false (1==0)
#define true  (1==1)

#define MAX 100

char stack[MAX];
int top= -1;
char infix[MAX], postfix[MAX];

void push (char item)
{
 if (top >= MAX-1)
   {
    printf("\nStack Overflow");
    exit(0);
   }
 else
   {
    top++;
    stack[top] = item;
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

bool Operator (char symbol)
{
 if (symbol == '^' || symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-')
   {
    return true;
   }
 else
   {
    return false;
   }
}

int Precedence (char symbol)
{
 switch (symbol)
       {
        case '^':
                 return 5;
        case '/':
                 return 4;
        case '*':
                 return 3;
        case '+':
                 return 2;
        case '-':
                 return 1;
        default:
                 exit(0);
       }
}

void InfixToPostfix (char infix[], char postfix[])
{
 int i=0;                      
 int j=0;                      
 char item, x;

 push('(');
 strcat(infix,")");        

 item= infix[i];

 while (item != '\0')
      {
       if (item == '(')
         {
          push(item);
         }
       else if (isdigit(item) || isalpha(item))  
         {
          postfix[j] = item;
          j++;
         }
       else if (Operator(item) == true)
         {
          x= pop();
          while (Operator(x) == true && Precedence(x) >= Precedence(item))
               {
                postfix[j] = x;
                j++;
                x= pop();
               }
          push(x);
          push(item);
         }
       else if (item == ')')
         {
          x= pop();
          while (x != '(')
               {
                postfix[j] = x;
                j++;
                x= pop();
               }
         }
       else
         {
          printf("  The Input Statement is Incorrect\n");
          exit(0);
         }

       i++;
       item= infix[i];
      }
 
 /* It must be null to avoid the garbage value in the result. 
    The garbage value comes because of an extra j++ in the above while loop. */
 postfix[j] = NULL;
}

void main()
{
 printf("Enter Infix Expression: ");
 scanf("%s", infix);

 InfixToPostfix(infix,postfix);
 printf("Postfix Expression: %s\n", postfix);
}
