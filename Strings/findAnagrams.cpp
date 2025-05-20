#include<bits/stdc++.h>
using namespace std;

bool anagram(string s,unordered_map<char,int> &n){
        unordered_map<char,int> m=n;
        for(int i=0;i<s.length();i++){
            m[s[i]]--;
        }
        for(auto i:m){
            if(i.second!=0)
                return false;
        }
        return true;
    }
vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m;
        for(int i=0;i<p.length();i++){
            m[p[i]]++;
        }
        int i=0,j=p.length()-1;
        vector<int> ans;
        while(j<s.length()){
            if(anagram(s.substr(i,p.length()),m)){
                ans.push_back(i);
            }
            i++;
            j++;
        }
        return ans;
}

int main(){
    string s = "cbaebabacd", p = "abc";
    vector<int> k=findAnagrams(s,p);
    for(auto i:k){
        cout<<i<<" ";
    }
}