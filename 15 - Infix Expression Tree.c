/* Infix Expression Tree  */

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define false (1==0)
#define true  (1==1)

#define MAX 100

char stack1[MAX];
int top1= -1;
char infix1[MAX], postfix1[MAX];

void push1 (char item)
{
 if (top1 >= MAX-1)
   {
    printf("\nStack Overflow");
    exit(0);
   }
 else
   {
    top1++;
    stack1[top1] = item;
   }
}

char pop1()
{
 if (top1 == -1)
   {
    printf("\n !! Stack is Empty !! ");
   }
 else
   {
    return stack1[top1--];
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

void InfixToPostfix (char infix1[], char postfix1[])
{
 int i=0;
 int j=0;
 char item, x;

 push1('(');
 strcat(infix1,")");

 item= infix1[i];

 while (item != '\0')
      {
       if (item == '(')
         {
          push1(item);
         }
       else if (isdigit(item) || isalpha(item))
         {
          postfix1[j] = item;
          j++;
         }
       else if (Operator(item) == true)
         {
          x= pop1();
          while (Operator(x) == true && Precedence(x) >= Precedence(item))
               {
                postfix1[j] = x;
                j++;
                x= pop1();
               }
          push1(x);
          push1(item);
         }
       else if (item == ')')
         {
          x= pop1();
          while (x != '(')
               {
                postfix1[j] = x;
                j++;
                x= pop1();
               }
         }
       else
         {
          printf("  The Input Statement is Incorrect\n");
          exit(0);
         }

       i++;
       item= infix1[i];
      }

 /* It must be null to avoid the garbage value in the result.
    The garbage value comes because of an extra j++ in the above while loop. */
 postfix1[j] = NULL;
}
/* ==================================================================================== */

/* For Expression Tree ================================================================ */
typedef struct
{
 int data;
 struct EtNode* left;
 struct EtNode* right;
} EtNode;

char postfix[MAX];
int top = -1;

EtNode *stack[MAX];

void push(EtNode *root)
{
 top++;
 stack[top] = root;
}

EtNode *pop()
{
 top--;
 return (stack[top+1]);
}

int Check (char c)    // for checking input character is operand or operator
{
 if (c == '+' || c == '-' || c == '*' || c == '/')
   {
    return -1;
   }
 else if (isalpha(c) || isdigit(c))
   {
    return 1;
   }
 else
   {
    return 0;
   }
}

void Create (char *root)
{
 char r = root[0];       //Read the first symbol from the postfix exp
 int a;
 EtNode *temp, *t1, *t2;

 for (int i=1; r!='\0'; i++)
    {
     a = Check(r);
     if (a == 1)
       {
        temp = (EtNode*)malloc(sizeof(EtNode));
        temp->data = r;
        temp->left = NULL;
        temp->right = NULL;
        push(temp);
       }
     else
       {
        t1 = pop();
        t2 = pop();
        temp = (EtNode*)malloc(sizeof(EtNode));
        temp->data = r;
        temp->left = t2;
        temp->right = t1;
        push(temp);
       }
     r= root[i];
    }
}

void PreOrderTraversal(EtNode* root)
{
 if (root == NULL)
   {
    printf("Tree is empty.");
    return;
   }
 printf("%c", root->data);
 if (root->left != NULL)
   {
    PreOrderTraversal(root->left);
   }
 if (root->right != NULL)
   {
    PreOrderTraversal(root->right);
   }
}

void InOrderTraversal(EtNode* root)
{
 if (root == NULL)
   {
    printf("Tree is empty.");
    return;
   }
 if (root->left != NULL)
   {
    InOrderTraversal(root->left);
   }
 printf("%c", root->data);
 if (root->right != NULL)
   {
    InOrderTraversal(root->right);
   }
}

void PostOrderTraversal(EtNode* root)
{
 if (root == NULL)
   {
    printf("Tree is empty.");
    return;
   }
 if (root->left != NULL)
   {
    PostOrderTraversal(root->left);
   }
 if (root->right != NULL)
   {
    PostOrderTraversal(root->right);
   }
 printf("%c", root->data);
}
/* ==================================================================================== */

/* For Evaluating Postfix expression ================================================== */
int stack2[MAX];
int top2 = -1;
char postfix[MAX];

void push2 (int num)
{
 top2++;
 stack2[top2] = postfix[num] - '0';
}

char pop2()
{
 if (top2 == -1)
   {
    printf("\n !! Stack is Empty !! ");
   }
 else
   {
    return stack2[top2--];
   }
}

void evaluate (char c)
{
 int p,q,ans;

 p= stack2[top2];
 pop2();

 q= stack2[top2];
 pop2();

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
 top2++;
 stack2[top2] = ans;
}
/* ==================================================================================== */

void main()
{
 printf("Enter Infix Expression: ");
 scanf("%s", infix1);

 InfixToPostfix(infix1,postfix1);

 int r = strlen(postfix1);
 for (int s=0; s<r; s++)
    {
     postfix[s] = postfix1[s];
    }

 Create(postfix);

 printf("\nIn-Order Traversal: ");
 InOrderTraversal(stack[0]);

 printf("\nPre-Order Traversal: ");
 PreOrderTraversal(stack[0]);

 printf("\nPost-Order Traversal: ");
 PostOrderTraversal(stack[0]);

 int len, i;
 len= strlen(postfix);

 for (i=0; i<len; i++)
    {
     if (postfix[i]>='0' && postfix[i]<='9')
       {
        push2(i);
       }
     else if (postfix[i] == '^' || postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-')
       {
        evaluate(postfix[i]);
       }
    }
 printf("\n\nResult after evaluation: %d\n\n", stack2[top]);
}

