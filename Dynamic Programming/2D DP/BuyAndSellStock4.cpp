/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 
*/

#include<bits/stdc++.h>
using namespace std;

//using atmost 2 limit method , Buy and Sell Stock III
//Space optimized
int maxProfitSOlimit(vector<int>& prices,int k) {
    int limit=k,n=prices.size();
    vector<vector<int>> curr(2,vector<int>(k+1,0));  //change
    vector<vector<int>> next(2,vector<int>(k+1,0));  //change
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=k;limit++){  //change
                int profit=0;
                if(buy){
                    int buyKaro=-prices[index]+next[0][limit];
                    int skipKaro=0+next[1][limit];
                    profit=max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro=prices[index]+next[1][limit-1];
                    int skipKaro=0+next[0][limit];
                    profit=max(sellKaro,skipKaro);
                }
                curr[buy][limit]=profit;
            }
        }
        next=curr;
    }
    return next[1][k];  //change
}

//operationNo or transaction method
//recursive
int solve(vector<int>& prices,int operationNo,int index,int k){
    int n=prices.size();
    if(index==n)
        return 0;
    if(operationNo==2*k)
        return 0;
    
    int profit=0;
    if(operationNo%2==0){
        int buyKaro=-prices[index]+solve(prices,operationNo+1,index+1,k);
        int skipKaro=0+solve(prices,operationNo,index+1,k);
        profit=max(buyKaro,skipKaro);
    }
    else{
        int sellKaro=prices[index]+solve(prices,operationNo+1,index+1,k);
        int skipKaro=0+solve(prices,operationNo,index+1,k);
        profit=max(sellKaro,skipKaro);
    }
    return profit;
}
int maxProfit(vector<int>& prices,int k) {
    return solve(prices,0,0,k);
}

//recursive + memoization
int solveMem(vector<int>& prices,int operationNo,int index,int k,vector<vector<int>> &dp){
    int n=prices.size();
    if(index==n)
        return 0;
    if(operationNo==2*k)
        return 0;
    
    if(dp[index][operationNo]!=-1){
        return dp[index][operationNo];
    }
    int profit=0;
    if(operationNo%2==0){
        int buyKaro=-prices[index]+solveMem(prices,operationNo+1,index+1,k,dp);
        int skipKaro=0+solveMem(prices,operationNo,index+1,k,dp);
        profit=max(buyKaro,skipKaro);
    }
    else{
        int sellKaro=prices[index]+solveMem(prices,operationNo+1,index+1,k,dp);
        int skipKaro=0+solveMem(prices,operationNo,index+1,k,dp);
        profit=max(sellKaro,skipKaro);
    }
    return dp[index][operationNo]=profit;
}
int maxProfitMem(vector<int>& prices,int k) {
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2*k,-1));
    return solveMem(prices,0,0,k,dp);
}

//Tabulation
int maxProfitTab(vector<int>& prices,int k) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    for(int index=n-1;index>=0;index--){
        for(int operationNo=0;operationNo<2*k;operationNo++){
            int profit=0;
            if(operationNo%2==0){
                int buyKaro=-prices[index]+dp[index+1][operationNo+1];
                int skipKaro=0+dp[index+1][operationNo];
                profit=max(buyKaro,skipKaro);
            }
            else{
                int sellKaro=prices[index]+dp[index+1][operationNo+1];
                int skipKaro=0+dp[index+1][operationNo];
                profit=max(sellKaro,skipKaro);
            }
            dp[index][operationNo]=profit;
        }
    }
    return dp[0][0];
}

//space optimization
int maxProfitSO(vector<int>& prices,int k) {
    int n=prices.size();
    //vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    vector<int> curr(2*k+1,0);
    vector<int> next(2*k+1,0);
    for(int index=n-1;index>=0;index--){
        for(int operationNo=0;operationNo<2*k;operationNo++){
            int profit=0;
            if(operationNo%2==0){
                int buyKaro=-prices[index]+next[operationNo+1];
                int skipKaro=0+next[operationNo];
                profit=max(buyKaro,skipKaro);
            }
            else{
                int sellKaro=prices[index]+next[operationNo+1];
                int skipKaro=0+next[operationNo];
                profit=max(sellKaro,skipKaro);
            }
            curr[operationNo]=profit;
        }
        next=curr;
    }
    return next[0];
}

int main(){
    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};
    cout<<maxProfitSO(prices,k);
}
