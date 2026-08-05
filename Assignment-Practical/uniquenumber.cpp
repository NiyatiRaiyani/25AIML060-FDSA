/* Write a program to find non repeating element in an array (Unique element)

Input : The number of elements, and an array.

Output: Return non repeating number

Input Format

-- first line contains N no. of array elements --Second line contains N elements separated by space

Constraints

-

Output Format

-- print unique number

Sample Input 0

5
1 2 3 2 1
Sample Output 0

3
Sample Input 1

6
1 2 3 4 1 5
Sample Output 1

2 3 4 5*/

#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    int arr[n];
    int freq[100001] = {0};

    // Input and count frequency
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    // Print non-repeating elements
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == 1) {
            cout << arr[i] << " ";
            found = true;
        }
    }

    if (!found)
        cout << -1;

    return 0;
}