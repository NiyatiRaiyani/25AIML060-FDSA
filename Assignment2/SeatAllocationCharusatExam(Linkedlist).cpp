/*Charusat University is hosting an examination in its examination hall, and there are n students attending the exam. Each student has a unique identification number, and they need to be allocated seats in the examination hall. The university has decided to allocate seats in ascending order of the students' identification numbers.

Your task is to write a program that takes the identification numbers of the students, allocates seats based on their identification numbers, and counts the number of swaps and comparisons that occur during the sorting process.

While applying sorting technique, you have to make sure that you have to compare neighbour pairs and swap the numbers if necessary.

Input Format

An integer n (1 <= n <= 100) representing the number of students attending the examination.
A list of n unique identification numbers (positive integers).
Constraints

The identification numbers are guaranteed to be unique.
Output Format

An integer representing the number of comparisons made during the sorting process.
An integer representing the number of swaps that occurred during the sorting process.
An ordered list of the same n identification numbers, representing the order in which students should be seated in the Charusat examination hall.
Sample Input 0

5
99 23 45 12 77
Sample Output 0

10
6
12 23 45 77 99
Sample Input 1

5
1 2 3 4 5
Sample Output 1

4
0
1 2 3 4 5
Sample Input 2

4
4 3 2 1
Sample Output 2

6
6
1 2 3 4
Sample Input 3

3
7 3 89
Sample Output 3

3
1
3 7 89*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int id;
    Node* next;
};
void insert(Node*& head, int id)
{
    Node* newNode = new Node;
    newNode->id = id;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        insert(head, id);
    }

    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        Node* temp = head;
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (temp->id > temp->next->id)
            {
                int x = temp->id;
                temp->id = temp->next->id;
                temp->next->id = x;

                swaps++;
                swapped = true;
            }

            temp = temp->next;
        }
        if (swapped == false)
        {
            break;
        }
    }

    cout << comparisons << endl;

    cout << swaps << endl;

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->id << " ";
        temp = temp->next;
    }
    
    return 0;
}
