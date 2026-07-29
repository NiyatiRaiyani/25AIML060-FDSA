#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
    }

int main() {
    int arr[] = {3, 8, 12, 19, 29, 45, 67, 91};
    int n = 8;
    int target = 45;

    int result = binarySearchIterative(arr, n, target);

    if (result != -1)
        cout << "Found at index " << result;
    else
        cout << "Not Found";

    return 0;
}
