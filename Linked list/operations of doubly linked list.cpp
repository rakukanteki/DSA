//INSERTING A NODE IN A EMPTY LIST
#include<bits/stdc++.h>
using namespace std;
struct node
{
    struct node* prev;
    int data;
    struct node *next;
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

//INSERTING A NODE AT THE BEGINING 
struct node* addatbegin(struct node* head,int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    temp->next=head;
    head->prev=temp;
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

//ADDING A NODE AT A CERTAIN POSITION AFTER A NODE
struct node* addatposition(struct node* head, int data, int pos)
{
    struct node* temp, *temp2, *newnode;
    temp=head;
    newnode=addtoempty(newnode,data);//called for creating a new node
    while(pos != 1)
    {
        temp = temp->next;
        pos--;
    } 
    //CONSIDERING IF WE ARE ADDING AT THE END OF A LIST
    if(temp->next == NULL)
    {
        temp->next=newnode;
        newnode->prev=temp; 
    }
    else
    {
        temp2=temp->next;
        temp->next=newnode;
        temp2->prev=newnode;
        newnode->next=temp2;
        newnode->prev=temp;
    }

    return head;

}

//ADDING A NODE AT A CERTAIN POSITION AFTER A NODE
struct node* addbeforeposition(struct node* head, int data, int pos)
{
    struct node* temp, *temp2, *newnode;
    newnode=NULL;
    temp2=NULL;
    temp=head;
    newnode=addtoempty(newnode,data);//called for creating a new node
    while(pos > 2)//we are adding position 3
    {
        temp = temp->next;
        pos--;
    } 
    //CONSIDERING IF WE ARE ADDING AT THE BEGINING OF A LIST
    if(pos==1)
    {
        
        head=addatbegin(head,data);
    }
    else
    {
        temp2=temp->next;
        temp->next=newnode;
        temp2->prev=newnode;
        newnode->next=temp2;
        newnode->prev=temp;
    }

    return head;

}

//DELETING THE FIRST NODE
struct node* delfirst(struct node* head)
{   
    struct node* temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;

    return head;
}

//DELETING THE LAST NODE
struct node* dellast(struct node* head)
{
    struct node* temp, *temp2;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp2 = temp->prev;
    temp2->next=NULL;
    free(temp);
    temp=NULL;

    return head;
}

//DELETING A CERTAIN NODE
struct node* delposition(struct node* head,int position)
{
    struct node* temp, *temp2;
    temp=head;
    temp2=NULL;
    if(position==1)
    {
        head=delfirst(head);
    }
    else
    {
        while(position>1)//say we are deleting 2nd node
        {
            temp=temp->next;
            position--;
        }
    }
    if(temp->next==NULL)
    {
        head=dellast(head);
    }
    else
    {
        temp2=temp->next;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}

int main()
{ 
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* ptr;
    cout<<"Before deletion: ";
    head=NULL;
    head=addtoempty(head,45);
    head=addatbegin(head,34);
    head=addatend(head,55);
    head=addatposition(head, 69, 2);
    head=addbeforeposition(head,12,3);

    cout<<"After deletion: ";
    head=delfirst(head);

    //PRINTING 
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    return 0;
}