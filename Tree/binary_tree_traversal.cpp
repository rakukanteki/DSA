//BINARY TREE
#include<bits/stdc++.h>
using namespace std;

//CREATING A NODE FOR BINARY TREE
struct node
{
    int data;
    struct node* left;
    struct node* right;

    //CONSTRUCTOR
    node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

//PREORDER TRAVERSAL
void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}

//INORDER TRAVERSAL
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

//POSTORDER TRAVERSAL
void postorder(struct node* root)
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
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    /*
            1
          /   \
        2       3
    */

    root->left->left=new node(4);
    root->left->right= new node(5);
    /*
            1
          /   \
        2       3
       / \
      4   5
    */
    root->right->left=new node(6);
    root->right->right= new node(7);
    /*
            1
          /   \
        2       3
       / \     / \
      4   5   6   7
    */

    cout<<"Preorder traversasl: ";
    preorder(root);
    cout<<endl<<"Inorder traversal: ";
    inorder(root);
    cout<<endl<<"Post-order traversal: ";
    postorder(root);
    return 0;
}