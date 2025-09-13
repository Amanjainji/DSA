#include<bits/stdc++.h>
using namespace std;

/*
In a Binary Search Tree (BST), inorder traversal produces a sorted sequence.
If two nodes are swapped by mistake, the inorder traversal will show a violation of the increasing order.
We can detect these two nodes during inorder traversal and swap their values back to fix the BST.
*/

//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }

    void helper(TreeNode* node) {
        if (!node) return;

        helper(node->left);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }

        prev = node;

        helper(node->right);
    }
};

void inorderBST(TreeNode* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorderBST(root->left,ans);
    ans.push_back(root->val);
    inorderBST(root->right,ans);
}

int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->right=new TreeNode(4);
    root->right->left=new TreeNode(2);
    vector<int> inorder;
    inorderBST(root,inorder);
    for(auto i: inorder) cout<<i<<" ";
    cout<<endl;
    Solution s;
    s.recoverTree(root);
    vector<int> inorder2;
    inorderBST(root,inorder2);
    for(auto i: inorder2) cout<<i<<" ";
    cout<<endl;
}