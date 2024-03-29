//NESTED BRACKET
//CHECK THE VALIDITY OF THE EXPRESSION CONTAINING NESTED BRACKETS
/* MEANS: 
1) total number of left brackets must be equal to the total
number of right brackets 
2) For every right brackets, there should be a left bracket of same type
3) () <> {} []
*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int top=-1;
char s[MAX];

//isFull FUNCTION
int isFull()
{
    if(top==MAX-1)
    {
        return 1; 
    }
    else
    return 0;
}

//isEmpty FUNCTION
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else 
    return 0;
}

//POP FUNCTION
int pop()
{   
    int value;
    if(top==-1)
    {
        cout<<"Stack underflow";
        exit(1); //abnormal terminaton of a program with failure.
    }
    value=s[top];
    top=top-1;
    return value;
}

//PUSH FUNCTION
void push(int data)
{
    if(isFull())
    {
        cout<<"Stack overflow!"<<endl;
        return;
    }
    top=top+1;
    s[top]=data; //storing data in index 0
}

int match_char(char x, char y)
{
    if(x=='(' && y==')')
    {
        return 1;
    }
    if(x=='{' && y=='}')
    {
        return 1;
    }
    if(x=='[' && y==']')
    {
        return 1;
    }

    return 0;
    
}

int check(char* expr)
{
    int i;
    char temp;
    for(i=0; i<strlen(expr); i++)
    {
        if(expr[i]=='[' || expr[i]=='(' || expr[i]=='{')
        {
            push(expr[i]);
        }
        if(expr[i]==']' || expr[i]==')' || expr[i]=='}')
        {
            if(isEmpty())
            {
                cout<<"Unbalanced"<<endl;
                return 0;
            }
            else
            {
                temp=pop();
                if(!match_char(temp,expr[i]))
                {
                    cout<<"Unbalanced"<<endl;
                    return 0;
                }
            }
        }
    }
    if(isEmpty())
    {
        cout<<"Balanced"<<endl;
        return 1;
    }
    else
    {
        cout<<"Unbalanced"<<endl;
        return 0;
    }
}

int main()
{
    char expr[MAX];
    int result;
    cout<<"Enter the expression: ";
    gets(expr);

    result=check(expr);
    if(result==1)
    {
        cout<<"Expression is valid"<<endl;
    }
    else
    {
        cout<<"Expression is not valid"<<endl;
    }
    return 0;
}