//USING PRIORITY QUEUE
#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>pq;

    //CREATES MAX HEAP BY DEFAULT
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element at top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top: "<<pq.top()<<endl;
    cout<<pq.size();
    
    if(pq.empty())
    {
        cout<<"pq is empty"<<endl;
    }
    else
    {
        cout<<"pq is not empty"<<endl;
    }

    //CREATING MIN HEAP
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"Element at top: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Element at top: "<<minheap.top()<<endl;
    cout<<minheap.size();
    
    if(minheap.empty())
    {
        cout<<"minheap is empty"<<endl;
    }
    else
    {
        cout<<"minheap is not empty"<<endl;
    }

    return 0;
}