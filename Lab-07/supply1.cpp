#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    queue<string> q;

    q.push("1");

    cout << "Binary numbers from 1 to " << n << ":" << endl;

    for(int i = 1; i <= n; i++)
    {
        string current = q.front();
        q.pop();

        cout << current << " ";

        q.push(current + "0");
        q.push(current + "1");
    }

    return 0;
}
