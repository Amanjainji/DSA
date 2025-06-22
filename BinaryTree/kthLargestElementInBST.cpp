#include<bits/stdc++.h>
#include<map>
#include<limits.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void insertBST(int val,node* &root){
    if(root==NULL){
        root=new node(val);
        return;
    }
    if(val<root->data){
        insertBST(val,root->left);
    }
    else{
        insertBST(val,root->right);
    }
}

int solve(node* root,int &i,int k){
    //base case
    if(root==NULL){
        return -1;
    }
    //L
    int right=solve(root->right,i,k);
    if(right!=-1){
        return right;
    }
    //N
    i++;
    if(i==k){
        return root->data;
    }
    //R
    return solve(root->left,i,k);
}

int kthLargest(node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

int main(){ 
    node* root=new node(50);
    insertBST(30,root);
    insertBST(70,root);
    insertBST(20,root);
    insertBST(40,root);
    insertBST(60,root);
    insertBST(80,root);
    cout<<kthLargest(root,3); //60


}