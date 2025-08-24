#include<bits/stdc++.h>
using namespace std;

/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
*/

//brute force
int numberOfSubstrings(string s){
    int cnt=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        vector<int> hash(3, 0);
        for(int j=i;j<n;j++){
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                cnt+=(n-j); // All substrings from this point to end are valid
                break;
            }
        }
    }
    return cnt;
}

//two pointer
int numberOfSubstrings2(string s) {
        vector<int> count(3, 0); // To store counts of 'a', 'b', 'c'
        int left = 0, res = 0;
        
        for (int right = 0; right < s.length(); right++) {
            count[s[right] - 'a']++;
            
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += s.length() - right; // All substrings from left to end are valid
                count[s[left] - 'a']--; // Move the left pointer
                left++;
            }
        }
        return res;
    }

//Optimal approach by striver
int numberOfSubstrings3(string s) {
    vector<int> lastseen(3,-1);
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        lastseen[s[i]-'a']=i;
        if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1)
            cnt+= (1+min({lastseen[0],lastseen[1],lastseen[2]}));
    }
    return cnt;
}

int main(){
    string s = "abcabc";
    cout<<numberOfSubstrings3(s);

}