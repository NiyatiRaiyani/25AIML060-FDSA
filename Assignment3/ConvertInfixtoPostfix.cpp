/*Convert infix expression to postfix expression. Include '+', '-', '*', '/' and '^' operators and parenthesis.

Input Format

Input line contains the infix expression with characters, digits and operators.

Constraints

-

Output Format

Output line contains the postfix expression.

Sample Input 0

(a+b)
Sample Output 0

ab+
Sample Input 1

(a+b)*c*d
Sample Output 1

ab+c*d*
Sample Input 2

a+b*c
Sample Output 2

abc*+
Sample Input 3

a+b^c^d^e
Sample Output 3

abcde^^^+
Sample Input 4

a+b-c/d-
Sample Output 4

Invalid expression
Sample Input 5

a+b-c--
Sample Output 5

Invalid Expression*/
/* Omark
#include <cmath>

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) 
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main() {
    string infix, postfix = "";
    cin >> infix;

    stack<char> s;
    bool expectOperand = true;
    int balance = 0;

    for (int i = 0; i < (int)infix.length(); i++) {
        char c = infix[i];

        if (isalnum((unsigned char)c)) 
        {
            if (!expectOperand) {
                cout << "Invalid Expression";
                return 0;
            }

            postfix += c;
            expectOperand = false;
        }
        else if (c == '(') {
            if (!expectOperand) {
                cout << "Invalid Expression";
                return 0;
            }

            s.push(c);
            balance++;
        }
        else if (c == ')') 
        {
            if (expectOperand || balance == 0) 
            {
                cout << "Invalid Expression";
                return 0;
            }

            while (!s.empty() && s.top() != '(') 
            {
                postfix += s.top();
                s.pop();
            }

            s.pop();
            balance--;
            expectOperand = false;
        }
        else if (isOperator(c)) 
        {
            if (expectOperand) 
            {
                cout << "Invalid Expression";
                return 0;
            }

            while (!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(c) ||
                   (precedence(s.top()) == precedence(c) &&
                    c != '^'))) 
            {
                postfix += s.top();
                s.pop();
            }

            s.push(c);
            expectOperand = true;
        }
        else 
        {
            cout << "Invalid Expression";
            return 0;
        }
    }

    if (expectOperand || balance != 0) 
    {
        cout << "Invalid Expression";
        return 0;
    }

    while (!s.empty()) {
        if (s.top() == '(') {
            cout << "Invalid Expression";
            return 0;
        }

        postfix += s.top();
        s.pop();
    }

    cout << postfix << endl; 
    return 0;
}
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char c) 
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main() {
    string infix, postfix = "";
    cin >> infix;

    stack<char> st;
    bool needOperand = true;
    int balance = 0;

    for (char c : infix) {
        if (isalnum((unsigned char)c)) {
            if (!needOperand) {
                cout << "Invalid Expression";
                return 0;
            }
            postfix += c;
            needOperand = false;
        }
        else if (c == '(') {
            if (!needOperand) {
                cout << "Invalid Expression";
                return 0;
            }
            st.push(c);
            balance++;
        }
        else if (c == ')') {
            if (needOperand || balance == 0) {
                cout << "Invalid Expression";
                return 0;
            }

            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            st.pop();
            balance--;
            needOperand = false;
        }
        else if (isOperator(c)) {
            if (needOperand) {
                cout << "Invalid Expression";
                return 0;
            }

            while (!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(c) ||
                  (precedence(st.top()) == precedence(c) && c != '^'))) {
                postfix += st.top();
                st.pop();
            }

            st.push(c);
            needOperand = true;
        }
        else {
            cout << "Invalid Expression";
            return 0;
        }
    }

    if (needOperand || balance != 0) {
        cout << "Invalid Expression";
        return 0;
    }

    while (!st.empty()) {
        if (st.top() == '(') {
            cout << "Invalid Expression";
            return 0;
        }
        postfix += st.top();
        st.pop();
    }

    cout << postfix;

    return 0;
}
