#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    //make parent map
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current->left){
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent[current->right] = current;
                q.push(current->right);
            } 
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markParent(root, parent, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        //explore all distance till k using bfs on target node 
        while(!q.empty()){
            int size = q.size();
            if(curr_level == k)  break;
            curr_level++;

            for(int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();

                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent[current] && !visited[parent[current]]){
                    q.push(parent[current]);
                    visited[parent[current]] = true;
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};

int main(){

}