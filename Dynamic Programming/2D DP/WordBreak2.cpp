#include<bits/stdc++.h>
using namespace std;

/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
*/

vector<string> solve(string &s,unordered_map<string,bool> &dict,int i){
    if(i==s.size()) return {""};
    vector<string> ans;
    string word;
    for(int j=i;j<s.size();++j){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end()) continue;

        //founded a valid word , baaki recursion dekh lega
        auto right=solve(s,dict,j+1);
        for(auto eachRightPart:right){
            string endPart;
            if(eachRightPart.size()>0) 
                endPart=" "+eachRightPart;
            ans.push_back(word + endPart);
        }
    }
    return ans;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,bool> dict;
    for(auto i:wordDict){
        dict[i]=true;
    }
    return solve(s,dict,0);  
}

//Memoization
unordered_map<int,vector<string>> dp;
vector<string> solveMem(string &s,unordered_map<string,bool> &dict,int i){
    if(i==s.size()) return {""};
    vector<string> ans;
    string word;

    if(dp.find(i)!=dp.end()) return dp[i];
    for(int j=i;j<s.size();++j){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end()) continue;

        //founded a valid word , baaki recursion dekh lega
        auto right=solveMem(s,dict,j+1);
        for(auto eachRightPart:right){
            string endPart;
            if(eachRightPart.size()>0) 
                endPart=" "+eachRightPart;
            ans.push_back(word + endPart);
        }
    }
    return dp[i]=ans;
}

vector<string> wordBreakMem(string s, vector<string>& wordDict) {
    unordered_map<string,bool> dict;
    for(auto i:wordDict){
        dict[i]=true;
    }
    return solveMem(s,dict,0);  
}

int main(){
    string s = "pineapplepenapple";
    vector<string> wordDict = {"apple","pen","applepen","pine","pineapple"};
    vector<string> k=wordBreak(s,wordDict);
    for(auto i:k){
        cout<<i<<endl;
    }
}