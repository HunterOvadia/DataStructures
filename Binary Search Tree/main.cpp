/*
A node-based binary tree structure with:
- Left subtree of a node contains nodes with keys lesser than the node's key
- Right subtree is keys greater
- The left and right subtree must also be a binary search tree.
- No duplicate nodes

Provide an ordering among keys so functions such as search, min, max can be done fast.
*/

#include <stdlib.h>

struct node
{
    int Data;
    node *Left;
    node *Right;
};

node* 
NewNode(int Data)
{
    node *Node = (node *)malloc(sizeof(node));
    Node->Data = Data;
    Node->Left = NULL;
    Node->Right = NULL;
    return(Node);
}

node*
SearchNode(node *Root, int Data)
{
    if(Root == NULL || Root->Data == Data)
        return Root;
    
    if(Root->Data < Data)
        return SearchNode(Root->Right, Data);
    
    return SearchNode(Root->Left, Data);
}

node*
Insert(node *Node, int Data)
{
    // If Tree is empty, insert new node
    if(Node == NULL)
        return NewNode(Data);
    
    if(Data < Node->Data)
        Node->Left = Insert(Node->Left, Data);
    else if(Data > Node->Data)
        Node->Right = Insert(Node->Right, Data);
    
    return Node;
}

// Returns node with minimum value in the tree.
// Keep searching down left side since smaller values.
node*
MinValueNode(node *Node)
{
    node *Current = Node;
    while(Current->Left != NULL)
        Current = Current->Left;
    
    return(Current);
}

node*
DeleteNode(node *Root, int Data)
{
    if(Root == NULL)
        return Root;
    
    if(Data < Root->Data)
        Root->Left = DeleteNode(Root->Left, Data);
    else if(Data > Root->Data)
        Root->Right = DeleteNode(Root->Right, Data);
    else
    {
        if(Root->Left == NULL)
        {
            node *Temp = Root->Right;
            free(Root);
            return Temp;
        }
        else if(Root->Right == NULL)
        {
            node *Temp = Root->Left;
            free(Root);
            return Temp;
        }
        
        node *Temp = MinValueNode(Root->Right);
        Root->Data = Temp->Data;
        Root->Right = DeleteNode(Root->Right, Temp->Data);
    }
    
    return(Root);
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