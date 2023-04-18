#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

//INSERTION IN BINARY SEARCH TREE
Node* insertBST(Node* root, int value)
{
    if(root==NULL)
    {
        //WHEN NO COMPARISON POSSIBLE
        //WHEN root IS NULL. THEN ONLY PASS VALUE
        return new Node(value);
    }
    if(value<root->data)
    {
        root->left=insertBST(root->left,value);
    }
    else
    {
        root->right=insertBST(root->right,value);
    }

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<(root->data)<<' ';
    inorder(root->right);
}

int main()
{
    Node* root = NULL;
    int n,x;
    cout<<"Enter the size of array: ";
    cin>>n;
    cin>>x;
    root=insertBST(root, x);
    for(int i=1; i<n; i++)
    {
        cin>>x;
        insertBST(root, x);
    }
    // insertBST(root, 1);
    // insertBST(root, 3);
    // insertBST(root, 4);
    // insertBST(root, 2);
    // insertBST(root, 7);

    inorder(root);

    return 0;
}