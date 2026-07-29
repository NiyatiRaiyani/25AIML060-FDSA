#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[]={78,45,90,32,67,10,55};
    int n=7;

    insertionSort(arr,n);
    cout<<"Insertion Sort : ";
    print(arr,n);

    return 0;
}
