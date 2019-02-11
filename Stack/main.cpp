/*
A linear data structure which can either be LIFO (Last In First Out) or FILO (First In Last Out).

Push: Adds to the stack
Pop: Removes an item from the stack.
Peek(or Top): Returns the top element
IsEmpty: Returns true/false if stack is empty

Pros: Easy implementable. 
Cons: Not dynamic. Cannot grow or shrink on runtime.


*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int Top;
    unsigned int Capacity;
    int *Array;
};

stack*
CreateStack(unsigned int Capacity)
{
    stack *Stack = (stack *)malloc(sizeof(stack));
    Stack->Capacity = Capacity;
    Stack->Top = -1;
    Stack->Array = (int *)malloc(Stack->Capacity * sizeof(int));
    
    return(Stack);
}

int
IsStackFull(stack *Stack)
{
    return(Stack->Top == Stack->Capacity - 1);
}

int
IsStackEmpty(stack *Stack)
{
    return(Stack->Top == -1);
}

void
Push(stack *Stack, int Item)
{
    if(IsStackFull(Stack))
        return;
    
    Stack->Array[++Stack->Top] = Item;
}

int
Pop(stack *Stack)
{
    if(IsStackEmpty(Stack))
        return INT_MIN;
    
    return Stack->Array[Stack->Top--];
}

int
main()
{
    stack *Stack = CreateStack(100);
    
    Push(Stack, 10);
    
    return(0);
}