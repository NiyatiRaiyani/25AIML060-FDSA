#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    string brackets;
    stack<char> s;

    cout << "Enter bracket sequence: ";
    cin >> brackets;

    for (char ch : brackets) {

        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }

        else if (ch == ')' || ch == ']' || ch == '}') {

            if (s.empty()) {
                cout << "No";
                return 0;
            }

            char top = s.top();
            s.pop();

            if (!isMatching(top, ch)) {
                cout << "No";
                return 0;
            }
        }
    }

    if (s.empty())
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
