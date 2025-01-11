#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<map>
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

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root= new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"For inserting in left:"<<endl;
    root->left=buildTree(root->left);

    cout<<"For inserting in right "<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);   //seperator - NULL for leveling
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){  //purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){  //queue still has some child nodes
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

void inorderTraversal(node* root){  //LNR
    //base case
    if(root==NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void postorderTraversal(node* root){  //LRN
    //base case
    if(root==NULL){
        return;
    }
    
    postorderTraversal(root->left);   
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

// 1)Construct using Preorder and Inorder
void findPositionMap(int in[],int n,map<int,int> &nodeToIndex){
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
}

node* solveInPre(int *in,int *pre,int n,int &index,int inorderStart,int inorderEnd,map<int,int> nodeToIndex){

    //base case
    if(index>=n || inorderStart>inorderEnd){
        return NULL;
    }

    int element= pre[index];
    index++;  //next root element gets updates with each call in recursion
    node* root= new node(element);
    int pos = nodeToIndex[element];

    //recursive call
    root->left=solveInPre(in,pre,n,index,inorderStart,pos-1,nodeToIndex);
    root->right=solveInPre(in,pre,n,index,pos+1,inorderEnd,nodeToIndex);

    return root;
}


node* PreInConstruct(int *in,int *pre,int n){ //n = total nodes
    int preOrderIndex=0;
    map<int,int> nodeToIndex;  //node->data -> index
    findPositionMap(in,n,nodeToIndex);
    node* ans=solveInPre(in,pre,n,preOrderIndex,0,n-1,nodeToIndex);
    return ans;
}

// 2)Construct using Postorder and Inorder
node* solveInPost(int *in,int *post,int n,int &index,int inorderStart,int inorderEnd,map<int,int> nodeToIndex){

    //base case
    if(index<0 || inorderStart>inorderEnd){
        return NULL;
    }

    int element= post[index];
    index--;  //next root element gets updates with each call in recursion
    node* root= new node(element);
    int pos = nodeToIndex[element];

    //recursive call -- right first
    root->right=solveInPost(in,post,n,index,pos+1,inorderEnd,nodeToIndex);
    root->left=solveInPost(in,post,n,index,inorderStart,pos-1,nodeToIndex);
    

    return root;
}


node* PostInConstruct(int *in,int *post,int n){ //n = total nodes
    int postOrderIndex=n-1;
    map<int,int> nodeToIndex;  //node->data -> index
    findPositionMap(in,n,nodeToIndex);
    node* ans=solveInPost(in,post,n,postOrderIndex,0,n-1,nodeToIndex);
    return ans;
}

int main(){
    int in[6]={3,1,4,0,5,2};
    int pre[6]={0,1,3,4,2,5};
    int post[6]={3,4,1,5,2,0};
    //node* root=PreInConstruct(in,pre,6);
    //postorderTraversal(root);
    node* root1=PostInConstruct(in,post,6);
    //inorderTraversal(root1);

}