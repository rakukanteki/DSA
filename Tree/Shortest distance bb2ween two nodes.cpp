//BINARY TREE
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
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    Node* left=LCA(root->left,n1,n2);
    Node* right=LCA(root->right,n1,n2);

    if(left!=NULL && right!=NULL)
    {
        return root;
    }
    if(left==NULL && right==NULL)
    {
        return NULL;
    }
    if(left!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    
    return LCA(root->right,n1,n2);
}

int findDistance(Node* root, int k, int dist)
{
    //IF THERE IS NO ROOT
    if(root==NULL)
    {
        return -1;   
    }
    //IF K IS FOUND
    if(root->data==k)
    {
        return dist;
    }
    //CHECK IF K LIES IN LEFT OR RIGHT SUB-TREE
    //DISTANCE IS INCREASED BY ONE BECAUSE WE 
    //TRAVEL 1 EDGE TO GO THE LEFT CHILD
    int left=findDistance(root->left,k,dist+1);
    //IF K IS FOUND IN LEFT SUB-TREE
    if(left!=-1)
    {
        return left;
    }
    //NOW IF K IS FOUND AT RIGHT SUB-TREE
    return findDistance(root->right,k,dist+1);
}

int distanceB2weenNodes(Node* root, int n1, int n2)
{
    //FIND OUT THE LCA
    Node* lca=LCA(root,n1, n2);
    int d1 =findDistance(lca,n1,0);
    int d2 =findDistance(lca,n2,0);

    return d1+d2;
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

    cout<<distanceB2weenNodes(root,4,7)<<endl;
}