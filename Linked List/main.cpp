#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int Data;
    int Key;
    struct node *Next;
} node;

node *Head = NULL;
node *Current = NULL;

void printList()
{
    node *Current = Head;
    printf("\n[ ");

    while(Current != NULL)
    {
        printf(" (%d,%d) ", Current->Key, Current->Data);
        Current = Current->Next;
    }

    printf(" ]");
}

void insertFirst(int key, int data)
{
    node *Link = (node *)malloc(sizeof(node));

    Link->Key = key;
    Link->Data = data;

    Link->Next = Head;

    Head = Link;
}

node* deleteFirst()
{
    node *Temp = Head;
    Head = Head->Next;
    return Temp;
}

bool IsEmpty()
{
    return Head == NULL;
}

int Length()
{
    int Length = 0;
    for(node *Current = Head; Current != NULL; Current = Current->Next)
    {
        ++Length;
    }

    return(Length);
}

node* Find(int Key)
{
    node *Current = Head;
    if(IsEmpty())
        return NULL;
    
    while(Current->Key != Key)
    {
        if(Current->Next == NULL)
            return NULL;
        else
            Current = Current->Next;
    }

    return Current;
}

node* Delete(int Key)
{
    node *Current = Head;
    node *Previous = NULL;

    if(Head == NULL)
        return NULL;
    
    while(Current->Key != Key)
    {
        if(Current->Next == NULL)
            return NULL;
        else
            Previous = Current;
            Current = Current->Next;
    }

    if(Current == Head)
        Head = Head->Next;
    else
        Previous->Next = Current->Next;

    return Current;
}

void Sort()
{
    int k = Length();
    node *Current;
    node *Next;
    int TempData;
    int TempKey;

    for(int i = 0; i < Length() - 1; i++, k--)
    {
        Current = Head;
        Next = Head->Next;

        for(int j = 1; j < k; j++)
        {
            if(Current->Data > Next->Data)
            {
                TempData = Current->Data;
                Current->Data = Next->Data;
                Next->Data = TempData;
                
                TempKey = Current->Key;
                Current->Key = Next->Key;
                Next->Key = TempKey;
            }

            Current = Current->Next;
            Next = Next->Next;
        }
    }
}


void Reverse()
{
    node *Prev = NULL;
    node *Current = Head;
    node *Next = NULL;

    while(Current != NULL)
    {
        Next = Current->Next;
        Current->Next = Prev;
        Prev = Current;
        Current = Next;
    }

    Head = Prev;
}