//SEARCHING IN BST
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

Node* search(struct Node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data > key)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
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

    int x;
    cout<<"Enter the value you want to find: ";
    cin>>x;

    if(search(root,x)==NULL)
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Found"<<endl;
    }

    return 0;
}