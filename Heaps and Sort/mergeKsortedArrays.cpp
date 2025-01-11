#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        int i;
        int j;

        node(int data,int row,int col){
            this->data=data;
            i=row;
            j=col;
        }
};

class compare{
    public:
        bool operator()(node* a,node *b){
            return a->data>b->data;
        }
};


//merge k sorted arrays - TC (n*k log k)  SC - O(n*k)
vector<int> mergeKsortedArrays(vector<vector<int>> &kArrays ,int k){

    priority_queue<node*,vector<node*>,compare> minHeap;

    //step1: saare array ke first element insert krne hai min heap mein
    for(int i=0;i<k;i++){
        node* tmp=new node(kArrays[i][0],i,0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    //step 2
    while(minHeap.size()>0){ 
        node* tmp=minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int row=tmp->i;
        int col=tmp->j;

        if(col+1<kArrays[row].size()){
            node* next=new node(kArrays[row][col+1],row,col+1);
            minHeap.push(next);
        }
    }

    return ans;

}
