#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> ans;
    vector<int> arr={1,2,3};
    int n=3;
    int x=(1<<n);   //2 powers n
    for(int num=0;num<x;num++){
        vector<int> subset;
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                subset.push_back(arr[i]);
            }
        }
        ans.push_back(subset);
    }

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}