#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        string ans="";
        int n = s.size();

        for(int i=n-1; i>=0; i--) {
            while(i>=0 && s[i] == ' ') {
                i--;
            }

            int j = i;
            while(j>=0 && s[j] != ' ') {
                j--;
            }

            ans += s.substr(j+1, i-j);
            ans += ' ';
            i = j;
        }
        
        ans.pop_back();
        return ans;
    }

int main(){
    string s="  a   good   example   ";
    cout<<reverseWords(s);
}