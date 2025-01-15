#include<bits/stdc++.h>
using namespace std;

//Recursion
int solve(vector<int> &nums,int n){
    //base case
    if(n<0)
        return 0;
    
    if(n==0)
        return nums[0];

    int incl=solve(nums,n-2)+ nums[n];
    int excl=solve(nums,n-1);

    return max(incl,excl);
}
int maxNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int ans=solve(nums,n-1);
    return ans;
}

//Top Down Approach
int solveMem(vector<int> &nums,int n,vector<int> &dp){
    //base case
    if(n<0)
        return 0;
    
    if(n==0)
        return nums[0];
    
    int incl=solve(nums,n-2)+ nums[n];
    int excl=solve(nums,n-1);

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]= max(incl,excl);
    return dp[n]; 
}
int maxNonAdjacentSum2(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return solveMem(nums,n-1,dp);
}

//bottom up Approach
int solveTab(vector<int> &nums,int n,vector<int> &dp){
    //base case
    if(n<0)
        return 0;
    
    if(n==0)
        return nums[0];
    
    int incl=solve(nums,n-2)+ nums[n];
    int excl=solve(nums,n-1);

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]= max(incl,excl);
    return dp[n]; 
}
int maxNonAdjacentSum3(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,0);

    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int incl=0;
        if(i-2>0)
            incl=dp[i-2]+nums[i];
        int excl=dp[n-1]+0;

        dp[i]=max(incl,excl);
    }

    return dp[n-1];
}
int main(){
    vector<int> arr={9,9,8,4};
    cout<<maxNonAdjacentSum2(arr);
}