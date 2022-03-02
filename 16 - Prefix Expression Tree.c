/* Prefix Expression Tree  */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* For Expression Tree ================================================================ */
typedef struct
{
 char data;
 struct EtNode* left;
 struct EtNode* right;
} EtNode;

EtNode *GetNewNode (char data)
{
 EtNode *newNode = (EtNode*)malloc(sizeof(EtNode));
 newNode->data  = data;
 newNode->left  = NULL;
 newNode->right = NULL;
 return newNode;
}

typedef struct
{
 struct EtNode* data;
 struct StackNode* next;
} StackNode;

StackNode *StNode (EtNode* root)
{
 StackNode *n = (StackNode*)malloc(sizeof(StackNode));
 n->data  = root;
 n->next  = NULL;
 return n;
}

char prefix[MAX];
StackNode *top;

void push (EtNode *root)
{
 if (top == NULL)
   {
    top = StNode(root);
   }
 else
   {
    StackNode *nptr = StNode(root);
    nptr->next = top;
    top = nptr;
   }
}

EtNode *pop()
{
 if (top == NULL)
   {
    printf("Underflow");
   }
 else
   {
    EtNode *ptr = top->data;
    top = top->next;
    return ptr;
   }
}

void Insert (char val)
{
 if (val >= '0' && val <= '9')
   {
    EtNode *nptr = GetNewNode(val);
    push(nptr);
   }
 else if (val == '+' || val == '-' || val == '*' || val == '/')
   {
    EtNode *nptr = GetNewNode(val);
    nptr->left = pop();
    nptr->right = pop();
    push(nptr);
   }
}

void BuildTree (char eqn[])
{
 int len = strlen(eqn);
 for (int i=len-1; i>=0; i--)
    {
     Insert(eqn[i]);
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

/* For Evaluating Prefix expression =================================================== */
int stack2[MAX];
int top2 = -1;

void push2 (int num)
{
 top2++;
 stack2[top2] = prefix[num] - '0';
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
 p=pop2();
 q=pop2();
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
 top2++;
 stack2[top2] = ans;
}
/* ==================================================================================== */

void main()
{
 printf("Enter Postfix Expression: ");
 scanf("%s", prefix);

 BuildTree(prefix);

 printf("\nIn-Order Traversal: ");
 InOrderTraversal(top->data);

 printf("\nPre-Order Traversal: ");
 PreOrderTraversal(top->data);

 printf("\nPost-Order Traversal: ");
 PostOrderTraversal(top->data);

 int len,j;
 len=strlen(prefix);

 for (j=len-1; j>=0; j--)
    {
     if (prefix[j]>='0' && prefix[j]<='9')
       {
        push2(j);
       }
     else if (prefix[j] == '^' || prefix[j] == '/' || prefix[j] == '*' || prefix[j] == '+' || prefix[j] == '-')
       {
        evaluate(prefix[j]);
       }
    }

 printf("\nResult after evaluation: %d\n\n", stack2[top2]);
}
