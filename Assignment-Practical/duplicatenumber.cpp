/* Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice otherwise print -1 for no duplicates.

Input Format

first line contains n
second line contains space separated n number of array elements
Constraints

1 <= n <= 10^5
1 <= a[i] <= n
Each element in nums appears once or twice.
Output Format

prints dupicates numbers
Sample Input 0

3
1 1 2
Sample Output 0

1
Sample Input 1

8
4 2 3 7 8 3 2 1
Sample Output 1

2 3
Sample Input 2

2
1 2
Sample Output 2

-1 */

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
