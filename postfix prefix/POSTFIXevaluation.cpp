#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

// Stack implementation using an array
class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
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

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    Stack s;
    int num1, num2, result;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If the character is a space, skip it
        if (c == ' ')
            continue;

        // If the character is an operand, push it to the stack
        if (isdigit(c)) {
            int num = c - '0';
            s.push(num);
        }

        // If the character is an operator, pop two operands from the stack and perform the operation
        else {
            num2 = s.pop();
            num1 = s.pop();

            switch (c) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                case '^':
                    result = pow(num1,num2);
                    break;
            }

            s.push(result);
        }
    }

    // The final result is the only element left in the stack
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}