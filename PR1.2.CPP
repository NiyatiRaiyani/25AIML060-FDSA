#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of book records: ";
    cin >> n;

    int arr[n];

    cout << "Enter book IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    set<int> printed;

    cout << "Duplicate Book IDs: ";

    for (int i = 0; i < n; i++)
    {
        if (printed.find(arr[i]) != printed.end())
            continue;

        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > 1)
        {
            cout << arr[i] << " ";
            printed.insert(arr[i]);
        }
    }

    return 0;
}
