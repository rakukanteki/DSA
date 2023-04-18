//DELETE IN BST
//ALSO BE CONCERN, THAT THE PROPERTIES OF BST DOESN'T CHANGE
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

Node* inorderSuccessor(Node* root)
{
    Node* curr=root;
    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

Node* deleteInBST(struct Node* root, int key)
{
    //FIND WHERE THE KEY LIES
    if(key<root->data)
    {
        root->left=deleteInBST(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=deleteInBST(root->right, key);
    }
    else
    {
        //CASE 1 AND 2
        if(root->left==NULL)
        {
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root->left;
            free(root);
            return temp;
        }
        //CASE 3
        Node* temp=inorderSuccessor(root->right);
        {
            root->data=temp->data;
            root->right=deleteInBST(root->right, temp->data);
        }
    }
    return root;
}

//INORDER TRAVERSAL
void inorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

int main()
{
    struct Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);

    int x;
    cout<<"Enter the node you want to delete: ";
    cin>>x;

    root=deleteInBST(root,x);
    inorder(root);

    return 0;
}