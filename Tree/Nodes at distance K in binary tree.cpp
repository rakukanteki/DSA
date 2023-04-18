#include<bits/stdc++.h>
using namespace std;

//CREATING A NODE FOR BINARY TREE
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    //CONSTRUCTOR
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

//CASE 1
//node's subtree
void PrintSubTree(Node* root, int k)
{
    if(root==NULL||k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<' ';
        return;
    }

    PrintSubTree(root->left, k-1);
    PrintSubTree(root->right, k-1);
}

//CASE 2
//node's ancestor
//this function returns distance d
int PrintNodesAtK(Node* root, Node* target, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        PrintSubTree(root,k);
        return 0;
    }
    
    int dl=PrintNodesAtK(root->left,target, k);
    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<' ';
        }
        else
        {
            PrintSubTree(root->right, k-dl-2);
        }
        return 1+dl;
    }
    int dr=PrintNodesAtK(root->right,target, k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<' ';
        }
        else
        {
            PrintSubTree(root->left, k-dr-2);
        }
        return 1+dr;
    }

    return -1;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    PrintNodesAtK(root,root->left, 1);
}

//bujhi naiiiiiiiiiiiiiiiiii
  