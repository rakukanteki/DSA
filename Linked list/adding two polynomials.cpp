//ADDITION OF TWO POLYNOMIALS
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int expo;
    float coeff;
    struct node* link;
};

//INSERTING
struct node* insert(struct node* head, float c, int e)
{
    struct node* temp;  
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=c;
    newnode->expo=e;
    newnode->link=NULL;

    if(head==NULL || e> head->expo)
    {
        newnode->link=head;
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL && temp->link->expo >= e)
            temp=temp->link;
        newnode->link=temp->link;
        temp->link=newnode;
    }
    return head;
}

//PRINTING 
void print(struct node* head)
{
    if(head==NULL)
    {
        cout<<"No polynomials"<<endl;
    }
    else
    {
        struct node* temp=head;
        while(temp!=NULL)
        {
            cout<<(temp->coeff)<<"x^"<<(temp->expo);
            temp=temp->link;
            if(temp!=NULL)
            {
                cout<<"+";
            }
            else
            {
                cout<<endl;
            }
        }

    }
}

//FUNCTION FOR ADDING TWO POLYS
void polyAdd(struct node* head1, struct node* head2)
{
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {  
            head3=insert(head3, ptr1->coeff+ptr2->coeff, ptr1->expo);        
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3=insert(head3, ptr1->coeff, ptr1->expo);
            ptr1=ptr1->link;
        }
        else if(ptr2->expo > ptr1->expo)
        {
            head3=insert(head3, ptr2->coeff, ptr2->expo);
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL)
    {
        head3=insert(head3, ptr1->coeff, ptr1->expo);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL)
    {
        head3=insert(head3, ptr2->coeff, ptr2->expo);
        ptr2=ptr2->link;
    }
    cout<<"Added poly: ";
    print(head3);
}

//CREATING POLYNOMIALS
struct node* creatPolynomial(struct node* head)
{
    int n,i,expo;
    float coeff;
    cout<<"Enter the number of terms: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter the coefficient and exponent accordingly: ";
        cin>>coeff>>expo;
        head=insert(head,coeff,expo);
    }
    return head;
}

int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    cout<<"Enter the first poly: "<<endl;
    head1=creatPolynomial(head1);
    cout<<"Enter the second poly: "<<endl;
    head2=creatPolynomial(head2);
    polyAdd(head1, head2);

    return 0;
}