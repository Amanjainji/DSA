#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

// Stack implementation using an array
class Stack {
    public:
    int arr[MAX_SIZE];
    int top;

    Stack() { top = -1; }

    // Push an element onto the stack
    void push(int num) {
        if (top < MAX_SIZE - 1)
            arr[++top] = num;
    }

    // Pop an element from the stack
    int pop() {
        if (top >= 0)
            return arr[top--];
        return 0;
    }

    // Check if the stack is empty
    bool isEmpty() { return top == -1; }

    // Get the top element of the stack
    int getTop() { return arr[top]; }
};

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, Stack& source, Stack& auxiliary, Stack& destination) {
    if (n == 1) {
        // Move the only disk from source to destination
        int disk = source.pop();
        destination.push(disk);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination
    int disk = source.pop();
    destination.push(disk);

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n=3;  
    Stack source, auxiliary, destination;

    // Initialize the source stack with disks
    for (int i = n; i >= 1; i--) {
        source.push(i);
    }

    cout << "Initial configuration:" << endl;
    cout << "Source: ";
    for (int i = n-1; i >=0; i--) {
        cout << source.arr[i] << " ";
    }
    cout << endl;

    towerOfHanoi(n, source, auxiliary, destination);

    cout << "Final configuration:" << endl;
    cout << "Destination: ";
    for (int i = n-1; i >=0; i--)  {
        cout << destination.arr[i] << " ";
    }
    cout << endl;

    return 0;
}