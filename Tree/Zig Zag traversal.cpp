//ZIG ZAG TRAVERSAL OR SPIRAL TRAVERSAL
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

vector<int> zigzag(Node* root)
{
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<Node*>q;
    q.push(root);

    //lefttoright will decide whether we will insert in normal way(L-R)
    //or reversed way (R-L)
    bool lefttoright=true;
    //until queue becomes empty
    while(!q.empty())
    {
        int size=q.size(); //size of level
        //we will push values inside temp in two way L-R and R-L
        vector<int>temp(size);
        //LEVEL PROCESS
        for(int i=0; i<size; i++)
        {
            //store the front node
            Node* frontNode=q.front();
            q.pop(); 

            //find index by which we will insert value in temp vector
            int index=lefttoright? i:size-i-1;
            temp[index] = frontNode->data;

            //if frontNode's left child is not null then
            if(frontNode->left!=NULL)
            {
                q.push(frontNode->left);
            }
            //if frontNode's right child is not null then
            if(frontNode->right!=NULL)
            {
                q.push(frontNode->right);
            }
        }
        //AFTER PROCESSING EVERY LEVEL CHANGE THE DIRECTION
        lefttoright= !lefttoright;
        for(auto i: temp)
        {
            ans.push_back(i);
        }
    }
    return ans;
}


int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<int> result = zigzag(root);
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<' ';
    }
    
    return 0;
}