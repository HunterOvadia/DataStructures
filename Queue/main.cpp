/*
A linear structure which follows a particular order. They follow First In First Out (FIFO). Difference between Stack and Queue is we remove the item least recently added, and not the most recent such as a Stack.

Enqueue: Add an item to the queue.
Dequeue: Remove an item from the queue.
Front: Front Item
Rear: Last Item

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue
{
    int Front, Rear, Size;
    unsigned int Capacity;
    int *Array;
};

queue*
CreateQueue(unsigned int Capacity)
{
    queue *Queue = (queue *)malloc(sizeof(queue));
    Queue->Capacity = Capacity;
    Queue->Front = 0;
    Queue->Size = 0;
    Queue->Rear = Capacity - 1;
    Queue->Array = (int *)malloc(Queue->Capacity * sizeof(int));
    
    return(Queue);
}

int
IsQueueFull(queue *Queue)
{
    return((unsigned int)Queue->Size == Queue->Capacity);
}

int
IsQueueEmpty(queue *Queue)
{
    return (Queue->Size == 0);
}

void
Enqueue(queue *Queue, int Item)
{
    if(IsQueueFull(Queue))
        return;
    Queue->Rear = (Queue->Rear + 1) % Queue->Capacity;
    Queue->Array[Queue->Rear] = Item;
    ++Queue->Size;
}

int
Dequeue(queue *Queue)
{
    if(IsQueueEmpty(Queue))
        return INT_MIN;
    
    int Item = Queue->Array[Queue->Front];
    Queue->Front = (Queue->Front + 1) % Queue->Capacity;
    --Queue->Size;
    
    return(Item);
}

int
GetFront(queue *Queue)
{
    if(IsQueueEmpty(Queue))
        return INT_MIN;
    
    return(Queue->Array[Queue->Front]);
}

int
GetRear(queue *Queue)
{
    if(IsQueueEmpty(Queue))
        return INT_MIN;
    
    return(Queue->Array[Queue->Rear]);
}

int
main()
{
    queue *Queue = CreateQueue(1000);
    
    Enqueue(Queue, 10);
    Enqueue(Queue, 20);
    
    Dequeue(Queue);
    GetFront(Queue);
    GetRear(Queue);
    
    return(0);
}