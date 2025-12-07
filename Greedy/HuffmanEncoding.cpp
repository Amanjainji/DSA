#include<bits/stdc++.h>
using namespace std;

/*
Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

Example 1:

S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111

HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Hence printing them in the PreOrder of Binary 
Tree.

You don't need to read or print anything. Your task is to complete the function huffmanCodes() which takes the given string S, frequency array f[] and number of characters N as input parameters and returns a vector of strings containing all huffman codes in order of preorder traversal of the tree.

Expected Time complexity: O(N * LogN) 
Expected Space complexity: O(N) 

*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

class cmp{
    public:
    bool operator()(Node *a ,Node* b){
        return a->data>b->data;
    }
};

void traverse(Node* root,vector<string> &ans,string temp);

vector<string> huffmanCodes(string S,vector<int> f,int n){
    priority_queue<Node*,vector<Node*>,cmp> pq;
    for(int i=0;i<n;i++){
        Node* temp=new Node(f[i]);
        pq.push(temp);
    }

    //Tree formation
    while(pq.size()>1){
        Node* left=pq.top();
        pq.pop();

        Node* right=pq.top();
        pq.pop();

        Node* newNode=new Node(left->data +  right->data);
        newNode->left=left;
        newNode->right=right;
        pq.push(newNode);
    }

    Node* root=pq.top();
    vector<string> ans;
    string temp="";
    traverse(root,ans,temp);
    return ans;
}

void traverse(Node* root,vector<string> &ans,string temp){
    if(root->left==NULL && root->right==NULL){
        ans.push_back(temp);
        return;
    }

    traverse(root->left,ans,temp+'0');
    traverse(root->right,ans,temp+'1');
}

int main(){
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    vector<string> ans=huffmanCodes(S,f,f.size());
    for(auto i: ans){
        cout<<i<<" ";
    }
}