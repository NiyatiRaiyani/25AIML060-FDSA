#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped = false;

        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        swap(arr[i], arr[min]);
    }
}

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

    bubbleSort(arr,n);
    cout<<"Bubble Sort : ";
    print(arr,n);

    return 0;
}
