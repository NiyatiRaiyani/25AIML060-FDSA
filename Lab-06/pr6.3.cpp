#include <iostream>
#include <stack>
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

bool isOperand(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9'))
    {
        return true;
    }

    return false;
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (isOperand(ch))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            s.push(ch);
        }

        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        else
        {
            while (!s.empty() &&
                   s.top() != '(' &&
                   precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}
