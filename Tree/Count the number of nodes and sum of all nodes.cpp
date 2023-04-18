//BINARY TREE
//COUNT ALL NODES IN BINARY TREE
//SUM OF ALL NODES
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

int countNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right) +1;
}

int sumOfNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return sumOfNodes(root->left)+sumOfNodes(root->right)+root->data;
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

    cout<<"Number of nodes: "<<countNodes(root)<<endl;
    cout<<"Sum of all nodes: "<<sumOfNodes(root)<<endl;
}