/*#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


int main() {
    int N;
    cin >> N;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= N; i++) {
        string binary = q.front();
        q.pop();
        cout << binary;

        if (i < N)
            cout << " ";

        q.push(binary + "0");
        q.push(binary + "1");
    }
}
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


int main() {
    int N;
    cin >> N;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= N; i++) {
        string binary = q.front();
        q.pop();
        cout << binary;

        if (i < N)
            cout << " ";

        q.push(binary + "0");
        q.push(binary + "1");
    }
}
