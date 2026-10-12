#include <iostream>
using namespace std;

#define MAX 100 

class ArrayStack {
    int arr[MAX];
    int top = -1;

public: 
    bool isEmpty() {
        return top == -1; 
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        arr[++top] = x; 
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1;
        }
        return arr[top--]; 
    }
}; 

// ADDED: The main function is required for the program to run
int main() {
    ArrayStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Popped element: " << stack.pop() << endl; // Should print 30
    cout << "Popped element: " << stack.pop() << endl; // Should print 20

    return 0;
}
