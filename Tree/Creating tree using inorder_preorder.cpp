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

int search(int in[], int start, int end, int curr)
{
    for(int i=start; i<=end; i++)
    {
        if(in[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int pre[], int in[], int start, int end)
{
    static int index=0;
    if(start>end)
    {
        return NULL;
    }

    int curr=pre[index];
    index++;
    Node* node=new Node(curr);
    if(start==end)
    {
        return node;
    }

    int pos=search(in,start,end,curr);

    //resursive call
    node->left=buildTree(pre,in,start,pos-1);
    node->right=buildTree(pre,in,pos+1,end);   
    return node;
}

//POSTORDER TRAVERSAL
void postorder(struct Node* root)
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
    int pre[]={1,2,4,3,5};
    int in[]={4,2,1,5,3};
    
    Node* root=buildTree(pre,in,0,4);
    postorder(root);

    return 0;
}