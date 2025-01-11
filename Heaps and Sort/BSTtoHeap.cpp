#include<bits/stdc++.h>
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

void preorderTraversal(node* root){  //NLR
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);   
    preorderTraversal(root->right);
}

//ques - convert BST to Min Heap 
/*
conditions:

given tree is already CBT
just convert in min heap using minorder property
and another condition left->data< right->data
so finally:

Node_Data < left_data < right_data
*/

//algorithm
/* step 1 - generate inorder array from BST
step 2 - using NLR as Node_Data < left_data < right_data
, just change the value in original data
(as complete tree , structure remains same ,so we just need to update the values to convert into heap)

*/

void inorder(node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

void BSTtoHeaphelper(node* &root,vector<int> inorder,int &index){
    if(root==NULL){
        return;
    }
    root->data=inorder[index];
    index++;
    BSTtoHeaphelper(root->left,inorder,index);
    BSTtoHeaphelper(root->right,inorder,index);
}

void BSTtoHeap(node* &root1){
    vector<int> arr;
    inorder(root1,arr);
    int index=0;
    BSTtoHeaphelper(root1,arr,index);
}

int main(){
    //balance bst
    node* root=new node(20);
    insertBST(15,root);
    insertBST(25,root);
    insertBST(10,root);
    insertBST(16,root);
    insertBST(23,root);
    insertBST(30,root);
    BSTtoHeap(root);
    preorderTraversal(root);
    cout<<endl;

}
