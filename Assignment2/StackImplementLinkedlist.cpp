/*
You are required to implement a stack data structure using an linkedlist. A stack is a data structure that follows the Last In First Out (LIFO) principle. Your implementation should support the following operations:

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

7
1 10
1 20
1 30
2
2
2
2
Sample Output 0

30
20
10
-1
Explanation 0

-1 for underflow

same for the case of overflow

Sample Input 1

12
1 100
1 200
1 300
3
2
3
1 400
4
2
3
2
4
Sample Output 1

300
300
200
0
400
200
200
0
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = top;
    top = newNode;

}

void pop()
{
    if (top == NULL)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << top->data << endl;

        Node* temp = top;
        top = top->next;

        delete temp;
    }
}

void peek()
{
    if (top == NULL)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << top->data << endl;
    }
}

void isEmpty()
{
    if (top == NULL)
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
