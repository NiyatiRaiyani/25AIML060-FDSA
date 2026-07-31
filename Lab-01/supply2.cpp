#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of voter IDs: ";
    cin >> n;

    int arr[n];
    int freq[1001] = {0};

    cout << "Enter voter IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    cout << "Voter IDs appearing exactly once are:\n";

    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 1)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
