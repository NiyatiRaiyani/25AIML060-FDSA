#include <iostream>
using namespace std;

// Iterative Binary Search
int iterativeSearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        else if (target > arr[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// Recursive Binary Search
int recursiveSearch(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;

    else if (target > arr[mid])
        return recursiveSearch(arr, mid + 1, high, target);

    else
        return recursiveSearch(arr, low, mid - 1, target);
}

int main()
{
    int n, target;

    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted book codes: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target book code: ";
    cin >> target;

    int pos1 = iterativeSearch(arr, n, target);
    int pos2 = recursiveSearch(arr, 0, n - 1, target);

    if (pos1 != -1)
        cout << "\nIterative Search: Found at position " << pos1 + 1;
    else
        cout << "\nIterative Search: Not Found";

    if (pos2 != -1)
        cout << "\nRecursive Search: Found at position " << pos2 + 1;
    else
        cout << "\nRecursive Search: Not Found";

    return 0;
}
