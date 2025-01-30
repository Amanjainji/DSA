#include<bits/stdc++.h>
using namespace std;

/*
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.
*/

long long solve(int dice,int faces,int target){
    //base case
    if(target<0)
        return 0;
    if(dice== 0 && target!=0)
        return 0;
    if(target==0 && dice!=0)
        return 0;
    if(dice==0 && target==0)
        return 1;
    
    long long ans=0;
    for(int i=1;i<=faces;i++){
        ans=ans+solve(dice-1,faces,target-i);
    }
    return ans;
}

long long noOfWays(int M,int N,int X){
    return solve(N,M,X);
}

//Top Down approach
long long solveMem(int dice,int faces,int target,vector<vector<long long>> &dp){
    //base case
    if(target<0)
        return 0;
    if(dice== 0 && target!=0)
        return 0;
    if(target==0 && dice!=0)
        return 0;
    if(dice==0 && target==0)
        return 1;
    
    if(dp[dice][target]!=-1){
        return dp[dice][target];
    }
    long long ans=0;
    for(int i=1;i<=faces;i++){
        ans=ans+solveMem(dice-1,faces,target-i,dp);
    }
    return dp[dice][target]=ans;
}

long long noOfWaysMem(int M,int N,int X){
    vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
    return solveMem(N,M,X,dp);
}

//Tabulation
long long noOfWaysTab(int f,int d,int t){
    vector<vector<long long>> dp(d+1,vector<long long>(t+1,0));
    //after analysing base case
    dp[0][0]=1;
    for(int dice=1;dice<=d;dice++){
        for(int target=1;target<=t;target++){
            long long ans=0;
            for(int i=1;i<=f;i++){
                if(target-i >=0)
                    ans=ans+dp[dice-1][target-i];
            }
            dp[dice][target]=ans;
        }
    }
    return dp[d][t];
}

//space optimization
long long noOfWaysSO(int f,int d,int t){
    vector<long long> prev(t+1,0);  //dp[dice-1]
    vector<long long> curr(t+1,0);  //dp[dice]
    //after analysing base case
    prev[0]=1;
    for(int dice=1;dice<=d;dice++){
        for(int target=1;target<=t;target++){
            long long ans=0;
            for(int i=1;i<=f;i++){
                if(target-i >=0)
                    ans=ans+prev[target-i];
            }
            curr[target]=ans;
        }
        prev=curr;
    }
    return prev[t];
}

int main(){
    cout<<noOfWaysSO(6,3,12);
}