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

int search(int in[], int start, int end, int value)
{
    for(int i=start; i<=end; i++)
    {
        if(in[i]==value)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int post[], int in[], int start, int end)
{
    //STARTING FROM THE LAST INDEX OF POST-ORDER
    static int index=4;
    //BASE CASE
    if(start>end)
    {
        return NULL;
    }
    //PICKING UP THE ELEMENT
    int value = post[index];
    //DECREMENTING INDEX OF POST-ORDER ARRAY
    index--;
    //CREATING NODE OF THAT PICKED ELEMENT
    Node* curr= new Node(value);
    if(start==end)
    {
        return curr;
    }
    //SEARCHING THE ELEMENT IN IN-ORDER ARRAY
    int pos=search(in,start,end,value);
    //BUILDING RIGHT SUB-TREE
    curr->right=buildTree(post,in,pos+1,end);
    //BUILDING LEFT SUB-TREE
    curr->left=buildTree(post,in,start,pos-1);

    return curr;

}

//INORDER TRAVERSAL
void inorderPrint(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<' ';
    inorderPrint(root->right);
}

int main()
{
    int post[]={4,2,5,3,1};
    int in[]={4,2,1,5,3};
    
    Node* root=buildTree(post,in,0,4);
    inorderPrint(root);

    return 0;
} 