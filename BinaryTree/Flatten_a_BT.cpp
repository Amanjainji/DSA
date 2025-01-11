#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void flattenTree(Node* root){
    Node* curr=root;
    while(curr!=NULL){    
        if(curr->left){
            Node* pred=curr->left;
            while(pred->right){
                pred=pred->right;
            }

            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
}

int main() {
  
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //            / \  
    //           4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    flattenTree(root);
    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    return 0;
}