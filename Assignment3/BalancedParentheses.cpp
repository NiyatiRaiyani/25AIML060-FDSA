/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order. Every close bracket has a corresponding open bracket of the same type

Input Format

Input A single string s containing the characters mentioned in the problem.

Constraints

1 <= s.length <= 1000 s consists of parentheses only '()[]{}'.

Output Format

For each test case, print whether the parentheses are balanced or not.

Sample Input 0

(
Sample Output 0

Not Balanced
Sample Input 1

({})
Sample Output 1

Balanced*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main() {
        string s;
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                cout << "Not Balanced";
                return 0;
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    if (st.empty())
        cout << "Balanced";
    else
        cout << "Not Balanced";   
    return 0;
}
