#include<bits/stdc++.h>
using namespace std;

//brute force
string solve(string temp){
    string t="";
    int n=temp.size();
    for(int i=1;i<n-1;i++){ // skip first '[' and last ']'
        if(temp[i]>='a' && temp[i]<='z')
            t+=temp[i];
        else{
            t+=decodeString(temp.substr(i,n-i-1));
            break;
        }
    }
    return t;
}

string decodeString(string s) {
    int num=0;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            num = 0;
            while(i<s.length() && isdigit(s[i])){
                num = num*10 + (s[i]-'0');
                i++;
            }
            i--; // adjust
        }
        else if(s[i]=='['){
            int br=1, j=i+1;
            while(br>0){
                if(s[j]=='[') br++;
                if(s[j]==']') br--;
                j++;
            }
            string temp=solve(s.substr(i,j-i));
            i = j-1; // adjust
            for(int k=0;k<num;k++)
                ans+=temp;
            num=0;
        }
        else{
            ans+=s[i];
        }
    }
    return ans;
}

//optimal approach
string decodeString2(string s) {
    stack<int> numStack;        // stores repeat counts
    stack<string> strStack;     // stores partial strings
    string curr = "";           // current built string
    int num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            // build the full number (can be multiple digits)
            num = num * 10 + (c - '0');
        }
        else if (c == '[') {
            // push current number and string into stacks
            numStack.push(num);
            strStack.push(curr);
            num = 0;
            curr = "";
        }
        else if (c == ']') {
            // pop number and previous string
            int k = numStack.top(); numStack.pop();
            string prev = strStack.top(); strStack.pop();

            // expand the current string
            string expanded = "";
            for (int i = 0; i < k; i++)
                expanded += curr;

            // append expanded result to the previous string
            curr = prev + expanded;
        }
        else {
            // normal letter
            curr += c;
        }
    }

    return curr;
}
