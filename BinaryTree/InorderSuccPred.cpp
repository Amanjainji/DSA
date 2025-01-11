#include <bits/stdc++.h>
using namespace std;

// Definition of a tree node
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to find the inorder predecessor
Node* findPredecessor(Node* node) {
    Node* current = node->left;
    while (current && current->right) {
        current = current->right;
    }
    return current;
}

// Function to find the inorder successor
Node* findSuccessor(Node* node) {
    Node* current = node->right;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

// Function to find predecessor and successor in BST
void findPredecessorSuccessor(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;

    if (root->data == key) {
        // Find the predecessor (rightmost in left subtree)
        if (root->left)
            pre = findPredecessor(root);

        // Find the successor (leftmost in right subtree)
        if (root->right)
            suc = findSuccessor(root);
        return;
    }

    // If key is smaller, traverse the left subtree
    if (key < root->data) {
        suc = root;  // Current root could be the successor
        findPredecessorSuccessor(root->left, pre, suc, key);
    }
    // If key is larger, traverse the right subtree
    else {
        pre = root;  // Current root could be the predecessor
        findPredecessorSuccessor(root->right, pre, suc, key);
    }
}


// Example usage
int main() {
    // Construct a sample BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);
    string s="";
    s=s+"A";
    cout<<s;
    int key = 15;
    Node* pre = NULL;
    Node* suc = NULL;
    findPredecessorSuccessor(root, pre, suc, key);
    //cout << "Inorder Predecessor of " << key << " is " << pre->data << endl;
    //cout << "Inorder Successor of " << key << " is " << suc->data << endl;
    return 0;
}
