#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct vertex
{
    char Label;
    bool Visited;
} vertex;

int Queue[MAX];
int Rear = -1;
int Front = 0;
int QueueItemCount = 0;

vertex *ListVertex[MAX];
int AdjMatrix[MAX][MAX];
int VertexCount = 0;

void Insert(int data)
{
    Queue[++Rear] = data;
    QueueItemCount++;
}

int RemoveData()
{
    QueueItemCount--;
    return Queue[Front++];
}

bool isQueueEmpty() { return QueueItemCount == 0; }

void AddVertex(char label)
{
    vertex *Vertex = (vertex *)malloc(sizeof(vertex));
    Vertex->Label = label;
    Vertex->Visited = false;
    ListVertex[VertexCount++] = Vertex;
}

void AddEdge(int start, int end)
{
    AdjMatrix[start][end] = 1;
    AdjMatrix[end][start] = 1;
}

int GetAdjUnvisitedVertex(int index)
{
    for(int i = 0; i < VertexCount; ++i)
    {
        if(AdjMatrix[index][i] == 1 && ListVertex[i]->Visited == false)
        {
            return i;
        }
    }

    return -1;
}

void BreadthFirstSearch()
{
    ListVertex[0]->Visited = true;
    Insert(0);
    int Unvisited;
    while(!isQueueEmpty())
    {
        int TempVertex = RemoveData();
        while((Unvisited = GetAdjUnvisitedVertex(TempVertex)) != -1)
        {
            ListVertex[Unvisited]->Visited = true;
            Insert(Unvisited);
        }
    }
    
    for(int i = 0; i < VertexCount; ++i)
    {
        ListVertex[i]->Visited = false;
    }
}