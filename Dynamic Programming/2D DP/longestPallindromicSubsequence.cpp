#include<bits/stdc++.h>
using namespace std;

//similar to longer common subsequence ,just reverse string as second input

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/

int longestCommonSubsequenceSO(string &a, string &b) {
    vector<int> curr(b.length()+1,0);
    vector<int> next(b.length()+1,0);
    for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
            int ans=0;
            if(a[i]==b[j]){
                ans=1+next[j+1];
            }
            else{
                ans=max(next[j],curr[j+1]);
            }
            curr[j]=ans;
        }
        next=curr;
    }
    return next[0];
}

int longestPalindromeSubseq(string s) {
      string revStr=s;
      reverse(revStr.begin(),revStr.end());
      return longestCommonSubsequenceSO(s,revStr);  
}