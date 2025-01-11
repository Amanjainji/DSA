#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
void inorderTraversal(TreeNode* root){  //LNR
    //base case
    if(root==NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) 
            return NULL;
        if(head->next==NULL) 
            return new TreeNode(head->val);

        ListNode* slow=head;
        ListNode* fast= head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        prev->next=NULL;
        TreeNode* root= new TreeNode(slow->val);
        root->left= sortedListToBST(head);
        root->right= sortedListToBST(slow->next);
        return root;
}

int main(){
    //sorted linked list
    ListNode* head=new ListNode(-3);
    head->next=new ListNode(-7);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(10);
    head->next->next->next->next=new ListNode(12);

    TreeNode* root=sortedListToBST(head);
    inorderTraversal(root);
}