//CHECKING IF A LIST IS PALINDROME OR NOT
//REVERSING A LIST
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
    struct node* prev;
};

//REVERSING A LIST
struct node* reversing(struct node* head)
{
    struct node* prev=NULL;
    struct node* next=NULL;

    while(head!=NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head=next;
    }
    head=prev;
    return head;
}

bool isPalindrome(struct node* head)
{
    //FINDING THE MIDDLE
    struct node* fast=head;
    struct node* slow=head;
    while(fast!=NULL && fast->link!=NULL)
    {
        fast=fast->link->link;
        slow=slow->link;
    }

    //REVERSING THE LAST HALF
    slow=reversing(slow);
    fast=head;

    //COMPARING
    while(slow!=NULL)
    {
        if(fast->data!=slow->data)
        {
            return false;
        }
        else
        {
            fast=fast->link;
            slow=slow->link;
        }
        return true;
    }
}

struct node* creating_list(struct node* head, int n)
{
    struct node* ptr=head;
    for(int i=0; i<n-1; i++)
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        //cout<<"Enter the "<<(i+2)<<" node: ";
        cin>>(temp->data);
        ptr->link = temp;
        temp->link = NULL;
        ptr=temp;
    }

    return head;
}

//PRINTING
void printing(struct node* head)
{
    if(head==NULL)
    {
        cout<<"List is empty!";
    }
    else
    {
        struct node* ptr=NULL;
        ptr=head;
        while(ptr!=NULL)
        {
            cout<<(ptr->data)<<' ';
            ptr=ptr->link;
        }
    }
}

int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    int n;
    cout<<"Enter the size of the list: ";
    cin>>n;
    cin>>(head->data);
    head->link=NULL;
    head=creating_list(head,n);
    printing(head);

    if(isPalindrome(head)==true)
    {
        cout<<"Palindrome"<<endl;
    }
    else
    {
        cout<<"Not palindrome"<<endl;
    }
    return 0;
}
