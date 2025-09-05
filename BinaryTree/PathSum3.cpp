#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//brute force - O(N^2)
int dfs_from(TreeNode* root, long long currSum, int targetSum) {
        if (!root) return 0;
        
        currSum += root->val;
        int count = (currSum == targetSum) ? 1 : 0;
        
        count += dfs_from(root->left, currSum, targetSum);
        count += dfs_from(root->right, currSum, targetSum);
        
        return count;
}
    
int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        // count paths starting at this root
        int ans = dfs_from(root, 0, targetSum);
        
        // also try starting at left and right children
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        
        return ans;
}

//optimal approach - TC = O(N) , Prefix sum +  hashmap
    int dfs(TreeNode* root, long long currSum, int targetSum, unordered_map<long long,int>& prefix) {
        if (!root) return 0;
        
        currSum += root->val;
        
        // Count paths that end at this node
        int count = 0;
        if (prefix.find(currSum - targetSum)!=prefix.end()) {
            count += prefix[currSum - targetSum];
        }
        
        // Add current prefix sum to the map
        prefix[currSum]++;
        
        // Recurse to children
        count += dfs(root->left, currSum, targetSum, prefix);
        count += dfs(root->right, currSum, targetSum, prefix);
        
        // Backtrack: remove current prefix sum
        prefix[currSum]--;
        
        return count;
    }
    
int pathSum3(TreeNode* root, int targetSum) {
    unordered_map<long long,int> prefix;
    prefix[0] = 1;  // base case
    return dfs(root, 0, targetSum, prefix);
}

int main() {
    /*
        Example tree:
                10
               /  \
              5   -3
             / \     \
            3   2     11
           / \   \
          3  -2   1

        targetSum = 8
        Expected output = 3
        (paths: [5,3], [5,2,1], [-3,11])
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;
    cout << "Number of paths: " << pathSum3(root, targetSum) << endl;

    return 0;
}