#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* link;
};

struct node* create_list(node* head, int n)
{
    struct node* ptr=head;
    for(int i=1; i<=n-1; i++)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        cout<<"Enter the node number "<<i+1<<" : ";
        cin>>(temp->data);
        temp->link=NULL;
        ptr->link=temp;
        ptr=temp;
    }
    return head;
}

struct node* deleting_first_node(struct node* head)
{
    if(head==NULL)
    {
        cout<<"List is already empty"<<endl;
    }
    else
    {
        struct node* temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
    }

    return head;
}

struct node* deleting_the_last_node(struct node* head)
{
    if(head==NULL)
    {
        cout<<"List is already empty"<<endl;
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node* ptr=head;
        struct node* ptr2=head;
        while(ptr->link!=NULL) 
        {
            ptr2=ptr;
            ptr=ptr->link;
        }
        ptr2->link=NULL;
        free(ptr);
        ptr=NULL;
    }

    return head;
}

struct node* delete_the_whole_node(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->link;
        free(head);
        head=temp;
    }

    return head;
}

struct node* deleting_at_a_position(struct node* head, int pos)
{
    struct node* current=head;
    struct node* previous=head;
    if(head==NULL)
    {
        cout<<"There is no node"<<endl;
    }
    else if(pos==1)
    {
        head=current->link;
        free(current);
        current=NULL;
    }
    else
    {
        for(int i=1; i<pos; i++)
        {
            previous=current;
            current=current->link;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
    return head;
}

void printing(struct node* head)
{
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<' '; 
        ptr=ptr->link;
    }
}
 
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    int n,pos;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the node number 1 : ";
    cin>>(head->data);
    head->link=NULL;

    head=create_list(head, n);
    
    // head=deleting_first_node(head);
    // head=deleting_the_last_node(head);
    cout<<"Enter the position you want to delete: ";
    cin>>pos;
    head=deleting_at_a_position(head, pos);

    printing(head);
    return 0;
}