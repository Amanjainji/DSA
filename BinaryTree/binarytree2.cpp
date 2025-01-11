#include<iostream>
#include<queue>
#include<vector>
#include<stack>
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


void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left= new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data <<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right= new node(rightData);
            q.push(temp->right);
        }
    }
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

//ques 14 - Sum of longest bloodline of a tree
void solve(node* root,int sum,int&maxSum , int len,int &maxLen);

pair<int,int> SumOfLongRootToLeafPath(node* root){
    int len=0;
    int maxLen=0;

    int sum=0;
    int maxSum=INT_MIN;


    solve(root,sum,maxSum,len,maxLen);
    pair<int,int> p=make_pair(maxSum,maxLen);

    return p;
}

void solve(node* root,int sum,int&maxSum , int len,int &maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            maxSum=sum;
        }
        else if(len==maxLen){
            maxSum=max(sum,maxSum);
        }
        return;
    }

    sum=sum+root->data;
    solve(root->left,sum,maxSum ,len+1,maxLen);
    solve(root->right,sum,maxSum ,len+1,maxLen);
}

//ques 15 - lowest common ancestor (LCA) of a tree
node* lca(node* root,int n1,int n2){
    //base case
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    node* leftAns=lca(root->left,n1,n2);
    node* rightAns=lca(root->right,n1,n2);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else if(leftAns==NULL && rightAns==NULL){
        return NULL;
    }
}


//ques 16 - k sum path
void solve1(node* root,int k, int &count,vector<int> path){
    //base case
    if(root==NULL)
        return;
    
    path.push_back(root->data);
    //left
    solve1(root->left,k,count,path);
    //right
    solve1(root->right,k,count,path);

    //check for k sum
    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k)
            count++;
    }

    path.pop_back();
}
int sumK(node* root,int k){
    vector<int> path;
    int count=0;
    solve1(root, k,count , path);
    return count;
}

//ques 17 - K th ancester of a node in a tree

//17.1  using vector
void solve2(node* root,int valNode,vector<int> &path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    //left
    solve2(root->left,valNode,path);
    //right
    solve2(root->right,valNode,path);

    if(path[path.size()-1]==valNode){
        return;
    }
    path.pop_back();
}
int KthAncestor(node* root,int k,int valNode){
    if(root==NULL)
        return -1;
    
    vector<int> path;
    solve2(root,valNode,path);

    if(path.size()==0 || k>=path.size()) //edge case
        return -1;
    
    int n=path.size()-1;
    return path[n-k];
}

//17.2 No vector used
node* solve3(node* root,int&k,int valnode){
    //base case
    if(root==NULL)
        return NULL;
    
    if(root->data==valnode){
        return root;
    }

    node* leftAns= solve3(root->left,k,valnode);
    node* rightAns= solve3(root->right,k,valnode);

    if(leftAns!=NULL && rightAns ==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns==NULL && rightAns !=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;  //to lock the answer
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int KthAncestor2(node* root,int k,int valNode){
    node* ans=solve3(root,k,valNode);
    if(ans==NULL || ans->data==valNode) //for condn of kth ancestor of root node
        return -1;
    else
        return ans->data;
}
//ques 18 - Max sum of Non adjacent Nodes
pair<int,int> solve4(node* root);
int getMaxSum(node* root){
    pair<int,int> ans=solve4(root);
    return max(ans.first,ans.second);
}
pair<int,int> solve4(node* root){
    //base case
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> left=solve4(root->left);
    pair<int,int> right=solve4(root->right);
    pair<int,int> res;
    //including
    res.first= root->data+left.second+right.second;
    //excluding
    res.second=max(left.first,left.second)+max(right.first,right.second);

    return res;
}

int main(){
    node* root=NULL;
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root); 
    //cout<<SumOfLongRootToLeafPath(root).first<<endl;
    //cout<<SumOfLongRootToLeafPath(root).second;

    // 1 2 3 -1 -1 -1 -1
    // cout<<lca(root,2,3)->data;

    // 1 2 3 -1 -1 -1 -1
    //cout<<sumK(root,3);

    //1 2 3 4 -1 -1 -1 5 6 -1 -1 -1 -1
    //cout<<KthAncestor(root,2,5);

    //1 2 3 4 -1 -1 -1 5 6 -1 -1 -1 -1
    //cout<<KthAncestor2(root,1,5);


    //1 2 3 4 -1 -1 -1 5 6 -1 -1 -1 -1
    cout<<getMaxSum(root);


    return 0;
}