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

bool SearchBST(node* root,int val){
    if(root==NULL){
        return false;
    }

    if(root->data==val){
        return true;
    }
    else if(root->data>val){
        return SearchBST(root->left,val);
    }
    else{
        return SearchBST(root->right,val);
    }
}

bool SearchBSTiterative(node* Root,int val){
    node* root=Root;
    while(root!=NULL){
        if(root->data==val){
            return true;
        }
        else if(root->data>val){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return false;
}
void print(node* root){
    queue<node*> q;
    //static int count=1;
    q.push(root);
    q.push(NULL);   //seperator - NULL for leveling
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){  //purana level complete traverse ho chuka hai
            //count++;          
            if(!q.empty()){ 
                cout<<endl; //queue still has some child nodes
                //cout<<endl<<count<<" level: ";
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
        
            if(temp->right)
                q.push(temp->right);
        }
    } 
}

int maxValue(node* root){
    if(root==NULL){
        return -1;
    }
    node* temp=root;
    while(temp->right){
        temp=temp->right;
    }
    return temp->data;
}

int minValue(node* root){
    if(root==NULL){
        return -1;
    }
    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp->data;
}

//Delete node from BST

node* miniVal(node* root){
    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}
node* deleteFromBST(node* root,int val){
    if(root==NULL){
        cout<<"Underflow..."<<endl;
        return root;
    }
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //if only left child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        //if only right child
        if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=miniVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
        
    }
    else if(root->data>val){
        //left part mein jao
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        //right part mein jao
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

//ques 1: Validate BST
//approach-1
void inorderBST(node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorderBST(root->left,ans);
    ans.push_back(root->data);
    inorderBST(root->right,ans);
}
bool validateBST(node* root){
    if(root==NULL){
        return true;
    }

    //find inorder vector
    vector<int> inorder;
    inorderBST(root,inorder);

    //isSorted
    for(int i=0;i<inorder.size()-1;i++){
        if(inorder[i+1]<inorder[i]){
            return false;
        }
    }
    return true;
}

//approach-2
bool isBST(node* root,int min,int max){
    //base case
    if(root==NULL){
        return true;
    }

    if(root->data>=min && root->data<=max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}
bool validateBST2(node* root){
    int min=INT_MIN;
    int max=INT_MAX;
    return isBST(root,min,max);
}

//ques 2 - kth smallest element
int solve(node* root,int &i,int k){
    //base case
    if(root==NULL){
        return -1;
    }
    //L
    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    //N
    i++;
    if(i==k){
        return root->data;
    }
    //R
    return solve(root->right,i,k);
}
int kthSmallest(node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

//ques 3 - Lowest common ancestor
node*  lowestCommonAncestor(node* root,int p,int q){
    if(root==NULL){
        return NULL;
    }
    if(root->data>p && root->data>q){
        return lowestCommonAncestor(root->left,p,q);
    }
    if(root->data<p && root->data<q){
        return lowestCommonAncestor(root->right,p,q);
    }
    return root;  
}

//ques 4 - two sum in BST

//algorithm
//find inorder array
//use two pointer method to find two sum

bool twoSum(node* root,int target){
    if(root==NULL){
        return false;
    }

    //generate inorder array
    vector<int> ans;
    inorderBST(root,ans);

    //two pointer
    int i=0,j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==target){
            return true;
        }
        else if(ans[i]+ans[j]>target){
            j--;
        }
        else if(ans[i]+ans[j]<target){
            i++;
        }
    }
    return false;   
}

//ques 5 - flatten BST into sorted linked list or a right skewed linked list
node* FlattenBST(node* root){
    vector<int> ans;
    inorderBST(root,ans);   //find inorder Array
    int n=ans.size();

    //generate a linked list
    node* newRoot=new node(ans[0]);
    node* curr=newRoot;
    for(int i=1;i<n;i++){
        node* temp=new node(ans[i]);    
        //curr->left=NULL;  //already null as new node
        curr->right=temp;
        curr=temp;
    }

    return newRoot;
}

//ques 6 - balance BST
node* inorderToBST(vector<int> &nums,int s,int e) {
        if(s>e)
            return NULL;
        
        int mid=(s+e)/2;
        node* root=new node(nums[mid]);
        root->left=inorderToBST(nums,s,mid-1);
        root->right=inorderToBST(nums,mid+1,e);
        return root;
}

node* balanceTree(node* root){
    //find inorder
    vector<int> in;
    inorderBST(root,in);

    return inorderToBST(in,0,in.size()-1);
}

//ques 7 - BST from preorderTraversal

//approach-1 O(N^2)
//normal inserting value from array
node* bstFromPreorder(vector<int>& preorder) {
    if(preorder.size()==0){
        return NULL;
    }
    node* root=new node(preorder[0]);
    for(int i=1;i<preorder.size();i++){
        insertBST(preorder[i],root);
    }
    return root;
}

//approach-2 O(N*logN)
//given array is preorder ,inorder is sorted of that , just create a BT using preorder and inorder

//approach-3 O(N)
node* solve0(vector<int> &preorder,int mini,int maxi,int &i){
    if(i>=preorder.size()){
        return NULL;
    }

    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }

    node* root=new node(preorder[i]);
    i++;
    root->left=solve0(preorder,mini,root->data,i);
    root->right=solve0(preorder,root->data,maxi,i);
    return root;
}
node* preOrderToBST(vector<int> &preorder){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve0(preorder,mini,maxi,i);
}

//ques 8- merge2BST

//approach 1 -- TC = O(m+n)  SC = O(m+n)

/*  
step 1: find inorder array of root
step 2: merge these sorted arrays and sort
step 3: create a balance tree from that final sorted array
*/ 
node* merge2BST(node* root1,node* root2){
    //find inorder array
    vector<int> inorder1;
    inorderBST(root1,inorder1);
    vector<int> inorder2;
    inorderBST(root2,inorder2);

    //merge 2 Sorted arrays 
    for(int i=0;i<inorder2.size();i++){
        inorder1.push_back(inorder2[i]);
    }
    sort(inorder1.begin(),inorder1.end());

    //sorted array to BST
    node* root=inorderToBST(inorder1,0,inorder1.size()-1);
    return root;

}

//approach 2 - TC = O(m+n)  SC = O(h1+h2)  //better SC

/*

step1 : Convert BST into sorted doubly linked list 
step2 : merge 2 sorted linked lists
step3 : create a balance bst from sorted linked list

*/
void convertIntoSortedDLL(node* root,node* &head){ //doubly linked list
    //base case
    if(root==NULL){
        return;
    }
    //left work as prev and right work as next

    // Convert right subtree first
    convertIntoSortedDLL(root->right,head);

    // Adjust pointers
    root->right= head;
    if(head!=NULL)
        head->left = root;
    // Move head pointer
    head=root;

    // Convert left subtree
    convertIntoSortedDLL(root->left,head);
}

node* merge2linkedList(node* head1,node* head2){
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node* head=NULL;
    node* tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){  //first node
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }    
        }  
    }

    if(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
    }
    if(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
    }
    return head;
}
int countNodes(node* root1){
    int cnt=0;
    node* root=root1;
    while(root!=NULL){
        cnt++;
        root=root->right;
    }
    return cnt;
}
node* sortedLLtoBST(node* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }

    node* left=sortedLLtoBST(head,n/2);

    node* root=head;
    root->left=left;
    head=head->right;

    root->right=sortedLLtoBST(head,n-(n/2)-1);

    return root;
}
node* mergeTwoBST(node* root1,node* root2){

    //Convert BST into sorted doubly linked list 
    node* head1=NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left=NULL;

    node* head2=NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left=NULL;

    //merge 2 sorted linked lists
    node* head=merge2linkedList(head1,head2);

    //create a balance bst from sorted linked list
    int n=countNodes(head);
    node* BST=sortedLLtoBST(head,n);

    return BST;
}

int main(){ 
    node* root=new node(5);
    insertBST(3,root);
    insertBST(6,root);
    insertBST(2,root);
    insertBST(4,root);
    insertBST(7,root);
    node* root1=new node(15);
    insertBST(8,root1);
    insertBST(19,root1);
    insertBST(4,root1);
    insertBST(10,root1);
    insertBST(55,root1);

    //print(root);
    //cout<<"Search:"<<SearchBST(root,31);
    //cout<<minValue(root);

    cout<<endl;
    //deleteFromBST(root,6);
    //print(root);

    //cout<<endl<<validateBST2(root);
    //node* lca=lowestCommonAncestor(root,31,49);
    //cout<<lca->data<<endl;
    //cout<<twoSum(root,9);
/*
    node* newRoot=FlattenBST(root);
    while(newRoot->right){
        cout<<newRoot->data<<" ";
        newRoot=newRoot->right;
    }
    while(newRoot->left)
        cout<<newRoot->data<<" ";
*/

node* root2=merge2BST(root,root1);
print(root2);
}