#include<bits/stdc++.h>
using namespace std;

//brute force
int characterReplacement(string s,int k) {
    int n=s.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        vector<int> mpp(26,0);
        int maxFreq=0;
        for(int j=i;j<n;j++){
            mpp[s[j]-'A']++;
            maxFreq=max(mpp[s[j]-'A'],maxFreq);
            int noOfReplaceReq=j-i+1-maxFreq;
            if(noOfReplaceReq<=k)
                maxlen=max(maxlen,j-i+1);
            else
                break;
        }
    }
    return maxlen;
}

//two pointers
int characterReplacement1(string s, int k) {
        int l = 0, r = 0, maxlen = 0, maxFreq = 0;
        vector<int> mpp(26,0);
        int n = s.size();

        while (r < n) {
            mpp[s[r]-'A']++;
            maxFreq = max(maxFreq, mpp[s[r]-'A']);  // track best freq so far

            // if window is invalid, shrink
            while((r - l + 1) - maxFreq > k) {
                mpp[s[l]-'A']--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
}

//sliding window
int characterReplacement2(string s, int k) {
        int l = 0, r = 0, maxlen = 0, maxFreq = 0;
        vector<int> mpp(26,0);
        int n = s.size();

        while (r < n) {
            mpp[s[r]-'A']++;
            maxFreq = max(maxFreq, mpp[s[r]-'A']);  // track best freq so far

            // if window is invalid, shrink
            if((r - l + 1) - maxFreq > k) {
                mpp[s[l]-'A']--;
                l++;
            }
            if((r - l + 1) - maxFreq <= k)
                maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
}
int main(){
    string s="BAAA";
    cout<<characterReplacement2(s,0);
}