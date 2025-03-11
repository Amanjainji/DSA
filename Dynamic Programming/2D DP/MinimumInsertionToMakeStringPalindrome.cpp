#include<bits/stdc++.h>
using namespace std;

//leetcode 1312

/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
Example 1:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
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

int minInsertions(string s) {
    return s.length()-longestPalindromeSubseq(s);
}

int main(){
    string s="mbadm";
    cout<<minInsertions(s);
}
    
