#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* prev=NULL;
    struct node* next=NULL;
};

struct node* createNode(struct node* head,int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;

    return head;
}

struct node* addAtEnd(struct node* head, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    node* tra=head;
    while(tra->next != NULL)
    {
        tra=tra->next;
    }
    tra->next=temp;
    temp->prev=tra;

    return head;
}

struct node* createList(struct node* head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int nodes, i,data;
    cout<<"Enter the number of nodes: ";
    cin>>nodes;

    if(nodes==0)
    {
        return head;
    }
    cout<<"Enter the node number 1: ";
    cin>>data;
    head= createNode(head, data);

    for(i=1; i<nodes; i++)
    {
        cout<<"Enter the node number 2: ";
        cin>>data;
        head=addAtEnd(head, data);
    }

    return head;
}

void printing(struct node* head)
{
    struct node* ptr=head;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    
}

int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=createList(head);

    printing(head);
    return 0;
}