#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    string item[100];

    cout << "Enter items:\n";
    for(int i=0;i<n;i++)
    {
        cin>>item[i];
    }

    cout<<"Enter hours: ";
    cin>>h;

    h = h % n;

    cout<<"Final Display Order:\n";

    for(int i=0;i<n;i++)
    {
        cout<<item[(i+h)%n]<<" ";
    }

    return 0;
}
