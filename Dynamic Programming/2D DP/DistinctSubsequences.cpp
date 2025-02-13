#include<bits/stdc++.h>
using namespace std;
/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
ra(bb)bit
rab(bb)it
ra(b)b(b)it
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
*/

//recursive
int solve(string &s,string &t, int i,int j){
    //base case
    if(j==t.size())
        return 1;
    if(i==s.size())  // && j!=t.size
        return 0;

    //algorithm - if same then increment both i and j and take a case by excluding that character incrementing only i
    int ans=0;
    if(s[i]==t[j])
        ans+=solve(s,t,i+1,j+1);
    ans+=solve(s,t,i+1,j);
    return ans;
}
int numDistinct(string s, string t) {
    return solve(s,t,0,0);
}

//recursive + memoization
int solveMem(string &s,string &t, int i,int j,vector<vector<int>> &dp){
    //base case
    if(j==t.size())
        return 1;
    if(i==s.size())  // && j!=t.size
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    //algorithm - if same then increment both i and j and take a case by excluding that character incrementing only i
    int ans=0;
    if(s[i]==t[j])
        ans+=solveMem(s,t,i+1,j+1,dp);
    ans+=solveMem(s,t,i+1,j,dp);
    return dp[i][j]=ans;
}
int numDistinctMem(string s, string t) {
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
    return solveMem(s,t,0,0,dp);
}

//tabulation
int solveTab(string &s,string &t){
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
    //base case
    for(int i=0;i<=s.size();i++){
        dp[i][t.size()]=1;
    }
    //algorithm - if same then increment both i and j and take a case by excluding that character incrementing only i
    for(int i=s.size()-1;i>=0;i--){
        for(int j=t.size()-1;j>=0;j--){
            long long ans=0;
            if(s[i]==t[j])
                ans+= dp[i+1][j+1]; //solveMem(s,t,i+1,j+1,dp);
            ans+=dp[i+1][j];
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}
int numDistinctTab(string s, string t) {
    return solveTab(s,t);
}

//space optimization
int solveSO(string &s,string &t){
    //vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
    vector<int> curr(t.size()+1,0);
    vector<int> next(t.size()+1,0);
    
    //algorithm - if same then increment both i and j and take a case by excluding that character incrementing only i
    for(int i=s.size()-1;i>=0;i--){
        for(int j=t.size()-1;j>=0;j--){
            //catch
            next[t.size()]=1;
            
            long long ans=0;
            if(s[i]==t[j])
                ans+= next[j+1]; //solveMem(s,t,i+1,j+1,dp);
            ans+=next[j];
            curr[j]=ans;
        }
        next=curr;
    }
    return next[0];
}
int numDistinctSO(string s, string t) {
    return solveSO(s,t);
}
int main(){
    string s = "rabbbit", t = "rabbit";
    cout<<numDistinctSO(s,t);
}