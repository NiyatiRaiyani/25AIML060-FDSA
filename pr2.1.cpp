#include <iostream>
using namespace std;

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target element: ";
    cin >> target;

    int first = -1, last = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            if(first == -1)
                first = i;   // Store first occurrence

            last = i;        // Keep updating last occurrence
        }
    }

    if(first == -1)
    {
        cout << "Element not found.";
    }
    else
    {
        cout << "First Occurrence: " << first + 1 << endl;
        cout << "Last Occurrence: " << last + 1 << endl;
    }

    return 0;
}
