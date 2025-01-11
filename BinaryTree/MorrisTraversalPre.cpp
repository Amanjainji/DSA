// C++ program for Morris Preorder traversal 
#include <bits/stdc++.h>
using namespace std; 

class Node { 
public:
    int data; 
    Node *left, *right; 
    Node(int x){
          data = x;
          left = right = nullptr;
    }
}; 

// Preorder traversal without recursion and without stack 
void preOrder(Node* root) { 
    while (root)  { 
        
        // If left child is null, print the  current node data. Move to  right child. 
        if (root->left == nullptr)  { 
            cout<<root->data<<" ";
            root = root->right; 
        } 
        else { 
            
            // Find inorder predecessor 
            Node* current = root->left;   //current is the predecessor
            while (current->right!=NULL && current->right != root) 
                current = current->right; 

            // If the right child of inorder predecessor already points to this node 
            if (current->right == root)  { 
                current->right = nullptr;
                root = root->right; 
            } 

            // If right child doesn't point to this node, then print this node and make right child point to this node 
            else { //current->right == NULL
                cout<<root->data<<" ";
                current->right = root; 
                root = root->left; 
            } 
        } 
    } 
} 

int main()  { 
  
    // Constructing binary tree.
    //
    //             1
    //            / \
    //           /   \
    //          2     3
    //         / \   / \
    //        /   \ /   \
    //       4    5 6    7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrder(root); 
    cout<<endl; 
  
    return 0; 
}