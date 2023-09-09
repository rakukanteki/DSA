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
    cout<<endl<<"Sorted list 1: ";
    head=sort(head);
    printing(head);

    cout<<endl<<"Enter the size for list 2: ";
    cin>>n2;
    cout<<endl<<"List 2: ";
    cin>>(head2->data);
    head2->link = NULL;
    head2 = creating_list(head2,n2);
    printing(head2);
    cout<<endl<<"Sorted list 2: ";
    head2=sort(head2);
    printing(head2);

    merging(head,head2);
    cout<<endl<<"Merged list: ";
    printing(head);

    head=sort(head);
    cout<<endl<<"Sorted merged list: ";
    printing(head);
    
    return 0;
}