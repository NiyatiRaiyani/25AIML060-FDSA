/*
You are required to implement a stack data structure using an array. A stack is a data structure that follows the Last In First Out (LIFO) principle. Your implementation should support the following operations:

the switch case should have following operations.

push(x): Pushes element x onto the stack.
pop(): Removes and returns the top element of the stack. If the stack is empty, return -1.
peek(): Returns the top element of the stack without removing it. If the stack is empty, return -1.
isEmpty(): Returns 1 if the stack is empty, otherwise returns 0.
Input Format

The first line contains an integer n denoting the number of operations.
Each of the next n lines contains an operation to be performed on the stack.
Constraints

-

Output Format

For each pop() or peek() operation, output the result on a new line.
For each isEmpty() operation, output the result on a new line.
Sample Input 0

10
1 5
1 10
3
2
2
4
2
1 15
3
4
Sample Output 0

10
10
5
1
-1
15
0
Explanation 0

1 5: Push 5 onto the stack. Stack is now [5].
1 10: Push 10 onto the stack. Stack is now [5, 10].
3: Peek the top element, which is 10. Output: 10.
2: Pop the top element, which is 10. Stack is now [5]. Output: 10.
2: Pop the top element, which is 5. Stack is now []. Output: 5.
4: Check if the stack is empty. It is empty, so return 1. Output: 1.
2: Attempt to pop an element from the empty stack. Return -1. Output: -1.
1 15: Push 15 onto the stack. Stack is now [15].
3: Peek the top element, which is 15. Output: 15.
4: Check if the stack is empty. It is not empty, so return 0. Output: 0.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX-1)
        return;
    else
    {
        stack[++top]=value;
    }
}

void pop()
{
    if(top == -1)
        cout << -1 << endl;
    else
    {
        cout << stack[top] << endl;
        top--;
    }
}

void peek()
{
    if (top == -1)
        cout << -1 << endl;
    else
        cout << stack[top] << endl;
}

void isEmpty()
{
    if (top == -1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int x;
                cin >> x;
                push(x);
                break;
            }

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                isEmpty();
                break;
        }
    }
    return 0;
}