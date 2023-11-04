#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph
{
  int vertices;
  bool visited[MAX_VERTICES];
  int adjacency[MAX_VERTICES][MAX_VERTICES];
};

void initGraph(struct Graph *graph, int vertices)
{
  graph->vertices = vertices;
  for (int i = 0; i < MAX_VERTICES; i++)
  {
    graph->visited[i] = false;
    for (int j = 0; j < MAX_VERTICES; j++)
    {
      graph->adjacency[i][j] = 0;
    }
  }
}

void addEdge(struct Graph *graph, int v, int w)
{
  graph->adjacency[v][w] = 1;
}

void DFS(struct Graph *graph, int v)
{
  graph->visited[v] = true;
  printf("%d ", v);

  for (int i = 0; i < graph->vertices; i++)
  {
    if (graph->adjacency[v][i] == 1 && !graph->visited[i])
    {
      DFS(graph, i);
    }
  }
}

int main()
{
  struct Graph g;
  int vertices, edges;

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  initGraph(&g, vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++)
  {
    int v, w;
    printf("Enter edge %d (format: source destination): ", i + 1);
    scanf("%d %d", &v, &w);
    addEdge(&g, v, w);
  }

  int startVertex;
  printf("Enter the starting vertex for DFS: ");
  scanf("%d", &startVertex);

  printf("Following is Depth First Traversal (starting from vertex %d) \n", startVertex);
  DFS(&g, startVertex);

  return 0;
}
