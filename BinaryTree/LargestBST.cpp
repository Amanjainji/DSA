#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

void preorderTraversal(TreeNode* root){  //NLR
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorderTraversal(root->left);   
    preorderTraversal(root->right);
}

void preorder(TreeNode* root,string &s){
    if(root==NULL){
        s+="n";
        return;
    }
    s+=to_string(root->val);
    preorder(root->left,s);
    preorder(root->right,s);
}
string serialize(TreeNode* root) {
    string s="";
    preorder(root,s);
    return s;
}

void deserial(TreeNode* &root,string &s){
    char chr=s[0];
    s.erase(s.begin());
    if(chr=='n' || s.empty()){
        return;
    }
    else{
        root=new TreeNode((int)chr);
        deserial(root->left,s);
        deserial(root->right,s);
    }
}
TreeNode* deserialize(string data) {
    if(data[0]=='n')
        return NULL;
    
    TreeNode* root=NULL;
    deserial(root,data);

    return root;


}
/*
class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};



info solve(TreeNode* root,int &ans){
    //base case
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info currNode;

    currNode.size=left.size + right.size +1;
    currNode.maxi=max(root->val,right.maxi);
    currNode.mini=min(root->val,left.mini);

    if(left.isBST && right.isBST && (root->val >left.maxi && root->val <right.mini)){
        currNode.isBST=true;
    }
    else{
        currNode.isBST=false;
    }

    //answer update
    if(currNode.isBST){
        ans=max(ans,currNode.size);
    }

    return currNode;
}

int largestBST(TreeNode* root){
    int maxSize=0;
    info temp=solve(root,maxSize);
    return maxSize;
}*/

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->left->right=new TreeNode(6);
    root->right->right=new TreeNode(5);

    cout<<serialize(root);

    TreeNode* root1=deserialize(serialize(root));
    preorderTraversal(root1);
}