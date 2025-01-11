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


void inorderTraversal(node* root){  //LNR
    //base case
    if(root==NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}


//Burning tree - burn the tree when a node can burn its all neighbour node in 1 second each

//create parent mapping using BFS
node* createParentMapping(node* root,int target,map<node*,node*> &nodeToParent){  //create parent mapping and return target node from target value(int) 
    node* res=NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root]=NULL;

    while(!q.empty()){
        node* front=q.front();
        q.pop();

        if(front->data==target){
            res=front;
        }

        if(front->left){
            nodeToParent[front->left]=front;
            q.push(front->left);
        }

        if(front->right){
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
    }

    return res;
}

int burnTree(node* root,map<node*,node*> nodeToParent){
    map<node*,bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root]=true;

    int ans=0;
    while(!q.empty()){
        bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++){
            //process neighbouring nodes
            node* front=q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
            }

            if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag=1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]=1;
            }
        }

        if(flag){
            ans++;
        }
    }

    return ans;
}

/*algo
    step 1: create nodeToParentMapping
    step 2: find target node 
    step 3: burn the tree in min time 

*/
int minTime(node* root,int target){
    map<node*,node*> nodeToParent;
    node* targetNode= createParentMapping(root,target,nodeToParent);

    int ans=burnTree(targetNode, nodeToParent);
    return ans;
}

int main(){
    node* root;
//1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    buildFromLevelOrder(root);
    cout<<"Minimum time to burn the tree:"<<minTime(root,8);
}