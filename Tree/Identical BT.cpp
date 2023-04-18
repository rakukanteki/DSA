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

//IS IDENTICAL FUNCTION
bool isIdentical(Node* root1, Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else if(root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        bool cnd1= (root1->data == root2->data);
        bool cnd2=isIdentical(root1->left, root2->left);
        bool cnd3=isIdentical(root1->right, root2->right);
        if(cnd1 && cnd2 && cnd3)
        {
            return true;
        }
        return false;
    }
}

int main()
{

    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(3);

    Node* root2=new Node(6);
    root2->left=new Node(3);
    root2->right=new Node(10); 

    if(isIdentical(root1,root2))
    {
        cout<<"BSTs are identical"<<endl;
    }
    else
    {
        cout<<"Not identical"<<endl;
    }
}