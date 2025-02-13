/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

#include<bits/stdc++.h>
using namespace std;

bool solve(string &s,vector<string> &wordDict,int start,unordered_map<string,bool> &mpp){
    if(start==s.size()) return true;

    //one case,make a string
    string word="";
    bool flag=false;
    for(int i=start;i<s.size();i++){
        word+=s[i];
        if(mpp[word]){
            flag=flag||solve(s,wordDict,i+1,mpp);
        }
    }
    return flag;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,bool> mpp;
    for(auto i:wordDict){
        mpp[i]=true;
    }
    return solve(s,wordDict,0,mpp);
}

//memoization
bool solveMem(string &s,vector<string> &wordDict,int start,unordered_map<string,bool> &mpp,vector<int> &dp){
    if(start==s.size()) return true;

    if(dp[start]!=-1)
        return dp[start];
    //one case,make a string
    string word="";
    bool flag=false;
    for(int i=start;i<s.size();i++){
        word+=s[i];
        if(mpp[word]){
            flag=flag||solveMem(s,wordDict,i+1,mpp,dp);
        }
    }
    return dp[start]=flag;
}
bool wordBreakmem(string s, vector<string>& wordDict) {
    unordered_map<string,bool> mpp;
    vector<int> dp(s.size(),-1);
    for(auto i:wordDict){
        mpp[i]=true;
    }
    return solveMem(s,wordDict,0,mpp,dp);
}

//tabulation
bool solveTab(string &s,vector<string> &wordDict,unordered_map<string,bool> &mpp,vector<int> &dp){
    //handling base case
    dp[s.size()]=1;
    for(int start=s.size()-1;start>=0;start--){
        string word="";
        bool flag=false;
        for(int i=start;i<s.size();i++){
            word+=s[i];
            if(mpp[word]){
                flag=flag||dp[i+1];
            }
        }
        dp[start]=flag;
    }

    return dp[0]; 
}
bool wordBreakTab(string s, vector<string>& wordDict) {
    unordered_map<string,bool> mpp;
    vector<int> dp(s.size()+1,0);
    for(auto i:wordDict){
        mpp[i]=true;
    }
    return solveTab(s,wordDict,mpp,dp);
}

int main(){
    string s = "applepenapple"; 
    vector<string> wordDict = {"apple","pen"};
    string s1 = "catsandog";
    vector<string>wordDict1 = {"cats","dog","sand","and","cat"};
    cout<<wordBreakTab(s,wordDict);
}