#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

//FUNCTION FOR CREATING NODES
struct node* creating_list(struct node* head, int n)
{
    struct node* ptr=head;
    for(int i=0; i<n-1; i++)
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        //cout<<"Enter the node number "<<(i+2)<<": ";
        cin>>(temp->data);
        ptr->link = temp;
        temp->link = NULL;
        ptr=temp;
    }   
    return head;
}

//MERGING TWO LIST
void merging(struct node* head, struct node* head2)
{
    struct node*ptr=NULL;
    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=head2;

}


//FUNCTION FOR PRINTING
void printing(struct node* head)
{
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<' ';
        ptr=ptr->link;
    }
}

int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* head2=(struct node*)malloc(sizeof(struct node));
    int n,n2;
    cout<<"Enter the size for list 1: ";
    cin>>n;

    cout<<"List 1: ";
    cin>>(head->data);
    head->link = NULL;
    head = creating_list(head,n);
    printing(head);

    cout<<endl<<"Enter the size for list 2: ";
    cin>>n2;
    cout<<endl<<"List 2: ";
    cin>>(head2->data);
    head2->link = NULL;
    head2 = creating_list(head2,n2);
    printing(head2);

    merging(head,head2);
    cout<<endl<<"Merged list: ";
    printing(head);
    
    return 0;
}