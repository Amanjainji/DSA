/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
*/

#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(string &s1, string &s2,int i,int j){
    int cost=0;
    if(i==s1.size() || j==s2.size()){
        //return the sum of ascii of remaining char of remaining string
        for(int x=i;x<s1.size();x++)
            cost+=s1[x];
        for(int x=j;x<s2.size();x++)
            cost+=s2[x];
    }
    //same character
    else if(s1[i]==s2[j]){
        cost=solve(s1,s2,i+1,j+1);
    }
    //not same
    else{
        int cost1=s1[i]+ solve(s1,s2,i+1,j);
        int cost2=s2[j]+solve(s1,s2,i,j+1);
        cost=min(cost1,cost2);
    }

    return cost;
}
int minimumDeleteSum(string s1, string s2) {
    return solve(s1,s2,0,0);
}

//Memoization
int solveMem(string &s1, string &s2,int i,int j,vector<vector<int>> &dp){
    int cost=0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==s1.size() || j==s2.size()){
        //return the sum of ascii of remaining char of remaining string
        for(int x=i;x<s1.size();x++)
            cost+=s1[x];
        for(int x=j;x<s2.size();x++)
            cost+=s2[x];
    }
    //same character
    else if(s1[i]==s2[j]){
        cost=solveMem(s1,s2,i+1,j+1,dp);
    }
    //not same
    else{
        int cost1=s1[i]+ solveMem(s1,s2,i+1,j,dp);
        int cost2=s2[j]+solveMem(s1,s2,i,j+1,dp);
        cost=min(cost1,cost2);
    }

    return dp[i][j]=cost;
}
int minimumDeleteSumMem(string s1, string s2) {
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    return solveMem(s1,s2,0,0,dp);
}

//Tabulation
int minimumDeleteSumTab(string s1, string s2) {
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    //base case handling
    for(int i=s1.size()-1;i>=0;i--){
        dp[i][s2.size()]=s1[i]+dp[i+1][s2.size()];
    }
    for(int i=s2.size()-1;i>=0;i--){
        dp[s1.size()][i]=s2[i]+dp[s1.size()][i+1];
    }

    //main code
    for(int i=s1.size()-1;i>=0;i--){
        for(int j=s2.size()-1;j>=0;j--){
            int cost=0;
            //same character
            if(s1[i]==s2[j]){
                cost=dp[i+1][j+1];
            }
            //not same
            else{
                int cost1=s1[i]+ dp[i+1][j];
                int cost2=s2[j]+dp[i][j+1];
                cost=min(cost1,cost2);
            }
            dp[i][j]=cost;
        }
    }

    return dp[0][0];
}

int main(){
    string s1="eat" ,s2="sea";
    cout<<minimumDeleteSumTab(s1,s2);
}