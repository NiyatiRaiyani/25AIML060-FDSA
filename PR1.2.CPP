#include <iostream>
#include<set>
using namespace std;

int main()
{
    int n;

    cout << "Enter Number of records: ";
    cin >> n;

    int book[100];

    cout << "Enter Book IDs:\n";
    for (int i = 0; i < n; i++)

    {
        cin >> book[i];
    }

    cout << "Duplicate Book IDs:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = i++ ; j < n; j++)
        {
            if (book[i] == book[j])
            {
                cout << book[i] << " ";
                break;
                int set = book[j];
            }

        }
    }
    return 0;
}
