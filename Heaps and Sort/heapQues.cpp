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

//ques 1: Kth minimum element
int kthSmallest(vector<int> arr,int k){
    priority_queue<int> pq;

    //step1 - push first k element of array in max heap
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    //step2 - for remaining elements ,check if it less than top ,remove top and push that element in heap
    for(int i=k;i<arr.size();i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //step3 - return top
    return pq.top();
}

//ques 2 - Kth Largest element
int kthLargest(vector<int> arr,int k){
    priority_queue<int,vector<int>,greater<int>> pq;

    //step1 - push first k element of array in min heap
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    //step2 - for remaining elements ,check if it greater than top ,remove top and push that element in heap
    for(int i=k;i<arr.size();i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //step3 - return top
    return pq.top();
}

//ques 3 - is Binary Tree heap?
/*

Algorithm:
1 - check if it is a CBT or not
2 - check if it follows the property of max heap for three conditions, leaf node, left child only and both child.
3 - return true if both are true else false.

*/
int countNodes(node* root){
    if(root==NULL){
        return 0;
    }
    int ans= 1+ countNodes(root->left)+countNodes(root->right);
    return ans;
}

bool isCBT(node* root,int index,int count){
    if(root==NULL){
        return true;
    }
    if(index>=count){
        return false;
    }

    else{
        bool left=isCBT(root->left,2*index+1,count);
        bool right=isCBT(root->right,2*index+2,count);
        return (left && right);
    }
}

bool isMaxOrder(node* root){  //assuming already CBT
    //leaf node
    if(root->left==NULL && root->right ==NULL){
        return true;
    }

    //only left child
    if(root->right==NULL){
        return (root->data >root->left ->data);
    }
    else{
        bool left= isMaxOrder(root->left);
        bool right= isMaxOrder(root->right);
        if((root->data > root->left->data && root->data > root->right->data) && left && right ){
            return true;
        }
        else{
            return false;
        }
    }
}
bool isHeap(node* root){
    int index=0;
    int totalCount=countNodes(root);

    if(isCBT(root,index,totalCount) && isMaxOrder(root)){
        return true;
    }
    else{
        return false;
    }
}

//ques 4- merge 2 binary maxHeap

void heapifyMax(vector<int> &arr,int n,int i){  //heapify 
    int largest= i;
    int left= 2*i+1;      //arr start from 1 index 
    int right= 2*i+2;        

    if(left < n && arr[largest]< arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest !=i){
        swap(arr[i],arr[largest]);
        heapifyMax(arr,n,largest);
    }
}

vector<int> merge2binaryHeap(vector<int> heap1,vector<int> heap2){
    //step 1- merge both arrays
    vector<int> ans;
    for(auto i:heap1){
        ans.push_back(i);
    }
    for(auto i:heap2){
        ans.push_back(i);
    }
    //step 2 - build heap from merged array
    int n=ans.size();
    for(int i=n/2-1;i>=0;i--){  //ignoring the leaf
        heapifyMax(ans,n,i);
    }
    return ans;
}

//ques 5- minimum cost of ropes

//algorithm
// step 1: create a min heap for all the elements in array
//step 2: pop first 2 element and calculate sum and add it to cost and push sum back in heap till size>1
// return final-sum
long long minCost(long long arr[],long long n){
    //create a min heap
    priority_queue<long long,vector<long long> ,greater<long long>> pq;

    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    long long cost=0;
    while(pq.size()>1){
        long long a=pq.top();
        pq.pop();

        long long b=pq.top();
        pq.pop();

        long long sum= a+b;
        cost+=sum;

        pq.push(sum);   
    }
    return cost;
}


//ques 6 - Kth largest subarray sum
//approach 1 - TC O(n^2 log n)  SC - O(n^2)
 
//brute force algo:
//use nested loops to collect sum of all subarrays , sort the resultant array and return the kth largest from last
int getKthLargestSubarray(vector<int> &arr,int k){
    vector<int> sumStore;
    int n=arr.size();

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(),sumStore.end());

    return sumStore[sumStore.size()-k];
} 

//approach 2 - using min heap SC - O(k)  TC -O(n^2 log k)
int getKthLargestSubarray2(vector<int> &arr,int k){
    priority_queue<int,vector<int>,greater<int>> mini;
    int n=arr.size();

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }
            else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
} 



int main(){
    vector<int> arr={77,50,40,20,15};
    //cout<<kthSmallest(arr,4)<<endl;
    //cout<<kthLargest(arr,4)<<endl;
    vector<int> arr2={70,60,44,22,5};
    /*
    vector<int> ans=merge2binaryHeap(arr,arr2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }*/

    cout<< getKthLargestSubarray(arr2,4);
}