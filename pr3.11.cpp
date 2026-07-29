#include <iostream>
using namespace std;

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

    selectionSort(arr,n);
    cout<<"Selection Sort : ";
    print(arr,n);

    return 0;
}
