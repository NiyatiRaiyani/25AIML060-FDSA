#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
    int n;
    cin >> n;

    int arr[n];
    int freq[n + 1] = {0};

    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    bool found = false;

    for (int i = 1; i <= n; i++) 
    {
        if (freq[i] == 2) 
        {
            cout << i << " ";
            found = true;
        }
    }
    
    if(!found)
    {
        cout << -1;
    }
    return 0;
}
