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

//FUNCTION TO FIND SUM TREE
//RETURNS 2 VALUES AT A TIME SO WE USE PAIR IN THIS CASE
pair<bool,int> isSumTree(Node* root)
{
    //base case
    //if root is null
    if(root==NULL)
    {
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    //check if leaf node
    if(root->left==NULL && root->right==NULL)
    {
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }

    //SUM FROM LEFT SUB TREE
    pair<bool,int>leftAns=isSumTree(root->left);
    //SUM FROM RIGHT  SUB TREE
    pair<bool,int>rightAns=isSumTree(root->right);
    //leftAns and rightAns has 2 parts 
    //first part is true or false 
    //second part has value which is sum

    //CHECK IF LEFT SUB TREE WAS A SUM TREE OR NOT
    //FIRST PART OF THE PAIR
    bool left=leftAns.first;
    //CHECK IF RIGHT SUB TREE WAS A SUM TREE OR NOT
    //SECOND PART OF THE PAIR
    bool right=rightAns.first;

    //CHECK CONDITION
    //SUM IS STORED IN SECOND PART OF PAIR
    bool condition = (root->data == leftAns.second+rightAns.second);

    pair<bool,int>ans;
    if(left && right && condition)
    {
        ans.first = true;
        // ans.second = root->data + left.second + right.second;
        ans.second = 2* root->data;
    }
    else
    {
        ans.first=false;
    }
    return ans;
}

bool isSum(Node* root)
{
    return isSumTree(root).first;
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

    if(isSum(root)==true)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}