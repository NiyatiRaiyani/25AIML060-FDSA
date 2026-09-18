/*
Instructors have given one problem to students. Students have to solve and implement the program in maximum 60 minutes. After contest, Instructor has the submission time (in minutes) in which every student has submitted the correct solution.

Help the instructor to find the top 2 students who have submitted correct problem fastest.

Input for this program is roll number, roll_no and time to submit the solution in minutes, submissiontime for n students.

Explanation:

Input will be: n=5 (number of students)

roll_no: 1,4,5,7,10

submissiontime= 34,60,42,35,21

1 (for Bubble Sort)

2 (for Selection Sort)

Output can be:

case 1: Bubble Sort :

21,34,35,42,60

No of swaps : 7

case 2: Selection Sort :

21,34,35,42,60

No of swaps : 3

Top 2 students : roll no : 10 and 1

Input Format

First line contains the integer, the number of students n
next lines have two integers , roll_no and submission time for n students.
Third Line is interger, either 1. for bubble sort or 2 for selection sort
Constraints

1 < n < 50
1 < roll_no < 190 ; 1 < submission time < 60
Output Format

First line is sorted data according to time.
next line of output shows the number of comparisons required to sort data.
next line is number of swaps required to sort data.
Next line is top two performers' roll numbers.
Sample Input 0

6
6 35
7 30
5 20
10 25
12 40
1 22
1
Sample Output 0

5 20
1 22
10 25
7 30
6 35
12 40
9
5,1
Sample Input 1

6
6 35
7 30
5 20
10 25
12 40
1 22
2
Sample Output 1

5 20
1 22
10 25
7 30
6 35
12 40
5
5,1
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int roll[], int time[], int n, int &swaps)
{
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (time[j] > time[j + 1])
            {
                int temp = time[j];
                time[j] = time[j + 1];
                time[j + 1] = temp;

                temp = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = temp;

                swaps++;
            }
        }
    }
}

void selectionSort(int roll[], int time[], int n, int &swaps)
{
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (time[j] < time[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = time[i];
            time[i] = time[min];
            time[min] = temp;

            temp = roll[i];
            roll[i] = roll[min];
            roll[min] = temp;

            swaps++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int roll[50], time[50];

    for (int i = 0; i < n; i++)
    {
        cin >> roll[i] >> time[i];
    }

    int choice;
    cin >> choice;

    int swaps;

    if (choice == 1)
    {
        bubbleSort(roll, time, n, swaps);
    }
    else
    {
        selectionSort(roll, time, n, swaps);
    }

    // Print sorted students
    for (int i = 0; i < n; i++)
    {
        cout << roll[i] << " " << time[i] << endl;
    }

    // Print number of swaps
    cout << swaps << endl;

    // Top 2 fastest students
    cout << roll[0] << "," << roll[1] << endl;

    return 0;
}