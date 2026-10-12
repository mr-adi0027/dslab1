#include <iostream>
using namespace std;

#define MAX 100 // 1. Added missing MAX definition

class ArrayStack {
    int arr[MAX];
    int top = -1;

public: // 2. Added public access specifier so functions can be called externally
    bool isEmpty() {
        return top == -1; // 3. Fixed '=' to '=='
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Overflow";
            return;
        }
        arr[++top] = x; // 4. Fixed '()' to '[]'
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow";
            return -1;
        }
        return arr[top--]; // 4. Fixed '()' to '[]'
    }
}; // 5. Added missing semicolon at the end of the class
