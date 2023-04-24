//IS BST A HEAP TREE
#include<bits/stdc++.h>
using namespace std;

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

int countNode(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int ans=1+countNode(root->left)+countNode(root->right);
        return ans;
    }
}

bool isCBT(struct Node* root, int index, int cnt)
{
    if(root==NULL)
    {
        return true;
    }
    //if index is greater than total number of nodes
    if(index>=cnt)
    {
        return false;
    }
    else
    {
        bool left=isCBT(root->left, 2*index+1, cnt);
        bool right=isCBT(root->right, 2*index+2, cnt);

        return (left && right);
    }

}

bool isMaxOrder(struct Node* root)
{
    //base case
    //if leaf node
    if(root->left == NULL && root->right==NULL)
    {
        return true;
    }
    // if only left childs exists
    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    //if both child exists
    else
    {
        bool left=isMaxOrder(root->left);
        bool right=isMaxOrder(root->right);

        return (left && right && (root->data) > (root->left->data) && (root->right));
    }
}

bool isHeap(struct Node* root)
{
    int index=0;
    int totalNodes=countNode(root);

    if(isCBT(root,index,totalNodes) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}
