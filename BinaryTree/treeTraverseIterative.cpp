#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderIterative(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != NULL || !st.empty()) {
        // 1. Go left as far as possible
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        // 2. Visit node
        curr = st.top();
        st.pop();
        cout << curr->val << " ";

        // 3. Move right
        curr = curr->right;
    }
}

struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//postorder using two stacks
vector<int> postOrder(Node* root) {
    vector<int> postorder;
    if(root == NULL){
        return postorder;
    }

    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if(root->left != NULL){
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if(root->right != NULL){
            st1.push(root->right);
        }
    }
    // vector by popping st2
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}

//using 1 stack
void preorderIterative(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        cout << node->val << " ";  // Visit the root

        if (node->right) st.push(node->right); // Push right first
        if (node->left) st.push(node->left);   // Push left second
    }
}

//using 1 stack
void postorderIterative(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st;
    TreeNode* lastVisited = NULL;
    TreeNode* curr = root;

    while (!st.empty() || curr) {
        if (curr) {
            st.push(curr);
            curr = curr->left;  // go left first
        }
        else {
            TreeNode* peekNode = st.top();
            if (peekNode->right && lastVisited != peekNode->right) {
                curr = peekNode->right;  // go right if not visited
            } else {
                cout << peekNode->val << " "; // visit root
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
}


int main() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder Traversal: ";
    //inorderIterative(root); // Output: 4 2 5 1 3
    preorderIterative(root);
}
