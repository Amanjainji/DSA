#include<bits/stdc++.h>
#include<queue>
using namespace std;

/*
Input: n = 5, k = 3, arr[][] = [[4, 7, 9, 12, 15], [0, 8, 10, 14, 20], [6, 12, 16, 30, 50]]
Output: [6, 8]
Explanation: Smallest range is formed by  number 7 from the first list, 8 from second list and 6 from the third list.
*/
class node{
    public:
    int data;
    int row;
    int col;

    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
}; 

class compare{
    public:
        bool operator()(node* a,node *b ){
            return a->data>b->data;
        } 
};
int kSorted(vector<vector<int>> &a,int k,int n){
    int mini= INT_MAX,maxi=INT_MIN;
    priority_queue<node*,vector<node*>,compare> minHeap;
    
    //step 1- create a min heap for starting element of each list and tracking mini/maxi value
    for(int i=0;i<k;i++){
        int element =a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minHeap.push(new node(element,i,0));
    }

    int start=mini,end=maxi;

    //step 2 -process ranges
    while(!minHeap.empty()){

        //mini fetch
        node* temp=minHeap.top();
        minHeap.pop();

        //mini data
        mini=temp->data;

        //range or answer updation
        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }

        //next element exists then put in heap
        if(temp->col+1<n){
            maxi=max(maxi,a[temp->row][temp->col +1]); 
            minHeap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
        //else break
        }else
            break;
    }

    //step 3- return range
    return (end-start+1);
}

int main(){
    vector<vector<int>> v1={{1,10,11},{2,3,20},{5,6,12}};
    cout<<"Range:"<<kSorted(v1,3,3); //[1,5]
}