/*
A linear data structure, like an array, but each elements are linked using pointers to a memory location.

  Advantages:
  - Dynamic Size
  - Eaze of Insertion and Deletion
  
  Disadvantages:
  - Has to be accessed sequentially.
  - With adding an element, we need extra memory space for a pointer.
  - Not cache friendly, since not contiguous locations. (Pointers, memory can be all over)
  
  
  Representated by a pointer to the first node of the list. The first node is called the head. If the list is empty, then the value of head is NULL.
  Each Node contains:
  1. Data
  2. A pointer or reference to the next node.
  
*/


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Data;
    node *Next;
};


void
PrintList(node *Node)
{
    while(Node != NULL)
    {
        printf("%d\n", Node->Data);
        Node = Node->Next;
    }
}

void
Push(node **HeadRef, int NewData)
{
    node *NewNode = (node *)malloc(sizeof(node));
    NewNode->Data = NewData;
    NewNode->Next = *HeadRef;
    *HeadRef = NewNode;
}

void
InsertAfter(node *PrevNode, int NewData)
{
    if(PrevNode == NULL)
        return;
    
    node *NewNode = (node *)malloc(sizeof(node));
    NewNode->Data = NewData;
    NewNode->Next = PrevNode->Next;
    PrevNode->Next = NewNode;
}

void
Append(node** HeadRef, int NewData)
{
    node *NewNode = (node *)malloc(sizeof(node));
    node *Last = *HeadRef;
    
    NewNode->Data = NewData;
    NewNode->Next = NULL;
    
    if(*HeadRef == NULL)
    {
        *HeadRef = NewNode;
        return;
    }
    
    while(Last->Next != NULL)
    {
        Last = Last->Next;
    }
    
    Last->Next = NewNode;
}

void
DeleteNodeAt(node **HeadRef, int Position)
{
    if(*HeadRef == NULL)
        return;
    
    node *Temp = *HeadRef;
    
    if(Position == 0)
    {
        *HeadRef = Temp->Next;
        free(Temp);
        return;
    }
    
    for(int i = 0; Temp != NULL && i < Position - 1; ++i)
    {
        Temp = Temp->Next;
    }
    
    if(Temp == NULL || Temp->Next == NULL)
        return;
    
    node *Next = Temp->Next->Next;
    free(Temp->Next);
    
    Temp->Next = Next;
}

int
GetCount(node *Head)
{
    int Count = 0;
    node *Current = Head;
    while(Current != NULL)
    {
        ++Count;
        Current = Current->Next;
    }
    
    return(Count);
}

int 
main()
{
    node *Head = NULL;
    
    Push(&Head, 7);
    Push(&Head, 8);
    Push(&Head, 3);
    
    DeleteNodeAt(&Head, 2);
    
    PrintList(Head);
    
    system("pause");
    return(0);
}
