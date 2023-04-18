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

Node* LCA(Node* root, int n1, int n2)
{
    //base case
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data == n1 || root->data == n2)
    {
        return root;
    }

    //SEARCH IN LEFT
    Node* leftAns = LCA(root->left, n1 ,n2);
    //SEARCH IN RIGHT
    Node* rightAns = LCA(root->right, n1 ,n2);

    if(leftAns != NULL && rightAns!=NULL)
    {
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int main()
{

    //BST 
    struct Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);

    cout<<LCA(root,2,5)->data<<' ';
    
}