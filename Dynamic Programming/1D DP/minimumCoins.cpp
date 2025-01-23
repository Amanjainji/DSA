#include<bits/stdc++.h>
using namespace std;

//Approach 1: Recursively (leads to TLE)
int solveRec(vector<int> &nums,int x){
    //base case
    if(x==0)
        return 0;

    if(x<0)
        return INT_MAX;
    
    int mini=INT_MAX;
    for(int i=0; i<nums.size();i++){
        int ans=solveRec(nums,x-nums[i]);
        if(ans!=INT_MAX)
            mini=min(mini,1+ans);
    }

    return mini;
}

int minimumCoinsRec(vector<int> &nums,int x){
    int ans=solveRec(nums,x);
    if(ans==INT_MAX)
        return -1;
    return ans;
}

//TC - O(x*n) SC - O(x)
//Approach 2: Top-Down Approach
int solveMem(vector<int> &nums,int x,vector<int> &dp){
    //base case
    if(x==0)
        return 0;

    if(x<0)
        return INT_MAX;
    //Memoization
    if(dp[x]!=-1){
        return dp[x];
    }
    int mini=INT_MAX;
    for(int i=0; i<nums.size();i++){
        int ans=solveRec(nums,x-nums[i]);
        if(ans!=INT_MAX)
            mini=min(mini,1+ans);
    }
    dp[x]=mini;
    return mini;
}

int minimumCoinsMem(vector<int> &nums,int x){
    vector<int> dp(x+1,-1);
    int ans=solveMem(nums,x,dp);
    if(ans==INT_MAX)
        return -1;
    return ans;
}


//TC - O(x*n) SC - O(x)
//Approach 3: Bottom-Up Approach
//Tabulation technique
int minimumCoinsTab(vector<int> &nums,int x){
    vector<int> dp(x+1,INT_MAX);
    //base case
    dp[0]=0;
    
    for(int i=1; i<=x;i++){
        //trying to solve for every amount of figure from 1 to x
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX)
                dp[i]=min(dp[i],1+dp[i-nums[j]]);
        }
    }
    if(dp[x]==INT_MAX)
        return -1;
    return dp[x]; 
}


int main(){
    vector<int> coins={1,2,5};
    cout<<minimumCoinsTab(coins,11);
}