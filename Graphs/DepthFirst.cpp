/*
    Depth first starts at the top, works its way down, checking for adjacent nodes. If it is visted, it marks it as read and puts it on top of stack.
    If it has no adjacent, it pops the stack, goes back to previous, and continuously checks around it for unvisited nodes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct vertex
{
    char Label;
    bool Visited;
} vertex;

int Stack[MAX];
int Top = -1;

vertex *ListVertex[MAX];
int AdjMatrix[MAX][MAX];
int VertexCount = 0;

void Push(int Item)
{
    Stack[++Top] = Item;
}

int Pop()
{
    return Stack[Top--];
}

int Peek()
{
    return Stack[Top];
}

bool IsStackEmpty()
{
    return Top == -1;
}

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

void DepthFirstSearch()
{
    ListVertex[0]->Visited = true;
    Push(0);
    
    while(!IsStackEmpty())
    {
        int unvisited = GetAdjUnvisitedVertex(Peek());
        if(unvisited == -1)
        {
            Pop();
        }
        else
        {
            ListVertex[unvisited]->Visited = true;
            Push(unvisited);
        }
    }

    for(int i = 0; i < VertexCount; ++i)
    {
        ListVertex[i]->Visited = false;
    }
}