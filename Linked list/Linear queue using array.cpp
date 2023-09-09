//CODE CHEF "LINEAR QUEUE USING ARRAY"
//NSECDS15

#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int n,front=-1,rear=-1;

void push(int value)
{
    if(rear==n-1)
    {
        cout<<"Overflow"<<endl;
        return;
    }
    else
    {
        if(front==-1)
        {
            front =0;
            rear++;
            arr[rear]=value;
        }
    }
}

void pop()
{
    if(front==-1 || front>rear)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        front++;
    }
}

void Display_F()
{
    if(front==-1)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<arr[front]<<endl;
    }
}

void Display_R()
{
    if(rear==-1||front>rear)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<arr[rear]<<endl;
    }
}

int main()
{
    int t,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        while(q--)
        {
            char ch;
            int x;
            cin>>ch;

            if(ch=='E')
            {
                cin>>x;
            }

            switch(ch)
            {
                case 'E':  
                    push(x);
                    break;
                case 'D':
                    pop();
                    break;
                case 'F':
                    Display_F();
                    break;
                case 'R':
                    Display_R();
                    break;
                default:
                    cout<<"invalid choice"<<endl;
            }
        }
        while(front<=rear)
        {
            pop();
        }
        front=-1;
        rear=-1;
    }
    return 0;
}