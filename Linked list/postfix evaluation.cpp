//CONVERTING AN INFIX EXPPRESSION INTO POSTFIX EXPRESSION
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

char st[MAX];
char infix[MAX];
char postfix[MAX];
int top=-1;

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
    value=st[top];
    top=top-1;
    return value;
}

int space(char c)
{
    if(c==' '||c=='\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
    st[top]=data; //storing data in index 0
}

//CHECKING PRECEDENCE
int precedence(char symbol)
{
    
    switch(symbol)
    {
        //greater value means higher precedence
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }    
    
}

void infixToPostfix(char* infix)
{
    int i,j=0;
    char symbol,next;
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        if(!space(symbol))
        {
            switch(symbol)
            {
                case '(':
                case '{':
                case '[':
                    push(symbol);
                    break;
                case ')':
                case '}':
                case ']':
                    while((next=pop()) != '(')
                    {
                        postfix[j++]=next;
                    }
                    break;   
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(!isEmpty() && precedence(st[top])>=precedence(symbol))
                    {
                        postfix[j++]=pop();
                    }
                    push(symbol);
                    break;
                default:
                    postfix[j++]=symbol; //if operand
            }
        }
    }
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

//PRINT FUNCTION
void print()
{
    int i=0;
    cout<<"The final postfix expression is: ";
    while(postfix[i])
    {
        cout<<postfix[i++];
    }
}

int evaluation()
{
    int i,a,b;
    for(i=0; i<strlen(postfix); i++)
    {
        //we need integers not characters
        //CONVERTING CHARACTERS INTO INTEGERS
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '^':
                    push(pow(b,a));
                    break;
            }
        }
    }
    return pop();
}

int main()
{
    int result;
    cout<<"Enter the infix expression: ";
    gets(infix);

    infixToPostfix(infix);
    print();
    result=evaluation();
    cout<<"Result after postfix evaluation: "<<result<<endl;

    return 0;
}