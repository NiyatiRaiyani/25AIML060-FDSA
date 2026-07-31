#include <iostream>
using namespace std;

int findKthMissing(int arr[], int n, int k)
{
    int missing = 0;
    int prev = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = prev + 1; j < arr[i]; j++)
        {
            missing++;
            if (missing == k)
                return j;
        }
        prev = arr[i];
    }

    int num = arr[n - 1];

    while (missing < k)
    {
        num++;
        missing++;
    }

    return num;
}

int main()
{
    int n, k;

    cout << "Enter number of assigned roll numbers: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted roll numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;

    cout << "Kth Missing Roll Number = " << findKthMissing(arr, n, k);

    return 0;
}
