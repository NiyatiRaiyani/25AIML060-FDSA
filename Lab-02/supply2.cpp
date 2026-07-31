#include <iostream>
using namespace std;

void searchElement(int arr[10][10], int r, int c, int target)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == target)
            {
                cout << "Target Found";
                return;
            }
        }
    }

    cout << "Target Not Found";
}

int main()
{
    int r, c, target;
    int arr[10][10];

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Enter target element: ";
    cin >> target;

    searchElement(arr, r, c, target);

    return 0;
}
