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
    int arr[] = {12,35,45,89,91,19,15,135};
    int n = 7, target = 89;

    int result = linearSearchIterative(arr, n, target);

    if (result != -1)

        cout << "Found at index " << result;
    else
        cout << "Not Found";

    return 0;
}
