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
