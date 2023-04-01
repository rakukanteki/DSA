#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;
int main()
{
    int n,temp;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];

    for(int i=0; i<n-1; i++)
    {
        //generating random values
        arr[i]=1+rand()%1000;
    }

    for(int i=0; i<n-1; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;

    //TIME COUNT STARTS
    auto start = high_resolution_clock::now();

    //SWAPPING  
    for(int i=n; i>=0; i--)
    {
        temp = arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }
    //INSERTING VALUE AT INDEX 0
    cout<<endl<<"Insert value for 0 index: ";
    cin>>arr[0];
    
    //TIME STOPS
    auto stop = high_resolution_clock::now();
    //MEASURING TIME
    auto duration = duration_cast<milliseconds>(stop-start);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }

    cout<<endl<<"Time taken : "<<duration.count()<<" Miliseconds"<<endl;

    return 0;
}