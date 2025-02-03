#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.
*/

int solve(vector<int> &arr,map<pair<int,int>,int> &maxi,int left,int right){
    if(left==right)
        return 0;
    
    int ans=INT_MAX;
    for(int i=left;i<right;i++){
        ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}]+ solve(arr,maxi,left,i)+solve(arr,maxi,i+1,right));
    }
    return ans;
}

int mctFromLeafValues(vector<int>& arr) {
    map<pair<int,int>,int> maxi;  //<index range> --> max_value
    //making pairs from indexes range and assigning max values 
    for(int i=0;i<arr.size();i++){
        maxi[{i,i}]=arr[i];
        for(int j=i+1;j<arr.size();j++){
            maxi[{i,j}]=max(arr[j],max(arr[j],maxi[{i,j-1}]));
        }
    }
    //to calculate internal node and then sum
    return solve(arr,maxi,0,arr.size()-1);
}

//Memoization
int solveMem(vector<int> &arr,map<pair<int,int>,int> &maxi,int left,int right,vector<vector<int>> &dp){
    if(left==right)
        return 0;
    
    if(dp[left][right]!=-1)
        return dp[left][right];
    int ans=INT_MAX;
    for(int i=left;i<right;i++){
        ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}]+ solveMem(arr,maxi,left,i,dp)+solveMem(arr,maxi,i+1,right,dp));
    }
    return dp[left][right]=ans;
}

int mctFromLeafValuesMem(vector<int>& arr) {
    map<pair<int,int>,int> maxi;  //<index range> --> max_value
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //making pairs from indexes range and assigning max values 
    for(int i=0;i<arr.size();i++){
        maxi[{i,i}]=arr[i];
        for(int j=i+1;j<arr.size();j++){
            maxi[{i,j}]=max(arr[j],max(arr[j],maxi[{i,j-1}]));
        }
    }
    //to calculate internal node and then sum
    return solveMem(arr,maxi,0,arr.size()-1,dp);
}

//Tabulation
int mctFromLeafValuesTab(vector<int>& arr) {
    map<pair<int,int>,int> maxi;  //<index range> --> max_value
    int n=arr.size();
    //making pairs from indexes range and assigning max values 
    //initialize map
    for(int i=0;i<n;i++){
        maxi[{i,i}]=arr[i];
        for(int j=i+1;j<arr.size();j++){
            maxi[{i,j}]=max(arr[j],max(arr[j],maxi[{i,j-1}]));
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int left=n-1;left>=0;left--){
        for(int right=left;right<=n;right++){
            if(left==right)
                continue;
            else{
                int ans=INT_MAX;
                for(int i=left;i<right;i++){
                    ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}]+ dp[left][i]+dp[i+1][right]);
                }
                dp[left][right]=ans;
            }  
        }
    }
    return dp[0][n-1]; 
}

int main(){
    vector<int> arr={6,2,4};        
    cout<<mctFromLeafValuesTab(arr);  //32
}