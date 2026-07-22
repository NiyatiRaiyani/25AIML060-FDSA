#include <iostream>
using namespace std;


int linearSearchRecursive(int arr[], int i, int n, int target)
{
    if (i == n)
        return -1;
    if (arr[i] == target)
        return i;

    return linearSearchRecursive(arr, i + 1, n, target);

}

int main() {

    int arr[] = {12,35,45,89,91,19,15,135};
    int n = 7;
    int target = 19;

    int result = linearSearchRecursive(arr, 0, n, target);

    if (result != -1)
        cout << "Found at index " << result;
    else
        cout << "Not Found";

    return 0;
}
