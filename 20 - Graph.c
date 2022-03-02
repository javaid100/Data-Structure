/*  Graph  */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
 int index;
 struct Node* next;
} Node;

Node* head[MAX];

char adj[MAX][MAX];
char v[MAX];            //  Vertices
int n;                 // No of Vertices

void AdjacencyMatrix ();
void DisplayMatrix();
Node* StartInsert (int x, Node* head);
Node* EndInsert (int x, Node* head);
void AdjacencyList();
void DisplayList();

void AdjacencyMatrix ()
{
 char x;
 for (int j=0; j<n; j++)
    {
     for (int k=0; k<n; k++)
        {
         printf("Is %c connected to %c ? <Y/N> : ",v[j],v[k]);
         scanf(" %c", &x);
         adj[j][k] = x;
        }
    }
}

void DisplayMatrix()
{
 printf("\n\n==========================");
 printf("\n==== Adjacency Matrix ====");
 printf("\n==========================\n");

 for (int s=0; s<n; s++)
    {
     printf("    %c ", v[s]);
    }

 printf("\n  ----------------\n");

 for (int y=0; y<n; y++)
    {
     printf("%c |", v[y]);
     for (int z=0; z<n; z++)
        {
         if (adj[y][z] == 'Y')
           {
            printf(" %d    ", 1);
           }
         else
           {
            printf(" %d    ", 0);
           }
        }
     printf("\n");
    }
}

Node* GetNewNode (int x)
{
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->index = x;
 newNode->next = NULL;
}

Node* StartInsert (int x, Node* head)
{
 Node* temp = GetNewNode(x);
 if (head != NULL)
   {
    temp->next = head;
   }
 head = temp;
 return head;
}

Node* EndInsert (int x, Node* head)
{
 if (head == NULL)
   {
    head = StartInsert(x, head);
    return head;
   }
 Node* t1 = GetNewNode(x);
 Node* t2 = head;
 while (t2->next != NULL)
      {
       t2 = t2->next;
      }
 t2->next = t1;
 return head;
}

void AdjacencyList()
{
 for (int i=0; i<n; i++)
    {
     for (int j=0; j<n; j++)
        {
         if (adj[i][j] == 'Y')
           {
            head[i] = EndInsert(j, head[i]);
           }
        }
    }
}

void DisplayList()
{
 Node* temp;
 printf("==========================");
 printf("\n===== Adjacency List =====");
 printf("\n==========================");
 for (int i=0; i<n; i++)\
    {
     printf("\n%c |", v[i]);
     temp = head[i];
     while (temp != NULL)
          {
           printf(" --> %c", v[temp->index]);
           temp = temp->next;
          }
    }
}

void main()
{
 printf("============== GRAPH ================== \n\n");

 char b;
 printf("Enter the Number of Vertices: ");
 scanf("%d",&n);

 printf("Enter the Name of Vertices: \n");
 for (int i=0; i<n; i++)
    {
     printf("Vertex %d: ", i+1);
     scanf(" %c", &b);
     v[i] = b;
    }

 printf("\n");
 AdjacencyMatrix();
 DisplayMatrix();

 printf("\n");
 AdjacencyList();
 DisplayList();

 printf("\n");
}

