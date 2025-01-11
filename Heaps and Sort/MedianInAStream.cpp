#include<bits/stdc++.h>
using namespace std;
int signum(int a,int b){
    if(a==b)
        return 0;
    else if(a>b)
        return 1;  
    else
        return -1;
}

void callMedian(priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini,int &median,int element){
    switch(signum(maxi.size(),mini.size())){
        case 0: if(element>median){  //equal as 0(even)
                    mini.push(element);
                    median=mini.top();  //after adding become odd
                }
                else{
                    maxi.push(element);
                    median=maxi.top(); //after adding become odd
                }
                break;
        
        case 1: if(element>median){  //unequal as 1(odd) (maxi.size = n then mini.size = n-1)
                    mini.push(element);
                    median=(maxi.top()+mini.top())/2;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median=(maxi.top()+mini.top())/2;
                }
                break;
        
        case -1: if(element>median){  //unequal as 1(odd) (maxi.size = n-1 then mini.size = n)
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median=(maxi.top()+mini.top())/2;
                }
                else{
                    maxi.push(element);
                    median=(maxi.top()+mini.top())/2;
                }
                break;
    }
}

//TC - O(N log N)
vector<int> findMedian(vector<int> &arr,int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int median=0;

    for(int i=0;i<n;i++){
        int element=arr[i];
        callMedian(maxHeap,minHeap,median,element);
        ans.push_back(median);
    }

    return ans;
}
int main(){
    vector<int> arr={10,25,5,6,7,8,9};
    vector<int> v1=findMedian(arr,arr.size());
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}