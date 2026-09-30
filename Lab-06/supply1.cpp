#include <iostream>
#include <stack>
using namespace std;

int main() {
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (char ch : postfix) {

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

            if (s.size() < 2) {
                cout << "Error: Invalid postfix expression";
                return 0;
            }

            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            if (ch == '+')
                result = a + b;
            else if (ch == '-')
                result = a - b;
            else if (ch == '*')
                result = a * b;
            else
                result = a / b;

            s.push(result);
        }
        else {
            cout << "Error: Invalid character";
            return 0;
        }
    }

    if (s.size() != 1) {
        cout << "Error: Invalid postfix expression";
    }
    else {
        cout << "Result: " << s.top();
    }

    return 0;
}
