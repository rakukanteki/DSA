//LEVEL ORDER TRAVERSING
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

int calHeight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    //recursive call
    int leftHeight=calHeight(root->left);
    int rightHeight=calHeight(root->right);
    return max(leftHeight,rightHeight)+1;
}

//NORMAL WAY
// int calDiameter(Node* root)
// {
//     if(root==NULL)
//     {
//         return 0;
//     }

//     int leftHeight=calHeight(root->left);
//     int rightHeight=calHeight(root->right);
//     int currDiameter=leftHeight+rightHeight+1;

//     int leftDiameter=calDiameter(root->left);
//     int rightDiameter=calDiameter(root->right);

//     return max(currDiameter,max(leftDiameter,rightDiameter));
// }

//OPTIMIZED WAY
int calDiameter(Node* root,int* height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    //CALCULATING HEIGHT FOR LEFT SUB-TREE AND RIGHT SUB-TREE
    int lh=0,rh=0;
    int ld=calDiameter(root->left,&lh);
    int rd=calDiameter(root->right,&rh);

    int currDiameter=lh+rh+1; 
    *height=max(lh,rh)+1;

    return max(currDiameter,max(ld,rd));

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

    //PrintLevelOrder(root);
    int height=0;
    cout<<"Heigth: "<<calHeight(root)<<endl;
    cout<<"Diameter: "<<calDiameter(root,&height);

    return 0;
}  