#include<bits/stdc++.h>
using namespace std;
//leetcode #889

//algo 
/*
Create Root Node:

Construct the root node from preorder[0] and mark it as visited in mpp and Store it in the node map.
Iterate through Preorder List:

For each node in preorder (starting from index 1):
Create a TreeNode for the current value and mark it as visited in mpp.
Store the node in the node map.
Find Parent in Postorder:

Determine the index of the current node in postorder.
Check for the nearest visited ancestor in postorder (i.e., a node that has space for a left or right child and already found in preorder).
Attach the Node:

If the found ancestor has a free left child, attach the new node as the left child.
Otherwise, attach it as the right child.
Repeat Until Tree is Constructed:
*/
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    unordered_map<int,bool> visited;
    unordered_map<int,TreeNode*> node;
    for(int i=1;i<=preorder.size();i++){
        visited[i]=false;
    }
    unordered_map<int,int> indexPostOrder;
    for(int i=0;i<postorder.size();i++){
        indexPostOrder[postorder[i]]=i;
    }
    TreeNode* root=new TreeNode(preorder[0]);
    visited[preorder[0]]=true;
    node[preorder[0]]=root;
    for(int i=1;i<preorder.size();i++){
        TreeNode* temp=new TreeNode(preorder[i]);
        visited[preorder[i]]=true;
        node[preorder[i]]=temp;
        int index=indexPostOrder[preorder[i]];
        for(int j=index+1;j<postorder.size();j++){
            if(visited[postorder[j]]){
                if(node[postorder[j]]->left && node[postorder[j]]->right)
                    continue;
                else{
                    if(!node[postorder[j]]->left){
                        node[postorder[j]]->left=temp;
                    }
                    else if(!node[postorder[j]]->right){
                        node[postorder[j]]->right=temp;
                    }
                    break;
                }
            }
        }
    }
    return root;
}