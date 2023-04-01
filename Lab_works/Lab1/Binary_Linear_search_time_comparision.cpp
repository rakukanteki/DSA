#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

//FUNCTION FOR LINEAR SEARCH
void LinearSearch(int arr[], int value, int n)
{
    bool flag = true;
    for(int i=0; i<n; i++)
    {
        if(value==arr[i])
        {
            cout<<endl<<endl<<"Value found in Linear Search"<<endl;
            flag = false;
            break;
        }
        if(!flag)
        {
            cout<<endl<<"Not found in Linear Search"<<endl;
        }
    }
}

//FUNCTION FOR BINARY SEARCH
void BinarySearch(int arr[], int value, int n)
{
    bool flag = true;
    int mid,high,low;
    low=0;
    high=n-1;

    while(low<=high)
    {
        mid=(high+low)/2;
        if(arr[mid]==value)
        {
            cout<<endl<<"Value found in Binary Search"<<endl;
            flag = false;
            break;
        }
        else if(arr[mid]<value)
        {
            low = mid+1;
        }
        else if(arr[mid]>value)
        {
            high = mid-1;
        }
        if(!flag)
        {
            cout<<endl<<"Not found in Binary Search"<<endl;
        }
    }
}

int main()
{
    int n,i,cnt=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    //TAKING RANDOM VALUES IN ARRAY
    for(i=0; i<n; i++)
    {
        arr[i] = 1+rand()%n;
    }
    //PRINTING
    cout<<endl<<"Before sorting: "; 
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }

    //SORTING THE ARRAY
    sort(arr, arr+n);
    cout<<endl<<"After sorting: ";
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
    
    //TIME COUNTING FOR LINEAR SEARCHING
    auto start1 = high_resolution_clock::now();
    LinearSearch(arr, 69, n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1-start1);
    cout<<"Time needed for Linear Search: "<<duration1.count()<<" Miliseconds"<<endl;

    //TIME COUNTING FOR BINARY SEARCHING
    auto start2 = high_resolution_clock::now();
    BinarySearch(arr, 69, n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2-start2);
    cout<<"Time needed for Binary Search: "<<duration2.count()<<" Miliseconds"<<endl;

    return 0;
}