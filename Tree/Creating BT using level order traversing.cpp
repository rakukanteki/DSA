//CREATING BINARY TREE USING LEVEL ORDER TRAVERSAL
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

//INORDER TRAVERSAL
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

void buildfromlevelordertraversing(node* &root)
{
    queue<node*>q;
    cout<<"Enter data for root: ";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node* root=NULL;
    
    buildfromlevelordertraversing(root);
    cout<<endl<<"Inorder traversal: ";
    inorder(root);
    return 0;
}