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

void rightview(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        // nodes here is the number of nodes in current level
        int nodes=q.size();
        for(int i=0; i<nodes; i++)
        {
            Node* curr=q.front();
            //pop the elements to see the nodes
            //The last element will the the required node
            q.pop();
            if(i==nodes-1)
            {
                cout<<curr->data<<' ';
            }
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void leftview(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        // nodes here is the number of nodes in current level
        int nodes=q.size();
        for(int i=0; i<nodes; i++)
        {
            Node* curr=q.front();
            //pop the elements to see the nodes
            //The last element will the the required node
            q.pop();
            if(i==0)
            {
                cout<<curr->data<<' ';
            }
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
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

    cout<<"Right view: ";
    rightview(root);
    cout<<endl<<"Left view: ";
    leftview(root);
}