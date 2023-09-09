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
        cout<<"Enter the node number "<<(i+2)<<": ";
        cin>>(temp->data);
        ptr->link = temp;
        temp->link = NULL;
        ptr=temp;
    }   
    return head;
}
//ADDING A NODE AT THE BEGINNING OF THE LIST

struct node* at_the_begin(struct node* head, int value)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->link=NULL;

    ptr->link=head;
    head=ptr;

    return head;
}
//ADDING A NODE AT A CERTAIN POSITION 
///IF THE POSITION IS KNOWN

void add_at_position(struct node* head, int value, int pos)
{
    //CREATING THE NODE TO BE ADDED AT A CERTAIN POSITON
    struct node* ptr=(node*)malloc(sizeof(struct node));
    struct node* ptr2=(node*)malloc(sizeof(struct node));
    ptr2->data=value;
    ptr2->link=NULL;

    //SAY WE WANT TO ADD A NODE AT POSITION 3
    //WE WANT TO MOVE ptr POINTER JUST ONE STEP
    while(pos != 2)
    {
        ptr = ptr->link;
        pos--;   
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;
}

//FUNCTION FOR ADDING A NODE AT THE END OF A LIST
void at_the_end(struct node* head, int value)
{
    struct node* ptr;
    struct node* temp;
    ptr=head;
    //temp contains the node to be added at the end
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;

    while(ptr->link != NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;

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
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    cout<<"Enter the 1st node : ";
    cin>>(head->data);
    head->link = NULL;
    head = creating_list(head,n);
    cout<<"Before deleting: ";
    printing(head);
    
    return 0;
}