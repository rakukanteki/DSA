#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest =i;
    //1 based index
    int left=2*i+1;
    int right = 2*i+2;

    if(left<n && arr[largest]<arr[left])
    {
        largest=left;
    }
    //if largest is less than right child then update largest
    if(right<n && arr[largest]<arr[right])
    {
        largest=right;
    }

    //Check if array is updated then largest will not be equal to i
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int>&b, int n, int m)
{
    //step 1: merge both arrays into 1
    vector<int>ans;
    for(auto i:a)
    {
        ans.push_back(i);
    }
    for(auto i:b)
    {
        ans.push_back(i);
    }
    //step 2: build heap using merged array
    int size=ans.size();
    //for 0 based index
    for(int i=size/2 - 1; i>0; i--)
    {
        heapify(ans, size, i);
    }

    return ans;
}