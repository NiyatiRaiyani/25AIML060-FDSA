/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Example:

Input: s = "()"
Output: true
C code

#include <stdio.h>

#define MAX_SIZE 100  // Define a constant for the maximum stack size

// Define the Stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push a value onto the stack
void push(Stack* stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++stack->top] = value;
    } else {
        printf("Stack overflow\n");  // Optional: handle overflow
    }
}

// Pop a value from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1;  // Return -1 if the stack is empty
}

// Peek the top value of the stack
int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    }
    return -1;  // Return -1 if the stack is empty
}
cpp code

class Stack {
    int arr[MAX_SIZE];
    int top;
    
public:
    Stack() : top(-1) {}
    
    bool isEmpty() {
        return top == -1;
    }
    
    void push(int value) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = value;
        }
    }
    
    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1; // Return -1 if the stack is empty
    }
    
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return -1; // Return -1 if the stack is empty
    }
};
java code

class Stack {
    private int[] arr;
    private int top;
    private int maxSize;

    // Constructor to initialize the stack
    public Stack(int size) {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Push an element onto the stack
    public void push(int value) {
        if (top < maxSize - 1) {
            arr[++top] = value;
        }
    }

    // Pop an element from the stack
    public int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1; // Return -1 if the stack is empty
    }

    // Peek the top element of the stack
    public int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return -1; // Return -1 if the stack is empty
    }
}
python code

class Stack:
    def __init__(self):
        self.stack = []
    
    def is_empty(self):
        return len(self.stack) == 0
    
    def push(self, value):
        self.stack.append(value)
    
    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        return None
    
    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        return None
Input Format

Input contain the string of parentheses
Constraints

0 < S <=20
Output Format

Output contain the Boolean value.
Sample Input 0

[[[)))
Sample Output 0

false
Sample Input 1

{{{{{{}}}}}}
Sample Output 1

true
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#define MAX_SIZE 100
using namespace std;

class Stack
{
    char arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(char value)
    {
        if (top < MAX_SIZE - 1)
        {
            arr[++top] = value;
        }
    }

    char pop()
    {
        if (!isEmpty())
        {
            return arr[top--];
        }

        return '\0';
    }

    char peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }

        return '\0';
    }
};

bool isValid(string s)
{
    Stack st;

    for (char ch : s)
    {
        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }

        // Closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.isEmpty())
            {
                return false;
            }

            char top = st.peek();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }

            st.pop();
        }
    }

    return st.isEmpty();
}

int main() {
    string s;
    cin >> s;

    if (isValid(s))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}
