/* Implementation of Breadth First Search (BFS) Traversal of Graph  */

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true  (1==1)
#define false (1==0)

#define MAX 20

int z[MAX];
int b = 0;

// ====================================================
typedef struct
{
 int vertex;
 struct Node* next;
} Node;

Node* GetNewNode (int x);

Node* GetNewNode (int x)
{
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->vertex = x;
 newNode->next = NULL;
 return newNode;
}
// =====================================================

// =====================================================
typedef struct
{
 int num_of_vertices;
 struct Node** AdjList;
 int* visited;
} Graph;

Graph* CreateGraph (int v);
void AddEdge (Graph* graph, int s, int d);

Graph* CreateGraph (int v)
{
 Graph* graph = (Graph*)malloc(sizeof(Graph));
 graph->num_of_vertices = v;
 graph->AdjList = malloc(v* sizeof(Node*));
 graph->visited = malloc(v* sizeof(int));
 for (int i=0; i<v; i++)
    {
     graph->AdjList[i] = NULL;
     graph->visited[i] = 0;
    }
 return graph;
}

void AddEdge (Graph* graph, int s, int d)      // s: source & d: destination
{
 Node* temp;
 // Add edge from s to d
 temp = GetNewNode(d);
 temp->next = graph->AdjList[s];
 graph->AdjList[s] = temp;
 // Add edge from d to s
 temp = GetNewNode(s);
 temp->next = graph->AdjList[d];
 graph->AdjList[d] = temp;
}
// =====================================================

// =====================================================
typedef struct
{
 int items[MAX];
 int front;
 int rear;
} Queue;

Queue* CreateQueue();
bool isEmpty (Queue* q);
void enQueue (Queue* q, int x);
int deQueue (Queue* q);
void display (Queue* q);

Queue* CreateQueue()
{
 Queue* q = (Queue*)malloc(sizeof(Queue));
 q->front = -1;
 q->rear  = -1;
 return q;
}

bool isEmpty (Queue* q)
{
 if (q->rear == -1)
   {  return true;   }
 else
   {  return false;  }
}

void enQueue (Queue* q, int x)
{
 if (q->rear == MAX-1)
   {
    printf("Queueu is Full \n");
   }
 else
   {
    if (q->front == -1)
      {
       q->front = 0;
      }
    q->rear++;
    q->items[q->rear] = x;
   }
}

int deQueue (Queue* q)
{
 int x;
 if (isEmpty(q))
   {
    printf("Queue is empty");
    x = -1;
   }
 else
   {
    x = q->items[q->front];
    q->front++;
    if (q->front > q->rear)      // Resetting Queue
      {
       q->front = -1;
       q->rear  = -1;
      }
   }
 return x;
}

void display (Queue* q)
{
 int i= q->front;
 if (isEmpty(q))
   {
    printf("Queue is Empty \n");
   }
 else
   {
    printf("Queue contains: ");
    for (i=q->front; i<q->rear+1; i++)
       {
        printf("%d ", q->items[i]);
       }
   }
}
// =====================================================

// =====================================================
void BFS (Graph* graph, int v)      // v: Start Vertex
{
 Queue* q = CreateQueue();
 graph->visited[v] = 1;
 enQueue(q, v);
 while (!isEmpty(q))
      {
       display(q);
       int c = deQueue(q);          // c: Current Vertex
       printf("\n\nVisited: %d\n", c);
       z[b] = c;
       b++;
       Node* temp = graph->AdjList[c];
       while (temp != NULL)
            {
             int x = temp->vertex;
             if (graph->visited[x] == 0)
               {
                graph->visited[x] = 1;
                enQueue(q, x);
               }
             temp = temp->next;
            }
      }
}
// =====================================================

void main()
{
 for (int i=0; i<6; i++)
    {
     z[i] = NULL;
    }

 Graph* graph = CreateGraph(6);

 AddEdge(graph, 0, 1);
 AddEdge(graph, 0, 2);
 AddEdge(graph, 1, 2);
 AddEdge(graph, 1, 4);
 AddEdge(graph, 1, 3);
 AddEdge(graph, 2, 4);
 AddEdge(graph, 3, 4);
 AddEdge(graph, 4, 5);

 BFS(graph, 2);

 printf("\n===============================  ");
 printf("\nBreadth First Search Traversal   ");
 printf("\n===============================\n");
 for (int j=0; j<6; j++)
    {
     printf("%d ", z[j]);
    }
 printf("\n");
}
