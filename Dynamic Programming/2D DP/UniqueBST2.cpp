#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//Leetcode question

vector<TreeNode*> allPossibleBSTs(int start,int end){
    //base case
    if(start>end)
        return {0};
    if(start==end)
        return {new TreeNode(start)};
    
    vector<TreeNode*> ans;
    for(int i=start;i<=end;i++){
        vector<TreeNode*> left=allPossibleBSTs(start,i-1);
        vector<TreeNode*> right=allPossibleBSTs(i+1,end);
        //for all possible tree permutation
        for(int j=0;j<left.size();j++){
            for(int k=0;k<right.size();k++){
                TreeNode* root=new TreeNode(i);
                root->left=left[j];
                root->right=right[k];
                ans.push_back(root);
            }
        }
    }
    return ans;
}
vector<TreeNode*> generateTrees(int n) {
    if(n==0)
        return {};
    return allPossibleBSTs(1,n);
}

//Memoization
map<pair<int,int>,vector<TreeNode*>> dp;
vector<TreeNode*> allPossibleBSTs2(int start,int end){
    //base case
    if(start>end)
        return {0};
    if(start==end)
        return {new TreeNode(start)};
    
    if(dp.find({start,end})!=dp.end()){
        return dp[{start,end}];
    }
    vector<TreeNode*> ans;
    for(int i=start;i<=end;i++){
        vector<TreeNode*> left=allPossibleBSTs2(start,i-1);
        vector<TreeNode*> right=allPossibleBSTs2(i+1,end);
        //for all possible tree permutation
        for(int j=0;j<left.size();j++){
            for(int k=0;k<right.size();k++){
                TreeNode* root=new TreeNode(i);
                root->left=left[j];
                root->right=right[k];
                ans.push_back(root);
            }
        }
    }
    return dp[{start,end}]= ans;
}
vector<TreeNode*> generateTrees2(int n) {
    if(n==0)
        return {};
    return allPossibleBSTs2(1,n);
}


void preorderTraversal(TreeNode* root){  
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int main(){
    vector<TreeNode*> k=generateTrees2(3);
    for(auto i:k){
        preorderTraversal(i);
        cout<<endl;
    }

}