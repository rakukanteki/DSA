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

//SORTING THE LIST
//BUBBLE SORT
struct node* sort(struct node* head)
{
    struct node* ptr1, *ptr2;
    ptr1=head;

    if(head==NULL)
    {
        cout<<"No nodes"<<endl;
    }
    else
    {
        while(ptr1->link!=NULL)
        {
            ptr2=ptr1->link;
            while(ptr2!=NULL)
            {
                if(ptr1->data > ptr2->data)
                {
                    int temp=ptr1->data;
                    ptr1->data=ptr2->data;
                    ptr2->data=temp; 
                }
                ptr2=ptr2->link;
            }
            ptr1=ptr1->link;
        }
        return head;
    }
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
    cin>>n;
    
    cin>>(head->data);
    head->link = NULL;
    head = creating_list(head,n);
    printing(head);
    cout<<endl<<"Sorted list 1: ";
    head=sort(head);
    printing(head);
    
    return 0;
}