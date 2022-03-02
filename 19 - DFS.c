/* Implementation of Depth First Search (DFS) Traversal of Graph  */

#include <stdio.h>
#include <stdlib.h>

int z[20];
int b=0;

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
void PrintGraph (Graph* graph);

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

void PrintGraph (Graph* graph)
{
 for (int v = 0; v < graph->num_of_vertices; v++)
    {
     Node* temp = graph->AdjList[v];
     printf("Adjacency list of vertex %d:  ", v);
     while (temp != NULL)
          {
           printf("%d -> ", temp->vertex);
           temp = temp->next;
          }
     printf("\n");
    }
}
// =====================================================

void DFS (Graph* graph, int v)
{
 Node* temp = graph->AdjList[v];
 graph->visited[v] = 1;
 printf("Visited: %d \n", v);
 z[b] = v;
 b++;
 while (temp != NULL)
      {
       int c = temp->vertex;
       if (graph->visited[c] == 0)
         {
          DFS(graph, c);
         }
       temp = temp->next;
      }
}

void main()
{
 for (int i=0; i<4; i++)
    {
     z[i] = NULL;
    }

 Graph* graph = CreateGraph(4);

 AddEdge(graph, 0, 1);
 AddEdge(graph, 0, 2);
 AddEdge(graph, 1, 2);
 AddEdge(graph, 2, 3);

 PrintGraph(graph);

 printf("\n");
 DFS(graph, 1);

 printf("\n=============================  ");
 printf("\nDepth First Search Traversal   ");
 printf("\n=============================\n");
 for (int j=0; j<4; j++)
    {
     printf("%d ", z[j]);
    }
 printf("\n");
}
