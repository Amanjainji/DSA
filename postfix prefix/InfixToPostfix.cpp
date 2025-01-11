#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

// Function to get precedence of operators
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Stack implementation using an array
class Stack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }

    // Push an element onto the stack
    void push(char c) {
        if (top < MAX_SIZE - 1)
            arr[++top] = c;
    }

    // Pop an element from the stack
    char pop() {
        if (top >= 0)
            return arr[top--];
        return '\0';
    }

    // Check if the stack is empty
    bool isEmpty() { return top == -1; }

    // Get the top element of the stack
    char getTop() { return arr[top]; }
};

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the character is a space, skip it
        if (c == ' ')
            continue;

        // If the character is an operand, add it to the postfix string
        if (isalnum(c))
            postfix += c;

        else if (c == '(')
            s.push(c);

        else if (c == ')') {
            while (!s.isEmpty() && s.getTop() != '(') {
                postfix += s.pop();
            }
            if (!s.isEmpty() && s.getTop() == '(')  // to remove '('
                s.pop();
        }

        // If the character is an operator, pop from the stack and add to postfix string
        else {
            while (!s.isEmpty() && s.getTop() != '(' && getPrecedence(c) <= getPrecedence(s.getTop())) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    // Pop any remaining operators from the stack and add to postfix string
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}