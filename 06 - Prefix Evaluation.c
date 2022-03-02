/*  Evaluation of Prefix Expression  */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;
char prefix[MAX];

void push (int num)
{
 top++;
 stack[top] = prefix[num] - '0';
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
 p=pop();
 q=pop();
 switch (c)
       {
        case '^':
                 ans = p^q;
                 break;
        case '/':
                 ans = p/q;
                 break;
        case '*':
                 ans = p*q;
                 break;
        case '+':
                 ans = p+q;
                 break;
        case '-':
                 ans = p-q;
                 break;
        default:
                ans = 0;
       }
 top++;
 stack[top] = ans;
}

void main()
{
 int len,i;

 printf("Enter the Prefix Expression: ");
 scanf("%s",prefix);

 len=strlen(prefix);

 for (i=len-1; i>=0; i--)
    {
     if (prefix[i]>='0' && prefix[i]<='9')
       {
        push(i);
       }
     else if (prefix[i] == '^' || prefix[i] == '/' || prefix[i] == '*' || prefix[i] == '+' || prefix[i] == '-')
       {
        evaluate(prefix[i]);
       }
    }

 printf("Result after evaluation: %d\n\n", stack[top]);
}
