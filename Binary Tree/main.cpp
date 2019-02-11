/*
Not a linear Datastructure, but a Hierarchial.
Topmost node is called the Root of the Tree. The elements under an element is called the children. Element above is called the Parent. Elements with no Children are called Leaves.

A Binary Tree is a tree whose elements have at most 2 children. Each element can only have 2 children, we call them left and right child. A tree is represented by a pointer to the topmost node in the tree. IF empty, it is NULL. A tree comtains:
1. Data
2. Pointer to Left Child
3. Pointer to Right Child
*/
#include <stdlib.h>

struct node
{
    int Data;
    node *Left;
    node *Right;
};

struct node *NewNode(int Data)
{
    node *Node = (node *)malloc(sizeof(node));
    Node->Data = Data;
    Node->Left = NULL;
    Node->Right = NULL;
    return(Node);
}

int
main()
{
    // Create root node
    node *Root = NewNode(1);
    
    
    Root->Left = NewNode(2);
    Root->Right = NewNode(3);
    
    Root->Left->Left = NewNode(4);
    
    
    
    return(0);
}