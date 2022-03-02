/*  Evaluation of Postfix Expression  */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;
char postfix[MAX];

void push (int num)
{
 top++;
 stack[top] = postfix[num] - '0';
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

void evaluate (char c)
{
 int p,q,ans;

 p= stack[top];
 pop();

 q= stack[top];
 pop();

 switch (c)
       {
        case '^':
                 ans = q^p;
                 break;
        case '/':
                 ans = q/p;
                 break;
        case '*':
                 ans = q*p;
                 break;
        case '+':
                 ans = q+p;
                 break;
        case '-':
                 ans = q-p;
                 break;
        default:
                ans = 0;
       }
 top++;                   
 stack[top] = ans;        
}

void main()
{
 int len, i;

 printf("Enter the Postfix Expression: ");
 scanf("%s", postfix);

 len= strlen(postfix);

 for (i=0; i<len; i++)
    {
     if (postfix[i]>='0' && postfix[i]<='9')
       {
        push(i);
       }
     else if (postfix[i] == '^' || postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-')
       {
        evaluate(postfix[i]);
       }
    }
 printf("Result after evaluation: %d\n\n", stack[top]);
}
