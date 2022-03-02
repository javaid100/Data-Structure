/*  Implementation of BST (Binary Search Tree)  */

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true  (1==1)
#define false (1==0)

#define MAX 500

typedef struct
{
 int data;
 struct BstNode* left;
 struct BstNode* right;
} BstNode;

BstNode *temp;
BstNode *t;

void isEmpty(BstNode* root);
BstNode* GetNewNode(int data);
BstNode* Insert(BstNode* root, int data);
bool Search(BstNode* root, int data);
BstNode* Delete(BstNode* root, int data);
int Largest(BstNode* root);
int Smallest(BstNode* root);
void PreOrderTraversal(BstNode* root);
void InOrderTraversal(BstNode* root);
void PostOrderTraversal(BstNode* root);
void LevelOrderTraversal(BstNode* root);

void isEmpty(BstNode* root)
{
 if (root == NULL)
   {
    printf("Tree is Empty");
   }
 else
   {
    printf("Tree is not Empty");
   }
}

BstNode* GetNewNode(int data)
{
 BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));
 newNode->data  = data;
 newNode->left  = NULL;
 newNode->right = NULL;
 return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
 if (root == NULL)
   {
    root = GetNewNode(data);
   }
 else if (data <= root->data)
   {
    root->left = Insert(root->left, data);
   }
 else
   {
    root->right = Insert(root->right, data);
   }
 return root;
}

bool Search(BstNode* root, int data)
{
 if (root == NULL)
   {
    return false;
   }
 else if (root->data == data)
   {
    return true;
   }
 else if (data <= root->data)
   {
    return Search(root->left, data);
   }
 else
   {
    return Search(root->right, data);
   }
}

BstNode* Delete(BstNode* root, int data)
{
 if (root == NULL)
   {
    printf("Tree is empty. No elements to delete.\n");
    return;
   }
 if (data < root->data)
   {
    root->left = Delete(root->left, data);
   }
 else if (data > root->data)
   {
    root->right = Delete(root->right, data);
   }
 else
   {
    if (root->left == NULL)
      {
       BstNode* temp = root->right;
       free(root);
       return temp;
      }
    else if (root->right == NULL)
      {
       BstNode* temp = root->left;
       free(root);
       return temp;
      }
    BstNode* temp = Smallest(root->right);
    root->data = temp->data;
    root->right = Delete(root->right, temp->data);
   }
 return root;
}

int Smallest(BstNode* root)
{
 if (root->left != NULL)
   {
    t = root;
    return Smallest(root->left);
   }
 else
   {
    return root->data;
   }
}

int Largest(BstNode* root)
{
 if (root->right != NULL)
   {
    t = root;
    return Largest(root->right);
   }
 else
   {
    return root->data;
   }
}

void PreOrderTraversal(BstNode* root)
{
 if (root == NULL)
   {
    printf("Tree is empty.");
    return;
   }
 printf("%d -> ", root->data);
 if (root->left != NULL)
   {
    PreOrderTraversal(root->left);
   }
 if (root->right != NULL)
   {
    PreOrderTraversal(root->right);
   }
}

void InOrderTraversal(BstNode* root)
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
 printf("%d -> ", root->data);
 if (root->right != NULL)
   {
    InOrderTraversal(root->right);
   }
}

void PostOrderTraversal(BstNode* root)
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
 printf("%d -> ", root->data);
}

BstNode** createOueue(int *front, int *rear)
{
 BstNode** queue = (BstNode**)malloc(sizeof(BstNode*)*MAX);
 *front = 0;
 *rear  = 0;
 return queue;
}

void enQueue(BstNode** queue, int *rear, BstNode* root)
{
 queue[*rear] = root;
 (*rear)++;
}

BstNode* deQueue(BstNode** queue, int *front)
{
 (*front)++;
 return queue[*front - 1];
}

void LevelOrderTraversal(BstNode* root)
{
 int rear, front;
 BstNode** queue = createOueue(&front, &rear);
 while (root)
      {
       printf("%d -> ", root->data);
       if (root->left)
         {
          enQueue(queue, &rear, root->left);
         }
       if (root->right)
         {
          enQueue(queue, &rear, root->right);
         }
       root = deQueue(queue, &front);     // Dequeue node and make it temp2 node
      }
}

void main()
{
 BstNode* root = NULL;
 int k, input, a, b;

 printf("============= BINARY SEARCH TREE ================\n");
 printf("1- Insert \n2- Search \n3- Delete \n4- Maximum Value \n5- Minimum Value \n6- Preorder Traversal \n7- Inorder Traversal \n8- Postorder Traversal\n9- Level Order Traversal \n10- Exit \n");

 while (-1)
      {
       printf("\nEnter the choice: ");
       scanf("%d", &k);

       switch (k)
             {
              case 1:
                     printf("Enter the value to insert in BST: ");
                     scanf("%d", &input);
                     root = Insert(root, input);
                     break;
              case 2:
                     printf("Enter the value to search in BST to know that whether it is present or not: ");
                     scanf("%d", &a);
                     if (Search(root,a) == true)
                       {
                        printf("%d is Present in BST\n", a);
                       }
	                 else
                       {
                        printf("%d is not Present in BST\n", a);
                       }
                     break;
              case 3:
                     printf("Enter the value to delete from BST: ");
                     scanf("%d", &b);
                     Delete(root, b);
                     break;
              case 4:
                     printf("Maximum Value: %d", Largest(root));
                     printf("\n");
                     break;
              case 5:
                    printf("Minimum Value: %d", Smallest(root));
                    printf("\n");
                    break;
              case 6:
                     printf("Preorder Traversal: ");
                     PreOrderTraversal(root);
                     printf("\n");
                     break;
              case 7:
                     printf("Inorder Traversal: ");
                     InOrderTraversal(root);
                     printf("\n");
                     break;
              case 8:
                     printf("Postorder Traversal: ");
                     PostOrderTraversal(root);
                     printf("\n");
                     break;
              case 9:
                     printf("Level Order Traversal: ");
                     LevelOrderTraversal(root);
                     printf("\n");
                     break;
              case 10:
                      exit(0);
              default:
                      printf("Invalid Choice. Choose the Option again.\n");
             }
      }
}
