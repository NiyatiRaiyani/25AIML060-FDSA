/*
Given a circularly sorted integer array, find the total number of times the array is rotated. Assume there are no duplicates in the array, and the rotation is in the anti-clockwise direction.

Input Format

nums = [8, 9, 10, 2, 5, 6] nums = [2, 5, 6, 8, 9, 10]

Constraints

0< n <=50

Output Format

The array is rotated 3 times The array is rotated 0 times

Sample Input 0

[8, 9, 10, 2, 5, 6]
Sample Output 0

The array is rotated 3 times*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<int> a;
    int num = 0;
    bool reading = false;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            reading = true;
        } 
        else if (reading) {
            a.push_back(num);
            num = 0;
            reading = false;
        }
    }

    if (reading) {
        a.push_back(num);
    }

    int rotations = 0;

    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1]) {
            rotations = i;
            break;
        }
    }

    cout << "The array is rotated " << rotations << " times";
 
    return 0;
}
