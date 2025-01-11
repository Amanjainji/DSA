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

// Function to perform reverse level order traversal
void reverseLevelOrder(node* root) {
    if (root == NULL) {
        return;
    }

    // Create an empty queue for level order traversal
    queue<node*> q;
    // Create a stack to store the nodes in reverse order
    stack<node*> s;

    // Enqueue the root node
    q.push(root);
    q.push(NULL);

    // Perform level order traversal and push nodes to the stack
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        
        // Push the current node to the stack
        s.push(current);
        if(current==NULL){
            if(!q.empty()) //still child nodes
                q.push(NULL);
        } 
        
        else{        
        // Enqueue right child first, then left child (so that left child is processed first in reverse)
            if (current->right) {
                q.push(current->right);
            }
            if (current->left) {
                q.push(current->left);
            }
        }
    }
  // Now pop all nodes from the stack and print them
  while (!s.empty()) {
        node* top=s.top();
        s.pop();
        if(top==NULL){
            cout<<endl;
        }
        else{
            cout << top->data << " ";
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

void preorderTraversal(node* root){  //NLR
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);   
    preorderTraversal(root->right);
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


//ques 1 -  count no. of leaves
void inorder(node* root,int &count){
    if(root==NULL){
        return;
    }
    inorder(root->left,count);

    //leaf node condn
    if(root->left==NULL && root->right==NULL){
        count++;
    }

    inorder(root->right,count);
}
int noOfLeafNodes(node* root){
    int count=0;
    inorder(root,count);
    return count;
}

//ques 2 - find height of binary tree (distance between root and lowest node)

int height(node* root){
    if(root==NULL){  //base case
        return 0;
    }

    int left= height(root->left);
    int right= height(root->right);

    int ans= max(left,right)+1;
    return ans;
}

//ques 3 - Diameter of a tree or width (max distance between two leaf node)

//3.1 - first method - T.C.= O(n^2)
int diameter(node* root){
    if(root==NULL){
        return 0;
    }

    int op1=diameter(root->left);  // answer on left side of tree only
    int op2= diameter(root->right);  // answer on right side of tree only
    int op3= height(root->left) + height(root->right)+1;  // combo - left height+ right height + 1(root node)

    int ans=max(op1,max(op2,op3));
    return ans;
}

// 3.2 - second method - T.C.=O(n)
pair<int,int> diameterfast(node* root){  //pair(diameter,height)
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameterfast(root->left);
    pair<int,int> right=diameterfast(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second + right.second +1;

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;

    return ans;
} 

// ques 4 - balance tree (diffrence between height of left and right subtrees is not more than one for all nodes of tree)

//4.1 - O(n^2)
bool isBalanced(node * root){
    if(root==NULL){
        return true;
    }

    bool left =isBalanced(root->left);
    bool right=isBalanced(root->right);

    bool diff=abs(height(root->left) - height(root->right))<=1;

    if(left && right && diff)
        return true;
    else
        return false;
}

//4.2 - O(n)
pair<bool,int> isBalancedfast(node * root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> left =isBalancedfast(root->left);
    pair<bool,int> right=isBalancedfast(root->right);

    bool leftAns= left.first;
    bool rightAns= right.first;
    bool diff=abs(left.second - right.second)<=1;

    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    ans.first=leftAns && rightAns && diff;

    return ans;
}

//ques 5 - Identical tree?
bool isIdentical(node* r1,node* r2){
    //base case
    if(r1==NULL && r2 ==NULL)
        return true;
    if((r1==NULL && r2!=NULL) ||(r1!=NULL && r2==NULL))
        return false;
    
    bool left =  isIdentical(r1->left,r2->left);
    bool right= isIdentical(r1->right,r2->right);
    bool value= r1->data == r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
    
}

//QUES 6 - sum of tree elements(left and right side child sums equal to parent node)

pair<bool,int> isSumTreeFast(node* root){
    //base case
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    //condn for leaf nodes
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftAns=isSumTreeFast(root->left);
    pair<bool,int> rightAns=isSumTreeFast(root->right);

    bool left=leftAns.first;
    bool right=rightAns.first;

    bool condn= root->data== (leftAns.second+rightAns.second);

    pair<bool,int> ans;
    if(left && right && condn){
        ans.first=true;
        ans.second=root->data + leftAns.second +rightAns.second;
    }
    else{
        ans.first=false;
    }
    return ans;
}

//ques 7 - zig zag traversal
vector<int> zigzagTraverse(node* root){
    vector<int> result;
    if(root==NULL)   // empty tree condn
        return result;
    
    queue<node*> q;
    q.push(root);

    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();  //har level pr size change hoga
        vector<int> ans(size);  //har level pr naya ans vector banega
        for(int i=0;i<size;i++){
            node* frontNode = q.front();
            q.pop();

            int index= leftToRight? i: size-i-1;  //important
            ans[index]=frontNode ->data;
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }  //for loop end
        
        //direction change krni hai
        leftToRight=!leftToRight;

        for(auto i:ans)
            result.push_back(i);    
    } //while loop end

    return result;
}

//ques 8 - boundary traversal (print all bounary nodes)

/*
Algorithm:
1)print root node data.
2)print only left part from root excluding leaf node.
3)print all the leaf node.
4)print only right part from root in reverse order ,excluding leaf node and root node.
*/

//function used , describe below
void traverseLeft(node* root, vector<int> &ans);
void traverseLeaf(node* root, vector<int> &ans);
void traverseRight(node* root, vector<int> &ans);

//main
vector<int> boundary(node* root){
    vector<int> ans;
    if(root==NULL){ //empty tree
        return ans;
    }

    //1 push root node
    ans.push_back(root->data);

    //2 left part traverse
    traverseLeft(root->left,ans);

    //3 traverse leaf node
    //left subtree
    traverseLeaf(root->left,ans);
    //right subtree
    traverseLeaf(root->right,ans);

    //4 traverse right part
    traverseRight(root->right,ans);

    return ans;

}
void traverseLeft(node* root, vector<int> &ans){
    //base case
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->left)
        traverseLeft(root->left,ans);
    else  
        traverseLeft(root->right,ans);  
}

void traverseLeaf(node* root, vector<int> &ans){ 
    //using LNR
    //base case
    if(root==NULL)
        return;
    
    if(root->left==NULL && root->right ==NULL){
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(node* root, vector<int> &ans){
    //base case
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }

    if(root->right)
        traverseRight(root->right,ans);
    else
        traverseRight(root->left,ans);

    //wapas aagye
    ans.push_back(root->data);  //reverse order
}

//ques 9 - vertical order traversal
vector<int> verticalOrder(node* root){
    map<int,map<int,vector<int>>> nodes;  //mapping of horizontal distance and levelwise nodes<level , vector of nodes data>
    queue<pair<node*,pair<int,int>>> q;
    //queue mein node* toh hoti hi thi level order mein , ek pair or add kr diya showing Horizotal Distance(int) and level(int)
    vector<int> ans;

    if(root==NULL)
        return ans;

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<node*,pair<int,int>> temp= q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second.first;
        int lvl= temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));

        if(frontNode->right)
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));  
    }

    for(auto i:nodes){
        for(auto j: i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}


//ques 10- top view of binary tree
vector<int> topView(node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    map<int,int> topNode;  // Hd --> data
    queue<pair<node* ,int>> q;  //Node and Hd
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp =q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second;

        //if no value is present for the Hd , then do not change that value else skip
        if(topNode.find(hd)==topNode.end()){  //important condn showing no value is present for that particular horizontal distance
            topNode[hd]=frontNode->data;
        }

        if(frontNode->left)
            q.push(make_pair(frontNode->left,hd-1));

        if(frontNode->right)
            q.push(make_pair(frontNode->right,hd+1));
    }

    for(auto i:topNode)  //map is ordered
        ans.push_back(i.second);

    return ans;
}

// ques 11 bottom view
//similar to top view , just remove the important condn
vector<int> bottomView(node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    map<int,int> topNode;  // Hd --> data
    queue<pair<node* ,int>> q;  //Node and Hd
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp =q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second;

        topNode[hd]=frontNode->data;  //only update

        if(frontNode->left)
            q.push(make_pair(frontNode->left,hd-1));

        if(frontNode->right)
            q.push(make_pair(frontNode->right,hd+1));
    }

    for(auto i:topNode)  //map is ordered
        ans.push_back(i.second);
}

//ques 11 - left view 

//without recursion
vector<int> leftView(node* root) {
    vector<int> ans;
    if (root == NULL) 
        return ans;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // Number of nodes at the current level

        for (int i = 0; i < levelSize; i++) {
            node* temp = q.front();
            q.pop();

            // Add the first node of each level to the answer (left view)
            if (i == 0) {
                ans.push_back(temp->data);
            }

            // Enqueue left and right children of all nodes
            if (temp->left) 
                q.push(temp->left);
            if (temp->right) 
                q.push(temp->right);
        }
    }
    return ans;
}

//with recursion

void solve(node* root,vector<int> &ans,int level){   
    //base case
    if(root==NULL){
        return;
    }

    //we enetered into a new level condn
    if(level==ans.size())
        ans.push_back(root->data);
    
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);

}

vector<int> leftViewRecursive(node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

//ques 12 - right view

//single change from left view
void solve2(node* root,vector<int> &ans,int level){   
    //base case
    if(root==NULL){
        return;
    }

    //we enetered into a new level condn
    if(level==ans.size())
        ans.push_back(root->data);
    
    solve2(root->right,ans,level+1);  //single change
    solve2(root->left,ans,level+1);
}

vector<int> rightView(node* root){
    vector<int> ans;
    solve2(root,ans,0);
    return ans;
}

//ques 13 - diagonal traversal
void diagonalTraversalUtil(node* root, int d, map<int, vector<int>>& diagonalMap) {
    if (root == NULL)
        return;

    // Store all nodes of the same diagonal in a map
    diagonalMap[d].push_back(root->data);

    // Increase the diagonal distance if going to the left child
    diagonalTraversalUtil(root->left, d + 1, diagonalMap);
    // Keep the same diagonal distance for the right child
    diagonalTraversalUtil(root->right, d, diagonalMap);
}

vector<int> diagonalTraversal(node* root) {
    map<int, vector<int>> diagonalMap;
    vector<int> ans;

    if (root == NULL)
        return ans;

    // Call the utility function with initial diagonal distance 0
    diagonalTraversalUtil(root, 0, diagonalMap);

    // Print the diagonal traversal
    for (auto i : diagonalMap) {
        for (auto j : i.second) {
            ans.push_back(j);
        }
    }
    return ans;
}

//ques 14 - symmetrical
bool solve3(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL && root2!=NULL){
        return false;
    }
    else if(root1!=NULL && root2==NULL){
        return false;
    }

    if(root1->data==root2->data){
        bool a=solve3(root1->left,root2->right);
        bool b=solve3(root1->right,root2->left);
        return a&b;
    }
    else{
        return false;
    }
}
bool isSymmetric(node* root){
    return solve3(root->left,root->right);
}

//ques 15 - minimum height
int minDepth(node* root) {
        if(root==NULL){
            return 0;
        }
        int l,r;
        l=minDepth(root->left);
        r=minDepth(root->right);
        int k=0;
        if(l!=0 && r!=0){
            k=min(l,r);
        }
        if(l==0){
            k=r;
        }
        if(r==0){
            k=l;
        }
        return k+1;
    }
int main(){
    node* root=NULL;
    //node* root1=NULL;
    
    //creating a tree
    //root=buildTree(root); 
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //cout<<"Printing tree by level order traversal:"<<endl;
    //levelOrderTraversal(root);
    //cout<<"Printing tree by reverse level order traversal:"<<endl;
    //reverseLevelOrder(root);

    /*
    cout<<"Printing tree by inorder traversal:"<<endl;
    inorderTraversal(root);

    cout<<"\nPrinting tree by preorder traversal:"<<endl;
    preorderTraversal(root);

    cout<<"\nPrinting tree by postorder traversal:"<<endl;
    postorderTraversal(root);
    */

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    //levelOrderTraversal(root);
    //cout<<"Height of tree is: "<<height(root);
    //cout<<"Diameter of tree is:" << diameter(root);
    //cout<<"Diameter of tree is in O(n):" << diameterfast(root).first;
   //cout<<"No. of leaf nodes are: "<<noOfLeafNodes(root);
   //cout<<"Is a Balanced tree?"<<isBalanced(root);
   //cout<<"Is a Balanced tree fast?"<<isBalancedfast(root).first;

    //cout<<"Tree 1 and 2 are identical?"<<isIdentical(root,root1);
/*
    vector<int> k=zigzagTraverse(root);
    for(int i=0;i<k.size();i++) 
        cout<<k[i]<<" ";
    
*/

/*
   vector<int> bound=boundary(root);
   for(int i=0;i<bound.size();i++)
        cout<<bound[i]<<" ";
*/
    /*
    vector<int> vert=verticalOrder(root);
    for(int i=0;i<vert.size();i++)
        cout<<vert[i]<<" ";
    */
   /*
   vector<int> top=topView(root);
   for(int i=0;i<top.size();i++)
        cout<<top[i]<<" ";
*/
/*
    vector<int> bott=bottomView(root);
    for(int i=0;i<bott.size();i++)
        cout<<bott[i]<<" ";
*/

//1 2 5 3 4 -1 -1 -1 -1 7 -1 -1 -1
/*
    vector<int> left1=leftViewRecursive(root);
    for(int i=0;i<left1.size();i++)
        cout<<left1[i]<<" ";
    cout<<endl;
    vector<int> left=leftViewRecursive(root);
    for(int i=0;i<left.size();i++)
        cout<<left[i]<<" ";

    cout<<endl;
    vector<int> right=rightView(root);
    for(int i=0;i<right.size();i++)
        cout<<right[i]<<" ";
*/


// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
/*
    vector<int> dt=diagonalTraversal(root);
    for(int i=0;i<dt.size();i++)
        cout<<dt[i]<<" ";
*/
/*
vector<int> an=boundary(root);
for(int i=0;i<an.size();i++){
    cout<<an[i]<<" ";
}*/


}