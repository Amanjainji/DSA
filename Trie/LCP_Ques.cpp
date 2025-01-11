#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            childCount=0;
            isTerminal=false;
        }
};

class Trie{
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        //assumption - word will be in CAPS
        int index=word[0]-'a';
        TrieNode* child;

        //present
        if(root-> children[index]!=NULL){
            child=root->children[index];
        }
        else{ //absent
            child=new TrieNode(word[0]);
            root->childCount++;
            root->children[index]=child;
        }

        //recursion
        insertUtil(child,word.substr(1));
    }

    bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'a';
        TrieNode* child; 

        if(root->children[index]!=NULL){ //present
            child=root->children[index];
        }
        else{  //absent
            return false;
        }
        //Recursion
        return searchUtil(child,word.substr(1));
    }

    void deleteWordUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=false;
            root=NULL;
            return;
        }

        int index=word[0]-'a';
        TrieNode* child; 

        child=root->children[index];
        
        deleteWordUtil(child,word.substr(1));
        root->childCount--;
        root=NULL;
    }

    public:
    TrieNode* root;

    Trie(){
        root=new TrieNode('\0');
    }  
     
    void insertWord(string word){
        insertUtil(root,word);
    }
   

    bool search(string word){
        return searchUtil(root,word);
    }

    void deleteWord(string word){
        if(search(word))
            deleteWordUtil(root,word);
        else
            cout<<"Not found..."<<endl;
    }

    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childCount==1){
                ans.push_back(ch);   
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }
};  

//ques 1 - longest common prefix

//approach -1 : Using Trie TC-O(m*n) SC -O(m*n)
string longestCommonPrefix2(vector<string> &arr,int n){
    Trie *t=new Trie();
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }

    string first=arr[0];
    string ans="";
    t->lcp(first,ans);
    return ans;
}

//approach 2 :  TC -O(m*n)     SC -O(1)
string longestCommonPrefix(vector<string> &arr,int n){
    string ans="";
    //for traversing all character of first string
    for(int i=0;i<arr[0].length();i++){
        char ch=arr[0][i];
        bool match=true;

        //for comparing ch with rest of the string
        for(int j=1;j<n;j++){
            //not match
            if(arr[j].size()<i || ch!=arr[j][i]){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}

int main(){
    vector<string> arr={"aman","amanda","amara","amphibian"};
    cout<<longestCommonPrefix(arr,4)<<endl;
    cout<<longestCommonPrefix2(arr,4);
}

