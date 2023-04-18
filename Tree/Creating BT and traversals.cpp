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

//CREATING TREE
node* buildTree(struct node* root)
{   
    int data;
    cout<<"Enter data: ";
    cin>>data;
    root=new node(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter the left element for "<<data<<": "<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the right element for "<<data<<": "<<endl;
    root->right=buildTree(root->right);
    return root;

}

void levelOrderTraversal(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        cout<<temp->data<<' ';
        q.pop();

        // //if a level is completly traversed
        // if(temp==NULL)
        // {
        //     cout<<endl;
        //     if(!q.empty()) //queue still got some values
        //     {

        //     }
        // }

        //if a node has left child nodes or right child nodes
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}

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

//PRE-ORDER TRAVERSAL
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}

//POST-ORDER TRAVERSAL
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<' ';  
}

int main()
{
    node* root=NULL;
    root=buildTree(root);
    cout<<endl<<"Level order traversal: ";
    levelOrderTraversal(root);
    return 0;
}