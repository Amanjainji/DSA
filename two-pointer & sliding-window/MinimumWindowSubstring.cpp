#include<bits/stdc++.h>
using namespace std;

//brute force
string minimumSubstring(string s,string t){
    int minlen=1e9, stIndex=-1;
    int n=s.length(),m=t.length();
    for(int i=0;i<n;i++){
        vector<int> hash(256,0);
        int cnt=0;
        for(int j=0;j<m;j++) hash[t[j]]++;
        for(int j=i;j<n;j++){
            if(hash[s[j]]>0) cnt++;
            hash[s[j]]--;
            if(cnt==m){
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    stIndex=i;
                    break;
                }
            }
        }
    }
    return s.substr(stIndex,minlen);
}

string minimumSubstring2(string s,string t){
    int minlen=1e9, stIndex=-1;
    int n=s.length(),m=t.length();
    int l=0,r=0;
    int cnt=0;
    vector<int> hash(256,0);
    for(int i=0;i<m;i++)
        hash[t[i]]++;
    while(r<s.size()){
        if(hash[s[r]]>0) cnt++;
        hash[s[r]]--;
    
        while(cnt==m){
            if(r-l+1<minlen){
                minlen=r-l+1;
                stIndex=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0) cnt--;
            l++;
        }
        r++;
    }
    return s.substr(stIndex,minlen);
}
int main(){
    string s="ddbcddab";
    string t="abc";
    cout<<minimumSubstring2(s,t);
}