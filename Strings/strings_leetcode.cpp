#include<vector>
#include<iostream>
#include<bits/stdc++.h>
#include<strings.h>
using namespace std;

void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
char toLowerCase(char ch){
    if((ch>='a' && ch<='z')||(ch>='0' && ch<='9')){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }

}
string reverse(string st){
    string s=st;
    int begin=0;
    int end=s.length()-1;
    while(begin<end){
        swap(s[begin++],s[end--]);
    }
    return s;
}
/*
bool isPalindrome(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
                ans.push_back(s[i]);
            }
        }
        for(int j=0;j<ans.size();j++){
            ans[j]=toLowerCase(ans[j]);
        }
        string ans2=reverse(ans);
        if(ans==ans2){
            return true;
        }
        return false;   
    }
 
*/
/*
int CountWords(string s) {
        int countWords=0;
        for(int i=0;i<=s.length();i++){
            if((s[i]==' '&& s[i+1]!=' ')||s[i]=='\0'){
                countWords++;
            }
            
        }
        int k=s.length();
        if(s[k]=='\0' && s[k-1]==' '){
                countWords--;
        }
        if(s[0]==' '){
            countWords--;
        }

        return countWords;
}
*/
string ReverseString2(string s){
    string temp;
    string ans;
    int i=0;
    while(true){
        while(s[i]!=' '&& s[i]!='\0'){
            temp.push_back(s[i]);
            i++;
        }
        string rev=reverse(temp);
        ans+=rev;
        ans+=' ';
        temp.clear();
        if(s[i]=='\0'){
            break;
        }
        i++;

    }
    return ans;
}    
/*
string changeSpaces(string &s){
    string temp;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
           temp.push_back('@');
           temp.push_back('4');
           temp.push_back('0');
        }
        else{
            temp.push_back(s[i]);
        }
    }
    return temp;
}
*/
string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
//permutation of string
/*
bool checkEqual(int a[26],int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}
bool checkInclusion(string s1,string s2){ //s1=abc s2=eioobacddef
    //character count array for s1
    int count1[26]={0};
    for(int i=0;i<s1.length();i++){
        int index= s1[i] -'a';
        count1[index]++;
    }

    //traverse s2 string in a window of size s1 length and compare
    int i=0;
    int windowSize=s1.length();
    int count2[26]={0};

    //running for first window
    while(i<windowSize && i<s2.length()){
        int index= s2[i]-'a';
        count2[index]++;
        i++;
    }

    if(checkEqual(count1,count2)){
        return 1;
    }
    //remaining windows
    while(i<s2.length()){
        char newChar = s2[i];
        int index =  newChar-'a';
        count2[index]++;

        char oldChar = s2[i-windowSize];
        index=oldChar-'a';
        count2[index]--;

        i++;

        if(checkEqual(count1,count2)){
            return 1;
        }
    }
    return 0;
}*/

string removeAdjacentDuplicates(string s){
while (true) {
        bool changed = false;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                s.erase(i, 2);
                changed = true;
                break;
            }
        }
        if (!changed||s.length()==0) break;
    }
    return s;
}


/*
string removeAdjacentDuplicates1(string s) {
    string result = "";
    for (char c : s) {
        if ( result.empty()||result.back()!= c) {
            result.push_back(c);
        } else {
            result.pop_back();
        }
    }
    return result;
}*/



int compressString(vector<char> &chars){
    int i=0;
    int n=chars.size();
    vector<char> ans;
    while(i<n){
        int j=i+1;
        while(j<n && chars[j]==chars[i]){
            j++;
        }
        //ya toh vector pura traverse krdia
        //ya fir new diffrent alphabet encounter kr lia

        //oldchar store kro
        ans.push_back(chars[i]);

        int count=j-i; //no. of times that character comes
        if(count>1){
            string cnt=to_string(count);
            for(char ch:cnt){
                ans.push_back(ch);
            }
        }
        i=j;
        }
       return ans.size();
    }

int main(){
    string s="Amana plana canal Panam";
    //cout<<isPalindrome(s);
    //string k=ReverseString2(s);
    //string k=changeSpaces(s);
    //cout<<k;
    //string s1="abc", s2="eioobacddef";
    //cout<<checkInclusion(s1,s2);
    vector<char> str={'a','a','a','a','b','b','c'};
    cout<<compressString(str);
    //cout<<k;
    return 0;
}