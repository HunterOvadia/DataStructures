#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int Data;
    struct node *LeftChild;
    struct node *RightChild;
} node;

node *Root = NULL;

void Insert(int data)
{
    node *TempNode = (node *)malloc(sizeof(node));
    node *Current;
    node *Parent;

    TempNode->Data = data;
    TempNode->LeftChild = NULL;
    TempNode->RightChild = NULL;

    if(Root == NULL)
        Root = TempNode;
    else
    {
        Current = Root;
        Parent = NULL;
    
        while(1)
        {
            Parent = Current;
            if(data < Parent->Data)
            {
                Current = Current->LeftChild;
                if(Current == NULL)
                {
                    Parent->LeftChild = TempNode;
                    return;
                }
            }
            else
            {
                Current = Current->RightChild;
                if(Current == NULL)
                {
                    Parent->RightChild = TempNode;
                    return;
                }
            }      
        }
    }
}

node* Search(int data)
{
    node *Current = Root;
    while(Current->Data != data)
    {
        if(Current->Data > data)
            Current = Current->LeftChild;
        else
            Current = Current->RightChild;

        if(Current == NULL)
            return NULL;

        return Current;
    }
}


void PreOrderTraversal(node* root)
{
    if(root != NULL)
    {
        PreOrderTraversal(root->LeftChild);
        PreOrderTraversal(root->RightChild);
    }
}

void PostOrderTraversal(node* root)
{
    if(root != NULL)
    {
        PostOrderTraversal(root->LeftChild);
        PostOrderTraversal(root->RightChild);
    }
}

void InOrderTraversal(node* root)
{
    if(root != NULL)
    {
        InOrderTraversal(root->LeftChild);
        InOrderTraversal(root->RightChild);
    }
}