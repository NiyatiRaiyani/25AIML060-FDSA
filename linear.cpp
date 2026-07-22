#include <iostream>
using namespace std;


int linearSearchIterative(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {12, 45, 3, 67, 29, 8, 91};
    int n = 7, target = 29;

    int result = linearSearchIterative(arr, n, target);

    if (result != -1)
        cout << "Found at index " << result;
    else
        cout << "Not Found";

    return 0;
}
