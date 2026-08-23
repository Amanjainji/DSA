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

class Solution {
public:

    // state:
    // 0 -> camera placed at node
    // 1 -> node is covered, no camera
    // 2 -> node is not covered
    unordered_map<TreeNode*, vector<int>> dp;

    int solve(TreeNode* node, int state) {
        // Null node
        if (node == nullptr) {
            // A null node cannot have a camera.
            // Treating it as covered is useful.
            if (state == 0) return 1e9;
            return 0;
        }

        if (!dp.count(node))
            dp[node] = vector<int>(3, -1);

        if (dp[node][state] != -1)
            return dp[node][state];

        int ans = 1e9;

        // -------------------------
        // State 0: Camera at node
        // -------------------------
        if (state == 0) {

            ans = 1
                + min({
                    solve(node->left, 0),
                    solve(node->left, 1),
                    solve(node->left, 2)
                  })
                + min({
                    solve(node->right, 0),
                    solve(node->right, 1),
                    solve(node->right, 2)
                  });
        }

        // -------------------------
        // State 1: Node is covered
        // but doesn't have camera
        // -------------------------
        else if (state == 1) {

            // At least one child must have camera

            ans = min(
                solve(node->left, 0) +
                min(solve(node->right, 0),
                    solve(node->right, 1)),

                solve(node->right, 0) +
                min(solve(node->left, 0),
                    solve(node->left, 1))
            );
        }

        // -------------------------
        // State 2: Node is NOT covered
        // -------------------------
        else {

            // Neither child can have camera.
            // Both children must be covered.
            ans = solve(node->left, 1)
                + solve(node->right, 1);
        }

        return dp[node][state] = ans;
    }

    int minCameraCover(TreeNode* root) {

        if (root == nullptr)
            return 0;

        // Root cannot be left uncovered.
        // It either has a camera or is covered.
        return min(
            solve(root, 0),
            solve(root, 1)
        );
    }
};

class Solution2 : public Solution {
public: 
    
    // 0 means Not Covered 
    // 1 means has camera 
    // 2 means covered 

    int totalCameras = 0;  

    int minCameras(TreeNode* root){
        if(!root)return 2; 

        int left = minCameras(root->left); 
        int right = minCameras(root->right); 

        if(left==0 || right==0){
            totalCameras++; 
            return 1;
        } 

        if(left==1 || right==1){
            return 2; 
        } 

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if(minCameras(root)==0)totalCameras++; 
        return totalCameras; 
    }
};

int main(){
    return 0;
}