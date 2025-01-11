#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> q1; // Primary queue
    std::queue<int> q2; // Secondary queue

public:
    // Push element onto the stack
    void push(int x) {
        // Push the new element into the empty queue (q2)
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2
        std::swap(q1, q2);
    }

    // Pop element from the stack
    int pop() {
        if (q1.empty()) {
            throw std::underflow_error("Stack is empty!");
        }
        int top = q1.front();
        q1.pop();
        return top;
    }

    // Get the top element of the stack
    int top() {
        if (q1.empty()) {
            throw std::underflow_error("Stack is empty!");
        }
        return q1.front();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "Top: " << s.top() << std::endl; // Output: 3
    std::cout << "Pop: " << s.pop() << std::endl;  // Output: 3
    std::cout << "Top: " << s.top() << std::endl;  // Output: 2
    std::cout << "Pop: " << s.pop() << std::endl;  // Output: 2
    std::cout << "Pop: " << s.pop() << std::endl;  // Output: 1

    if (s.isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
    }

    return 0;
}



/*
#include <iostream>
#include <stack>
using namespace std;


void pushAtBottom(int x){
    stack<int> s;

    if(s.empty()){
        s.push(x);
        return;
    }

    int temp=s.top();
    s.pop();

    pushAtBottom(x);

    s.push(temp);
}
*/
/*
class QueueUsingStack {
private:
    std::stack<int> s;

public:
    // Enqueue function
    void enqueue(int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }
        
        // Pop the top element
        int temp = s.top();
        s.pop();
        
        // Recursively call the function
        enqueue(x);
        
        // Push the popped element back
        s.push(temp);
    }

    // Dequeue function
    int dequeue() {
        if (s.empty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1; // Indicate that the queue is empty
        }
        
        // Pop the top element, which is the front of the queue
        int front = s.top();
        s.pop();
        return front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s.empty();
    }

    // Function to get the front element of the queue
    int front() {
        if (s.empty()) {
            std::cerr << "Queue is empty!" << std::endl;
            return -1; // Indicate that the queue is empty
        }
        return s.top();
    }
};

int main() {
    QueueUsingStack q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Dequeue: " << q.dequeue() << std::endl; // Output: 1
    std::cout << "Dequeue: " << q.dequeue() << std::endl; // Output: 2

    q.enqueue(4);
    
    std::cout << "Front: " << q.front() << std::endl; // Output: 3
    std::cout << "Dequeue: " << q.dequeue() << std::endl; // Output: 3
    std::cout << "Dequeue: " << q.dequeue() << std::endl; // Output: 4

    if (q.isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
    }

    return 0;
}
*/