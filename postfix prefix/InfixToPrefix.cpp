#include <iostream>
#include <string>
#include <cctype>

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

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    Stack s;
    string prefix = "";

    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        // If the character is a space, skip it
        if (c == ' ')
            continue;

        // If the character is an operand, add it to the prefix string
        if (isalnum(c))
            prefix = c + prefix;

        // If the character is a ')', push it to the stack
        else if (c == ')')
            s.push(c);
 
        // If the character is a '(', pop from the stack and add to prefix string
        else if (c == '(') {
            while (!s.isEmpty() && s.getTop() != ')') {
                prefix = s.pop() + prefix;
            }
            if (!s.isEmpty() && s.getTop() == ')')  //to remove '('
                s.pop();
        }

        // If the character is an operator, pop from the stack and add to prefix string
        else {
            while (!s.isEmpty() && s.getTop() != ')' && getPrecedence(c) < getPrecedence(s.getTop())) {
                prefix = s.pop() + prefix;
            }
            s.push(c);
        }
    }

    // Pop any remaining operators from the stack and add to prefix string
    while (!s.isEmpty()) {
        prefix = s.pop() + prefix;
    }

    return prefix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}