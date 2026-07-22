#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int target)
{
        if (low > high)
            return -1;
        int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;

            else if (arr[mid] < target)

                return binarySearchRecursive(arr, mid + 1, high, target);

        else

        return binarySearchRecursive(arr, low, mid - 1, target);
}
int main()
{
    int arr[] = {3, 8, 12, 19, 29, 45, 67, 91};
    int n = 8;
    int target = 45;

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Found at index " << result;

    else
        cout << "Not Found";

    return 0;
}
