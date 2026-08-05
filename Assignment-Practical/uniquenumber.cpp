#include <iostream>
using namespace std;

int main() {
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