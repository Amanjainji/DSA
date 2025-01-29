#include<bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,pair<int,int>> mpp;
        for(int i=0;i<arr.size();i++){
            if(mpp.find(arr[i])==mpp.end()){
                mpp[arr[i]]={i,1};
            }
            else{
                mpp[arr[i]].second++;
            }
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:mpp){
            if(i.second.second==1){
                pq.push(i.second.first);
            }
        }
        while(!pq.empty() && k>1){
            pq.pop();
            k--;
        } 

        if(pq.empty() && k>0){
            return "";
        }
        return arr[pq.top()];
    }

int main(){
    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2;
    cout<<kthDistinct(arr,2);
}