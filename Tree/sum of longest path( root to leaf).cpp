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

void solve(Node* root, int sum, int &maxsum, int len, int &maxlen)
{
    //base case
    if(root==NULL)
    {
        if(maxlen<len)
        {
            maxlen=len;
            maxsum=sum;
        }
        else if(len == maxlen)
        {
            maxsum=max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->data;

    solve(root->left, sum, maxsum, len+1, maxlen);
    solve(root->right, sum, maxsum, len+1, maxlen);

}

int sumOfLongestBloodline(Node* root)
{
    int sum=0;
    int len=0;
    int maxlen=0;
    int maxsum=0;

    solve(root, sum, maxsum, len, maxlen);
    return maxsum;
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

    int result=sumOfLongestBloodline(root);
    cout<<result<<endl;
}