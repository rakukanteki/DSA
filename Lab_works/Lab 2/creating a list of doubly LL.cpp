#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* addtoempty(struct node* head, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;

    return head;
}

//ADDING A NODE AT THE END
struct node* addatend(struct node* head, int data)
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
    int n, data,i;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    if(n==0)
    {
        return head;
    }
    else
    {
        cout<<"Enter the element for node 1: ";
        cin>>data;
        head=addtoempty(head,data);

        for(i=1; i<n; i++)
        {
            cout<<"Enter the element for the node "<<(i+1)<<":";
            cin>>(data);
            head = addatend(head,data);
        }
        return head;
    }
}

int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    struct node *ptr;
    head=createList(head);

    ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<' ';
        ptr=ptr->next;
    }
    return 0;
}