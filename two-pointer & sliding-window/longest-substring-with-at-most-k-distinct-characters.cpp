#include<bits/stdc++.h>
using namespace std;

//brute force   TC - O(N^2)
int longestSubstring(string s,int k){
    int n=s.length();
    int ans=0;
    unordered_map<char,int> mpp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            if(mpp.size()<=k){
                ans=max(ans,j-i+1);
            }
            else    
                break;
        }
        mpp.clear();
    }
    return ans;
}

//two pointers - TC - O(2N)
int longestSubstring2(string s,int k){
    int n=s.length();
    int ans=0;
    unordered_map<char,int> count;
    int l=0,r=0;
    while(r<n){
        count[s[r]]++;
        while(count.size()>k){
            count[s[l]]--;
            if(count[s[l]]==0)
                count.erase(s[l]);
            l++;
        }

        ans=max(ans,r-l+1);
        r++;
    }
    return ans;
}

// sliding window   TC - O(N)
int longestSubstring3(string s,int k){
    int n=s.length();
    int ans=0;
    unordered_map<char,int> count;
    int l=0,r=0;
    while(r<n){
        count[s[r]]++;
        if(count.size()>k){
            count[s[l]]--;
            if(count[s[l]]==0)
                count.erase(s[l]);
            l++;
        }
        if(count.size()<=k)
            ans=max(ans,r-l+1);
        r++;
    }
    return ans;
}

int main(){
    string s="aaabbccd";
    cout<<longestSubstring3(s,2);
}