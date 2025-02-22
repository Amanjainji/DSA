#include<bits/stdc++.h>
using namespace std;
//leetcode #1028

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* recoverFromPreorder(string traversal) {
    stack<pair<TreeNode*, int>> st; // Stack stores {TreeNode*, depth}
    int index = 0, n = traversal.size();
    
    while (index < n) {
        // Count depth (number of dashes)
        int depth = 0;
        while (index < n && traversal[index] == '-') {
            depth++;
            index++;
        }

        // Read the node value (multi-digit support)
        int value = 0;
        while (index < n && isdigit(traversal[index])) {
            value = value * 10 + (traversal[index] - '0');
            index++;
        }

        // Create a new TreeNode
        TreeNode* node = new TreeNode(value);

        // Find parent in stack (last node with depth - 1)
        while (!st.empty() && st.top().second >= depth) {
            st.pop();
        }

        // Attach node to its parent
        if (!st.empty()) {
            TreeNode* parent = st.top().first;
            if (!parent->left) {
                parent->left = node;
            } else {
                parent->right = node;
            }
        }

        // Push new node onto stack
        st.push({node, depth});
    }

    // The root node is at the bottom of the stack
    while (st.size() > 1) {
        st.pop();
    }
    return st.top().first;
}