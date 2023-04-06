//POLYNOMIALS
#include<bits/stdc++.h>
using namespace std;

struct node
{
    float coef;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head, float c, int e)
{
    struct node* temp;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    newnode->link=NULL;

    if(head==NULL|| e  > head->expo)
    {
        newnode->link=head;
        head=newnode;
    }
    else
    {
        temp = head;
        while(temp->link!=NULL && temp->link->expo >= e)
        {
            temp=temp->link;
        }
        newnode->link=temp->link;
        temp->link=newnode;
    }
    return head; 
}

struct node* createPolynomial(struct node* head)
{
    int n,i;
    float coef;
    int expo;
    cout<<"Enter the number of terms: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter the coefficient and exponent for term accordingly "<<(i+1)<<": ";
        cin>>coef>>expo;
        head=insert(head, coef, expo);
    }
    return head;
}

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
            cout<<(temp->coef)<<"x^"<<(temp->expo);
            temp=temp->link;
            if(temp!=NULL)
            {
                cout<<"+";
            }
            else
            {
                cout<<"\n";
            }
        }
    }
    
}

int main()
{   
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    cout<<"Enter the polynomial"<<endl;
    head=createPolynomial(head);
    print(head);
    return 0;
}

