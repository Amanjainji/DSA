/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/
#include<bits/stdc++.h>
using namespace std;

//recursive
int solve(vector<int>& prices,int buy,int index,int limit){
    int n=prices.size();
    if(index>=n)
        return 0;
    if(limit==0)
        return 0;
    
    int profit=0;
    if(buy){
        int buyKaro=-prices[index]+solve(prices,0,index+1,limit);
        int skipKaro=0+solve(prices,1,index+1,limit);
        profit=max(buyKaro,skipKaro);
    }
    else{
        int sellKaro=prices[index]+solve(prices,1,index+1,limit-1);
        int skipKaro=0+solve(prices,0,index+1,limit);
        profit=max(sellKaro,skipKaro);
    }
    return profit;
}
int maxProfit(vector<int>& prices) {
    int limit=2;
    return solve(prices,1,0,limit);
}

//recursive + memoization
int solveMem(vector<int>& prices,int buy,int index,int limit,vector<vector<vector<int>>> &dp){
    int n=prices.size();
    if(index>=n)
        return 0;
    if(limit==0)
        return 0;
    
    if(dp[index][buy][limit]!=-1)
        return dp[index][buy][limit];
    int profit=0;
    if(buy){
        int buyKaro=-prices[index]+solveMem(prices,0,index+1,limit,dp);
        int skipKaro=0+solveMem(prices,1,index+1,limit,dp);
        profit=max(buyKaro,skipKaro);
    }
    else{
        int sellKaro=prices[index]+solveMem(prices,1,index+1,limit-1,dp);
        int skipKaro=0+solveMem(prices,0,index+1,limit,dp);
        profit=max(sellKaro,skipKaro);
    }
    return dp[index][buy][limit]=profit;
}
int maxProfitMem(vector<int>& prices) {
    int limit=2,n=prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solveMem(prices,1,0,limit,dp);
}

//Tabulation
//recursive + memoization
int maxProfitTab(vector<int>& prices) {
    int limit=2,n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=2;limit++){
                int profit=0;
                if(buy){
                    int buyKaro=-prices[index]+dp[index+1][0][limit];
                    int skipKaro=0+dp[index+1][1][limit];
                    profit=max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro=prices[index]+dp[index+1][1][limit-1];;
                    int skipKaro=0+dp[index+1][0][limit];;
                    profit=max(sellKaro,skipKaro);
                }
                dp[index][buy][limit]=profit;
            }
        }
    }
    return dp[0][1][2];
}

//Space optimization
int maxProfitSO(vector<int>& prices) {
    int limit=2,n=prices.size();
    vector<vector<int>> curr(2,vector<int>(3,0));
    vector<vector<int>> next(2,vector<int>(3,0));
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=2;limit++){
                int profit=0;
                if(buy){
                    int buyKaro=-prices[index]+next[0][limit];
                    int skipKaro=0+next[1][limit];
                    profit=max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro=prices[index]+next[1][limit-1];;
                    int skipKaro=0+next[0][limit];;
                    profit=max(sellKaro,skipKaro);
                }
                curr[buy][limit]=profit;
            }
        }
        next=curr;
    }
    return next[1][2];
}

//diffrent type of solution
int maxProfit1(vector<int>& prices) {
    int sellTwo = 0;
    int holdTwo = INT_MIN;
    int sellOne = 0;
    int holdOne = INT_MIN;

    for (const int price : prices) {
      sellTwo = max(sellTwo, holdTwo + price);
      holdTwo = max(holdTwo, sellOne - price);
      sellOne = max(sellOne, holdOne + price);
      holdOne = max(holdOne, -price);
    }

    return sellTwo;
}
int main(){
    vector<int> p={3,3,5,0,0,3,1,4};
    cout<<maxProfitSO(p);
}

