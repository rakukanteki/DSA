#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

//FUNCTION FOR BUBBLE SORT
void bubbleSort(int arr[], int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main()
{
    FILE *f;
    //OPENING FILE FOR WRITING "w"
    f = fopen("input.txt","w");

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];

    //STORING RANDOM VALUES
    for(int i=0; i<n; i++)
    {
        arr[i]=1+rand()%100;
    }

    //PRINTING
    cout<<"Before sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }

    auto start = high_resolution_clock::now();

    //BUBBLE SORT
    bubbleSort(arr,n);


    cout<<endl<<"After sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }

    //PUTTING VALUES INSIDE THE FILE
    for(int i=0; i<n; i++)
    {
        fprintf(f,"%d ",arr[i]);
    }
    fclose(f);

    //READING VALUES FROM THE FILE "r"
    f = fopen("input.txt","r");
    for(int i=n; i>0; i--)
    {
        fscanf(f,"%d ", &arr[i]);
    }
    fclose(f);

    //PRINTING THE VALUES (DESCENDING ORDER)
    cout<<endl<<"Sorted in descending: ";
    for(int i=n; i>0; i--)
    {
        cout<<arr[i]<<" ";
    }

    auto stop = high_resolution_clock::now();
    auto  duration = duration_cast<milliseconds>(stop-start);

    cout<<"Time needed: "<<duration.count()<<" Miliseconds"<<endl;
    return 0;
}