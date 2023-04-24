 #include<bits/stdc++.h>
using namespace std;

class heap
{
    public: 
        //take a array
        int arr[100];
        int size; 
        
    //constructor
    heap()
    {
        arr[0]=-1;
        size=0;//starting size is 0
    }

    //insertion function
    void insert(int value)
    {
        //insert value at last
        size+=1;
        int index =size;
        arr[index]=value;

        while(index>1)
        {
            //until index is greater than 1
            //find it's parent
            int parent=index/2;
            //compare value with parents
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i=1; i<=size; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
    }

    //deletion function
    void deletion()
    {
        if(size==0)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        else
        {
            //step:1
            //put the last index in first index
            arr[1]=arr[size];
            //step: 2
            size--;
        }

        //step3 : take root node at it's correct position
        int i=1; //root node is at 1st index
        while(i<size)
        {
            int leftindex = 2*i;
            int rightindex=2*i+1;

            //comparing root node with it's child
            if(leftindex<size && arr[i]<arr[leftindex])
            {
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[i]<arr[rightindex])
            {
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest =i;
    int left=2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest]<arr[left])
    {
        largest=left;
    }
    //if largest is less than right child then update largest
    if(right<=n && arr[largest]<arr[right])
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

//HEAP SORT
void heapSort(int arr[], int n)
{
    int size=n;
    while(size>1)
    {
        //Step 1
        //swap
        swap(arr[size],arr[1]);
        size--;

        //step 2
        heapify(arr,size,1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // cout<<"Insertion: ";
    // h.print();
    // h.deletion();n 
    // cout<<endl<<"After deletion: ";
    // h.print();

    int arr[6]={-1,54,53,55,52,50};
    //n is size
    int n=5;
    //HEAP CREATION
    for(int i=n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }
    cout<<"Printing the array: ";
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    
    //HEAP SORT
    heapSort(arr,n);
    cout<<"Printing the array: ";
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}