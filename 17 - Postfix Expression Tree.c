/* Postfix Expression Tree  */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
 printf("Enter Postfix Expression: ");
 scanf("%s", postfix);

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
 printf("\nResult after evaluation: %d\n\n", stack2[top]);
}
