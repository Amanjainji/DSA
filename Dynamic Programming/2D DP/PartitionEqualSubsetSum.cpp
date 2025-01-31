#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr[], return true if it can be partitioned into two subsets such that the sum of elements in both parts is the same, otherwise, false.
Note: Each element is present in either the first subset or the second subset, but not in both.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].
*/

/*
Algo:
1)add all elements of array and check if its odd then return false
2)if even then find subset having sum of element = totalSum/2
3)if found return true else false
*/
bool solve(int index,vector<int>& arr,int n,int target){
    //base case
    if(index>=n)
        return 0;
    if(target<0)
        return 0;
    if(target==0)
        return 1;
    
    bool incl=solve(index+1,arr,n,target-arr[index]);
    bool excl=solve(index+1,arr,n,target);

    return incl|excl;
}

bool equalPartition(vector<int>& arr) {
    int total=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        total+=arr[i];
    }

    if(total & 1){  //odd condn
        return 0;
    }
    return solve(0,arr,n,total/2);
}

//Memoization
bool solveMem(int index,vector<int>& arr,int n,int target,vector<vector<int>> &dp){
    //base case
    if(index>=n)
        return 0;
    if(target<0)
        return 0;
    if(target==0)
        return 1;
    
    if(dp[index][target]!=-1)
        return dp[index][target];
    
    bool incl=solveMem(index+1,arr,n,target-arr[index],dp);
    bool excl=solveMem(index+1,arr,n,target,dp);

    return dp[index][target]=incl|excl;
}

bool equalPartitionMem(vector<int>& arr) {
    int total=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        total+=arr[i];
    }

    if(total & 1){  //odd condn
        return 0;
    }
    int target=total/2;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return solveMem(0,arr,n,target,dp);
}

//Tabulation
bool equalPartitionTab(vector<int>& arr) {
    int total=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        total+=arr[i];
    }

    if(total & 1){  //odd condn
        return 0;
    }
    
    vector<vector<int>> dp(n+1,vector<int>((total/2)+1,0));
    //base case analysing
    for(int i=0;i<=n;i++){
        dp[i][0]=1;  // 1 column means target reach
    }

    for(int index=n-1;index>=0;index--){
        for(int target=0;target<=total/2;target++){

            bool incl=0;
            if(target-arr[index]>=0)
                incl=dp[index+1][target-arr[index]];
            
            bool excl=dp[index+1][target];
        dp[index][target]= incl or excl;
        }
    }
    return dp[0][total/2];
}

//Space optimization
bool equalPartitionSO(vector<int>& arr) {
    int total=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        total+=arr[i];
    }

    if(total & 1){  //odd condn
        return 0;
    }
    
    vector<int> curr(total/2+1 ,0);
    vector<int> next(total/2+1 ,0);
    //base case
    curr[0]=1;   //dp[index]
    next[0]=1;   //dp[index+1]

    for(int index=n-1;index>=0;index--){
        for(int target=0;target<=total/2;target++){

            bool incl=0;
            if(target-arr[index]>=0)
                incl=next[target-arr[index]];
            
            bool excl=next[target];
        curr[target]= incl or excl;
        }
        next=curr;
    }
    return next[total/2];
}

int main(){
    vector<int> arr = {1, 5, 11, 5};  //ans=1
    //vector<int> arr = {1, 5, 11, 5,4};   //ans=0
    cout<<equalPartitionSO(arr);
}

