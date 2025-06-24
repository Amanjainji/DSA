#include <iostream>

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to convert binary tree to doubly linked list
Node* bToDLL(Node* root) {
    // Initialization
    Node* curr = root;
    Node* prev = nullptr; // Used to keep track of prev node
    Node* final_head = nullptr; // Used to return the final head

    // Traverse the tree
    while (curr) {
        // If no left child
        if (!curr->left) {
            // If final_head is not set, set it to current node
            if (!final_head) {
                prev = curr;
                final_head = curr;
            } else {
                // Set next of prev as curr and prev of curr as prev
                prev->right = curr;
                curr->left = prev;
            }
            // Set the new prev node
            prev = curr;
            curr = curr->right;
        } else {
            // If left child exists
            Node* pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = curr;
                curr = curr->left;
            } else {
                curr = pre->right;
                // Set next of prev as curr and prev of curr as prev
                prev->right = curr;
                curr->left = prev;
                // Set the new prev node
                prev = curr;
                curr = curr->right;
            }
        }
    }

    return final_head; // Return the final head of the linked list
}

// Function to print nodes in the doubly linked list
void print_dll(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->right;
    }
}

// Driver code
int main() {
    // Create the binary tree
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    // Convert the binary tree to doubly linked list
    Node* head = bToDLL(root);

    // Print the converted list
    print_dll(head);

    return 0;
}