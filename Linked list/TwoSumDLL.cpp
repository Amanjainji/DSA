#include <iostream>
#include <vector>
using namespace std;

// Doubly Linked List Node
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Insert node at the end of the list
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Utility to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Find tail of DLL
Node* findTail(Node* head) {
    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;
    return tail;
}

// Find pairs with given sum in DLL
vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> ans;

    if (head == nullptr) return ans;

    Node* left = head;
    Node* right = findTail(head); // O(N)

    while (left && right && left->data < right->data) {
        int sum = left->data + right->data;
        if (sum == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if (sum < k) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }

    return ans;
}

// Driver Code
int main() {
    Node* head = nullptr;

    // Create doubly linked list
    vector<int> values = {1, 2, 3, 4, 5, 6, 8, 9};
    for (int val : values) {
        insertEnd(head, val);
    }

    cout << "Doubly Linked List: ";
    printList(head);

    int k = 10;
    vector<pair<int, int>> result = findPairs(head, k);

    cout << "Pairs with sum " << k << ":\n";
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
