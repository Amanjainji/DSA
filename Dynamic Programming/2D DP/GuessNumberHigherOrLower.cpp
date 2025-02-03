#include<bits/stdc++.h>
using namespace std;

/*
We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.
*/
int solve(int start,int end){
    //base case
    if(start>=end){
        return 0;
    }

    int maxi=INT_MAX;
    for(int i=start;i<=end;i++){
        maxi=min(maxi,i+max(solve(start,i-1),solve(i+1,end)));
    }
    return maxi;
}

int getMoneyAmount(int n) {
    return solve(1,n);
}

//Memoization  TC- O(N^3)
int solveMem(int start,int end,vector<vector<int>> &dp){
    //base case
    if(start>=end){
        return 0;
    }

    if(dp[start][end]!=-1){
        return dp[start][end];
    }

    int maxi=INT_MAX;
    for(int i=start;i<=end;i++){
        maxi=min(maxi,i+max(solveMem(start,i-1,dp),solveMem(i+1,end,dp)));
    }
    //har ek guess ke liye jo minimum value ban rhi hai use dp mein daal do
    return dp[start][end]=maxi;
}

int getMoneyAmountMem(int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solveMem(1,n,dp);
}

//dp[i][j] = minimum amount of money to win for range i to j

//Tabulation  TC- O(N^3)
int getMoneyAmountTab(int n) {
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    //when start and end are equal , dp[start][end]=0
    for(int start=n;start>=1;start--){
        for(int end=start;end<=n;end++){
            if(start==end){
                continue;
            }
            else{
                int maxi=INT_MAX;
                for(int i=start;i<=end;i++){
                    maxi=min(maxi,i+max(dp[start][i-1],dp[i+1][end]));
                }
                //visualize
                //cout<<"("<<start<<","<<end<<")"<<"-->"<<maxi<<endl;
                dp[start][end]=maxi;
            }
        }
    }
    return dp[1][n];
}

int main(){
    cout<<"final ans "<<getMoneyAmountTab(10);
}