#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter total classrooms: ";
    cin >> n;

    int arr[n - 1];
    int sum = 0;

    cout << "Enter classroom numbers:\n";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int expected = n * (n + 1) / 2;
    int missing = expected - sum;

    cout << "Missing classroom number = " << missing;

    return 0;
}
