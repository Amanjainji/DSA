#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class Trie{
    public:

    TrieNode* root;

    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        //assumption - word will be in CAPS
        int index=word[0]-'A';
        TrieNode* child;

        //present
        if(root-> children[index]!=NULL){
            child=root->children[index];
        }
        else{ //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursion
        insertUtil(child,word.substr(1));
    }

     
    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'A';
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

    bool search(string word){
        return searchUtil(root,word);
    }

    void deleteWordUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=false;
            return;
        }

        int index=word[0]-'A';
        TrieNode* child; 

        child=root->children[index];
        
        deleteWordUtil(child,word.substr(1));
    }
    void deleteWord(string word){
        if(search(word))
            deleteWordUtil(root,word);
        else
            cout<<"Not found..."<<endl;
    }
};  


int main(){
    Trie *t=new Trie();
    t->insertWord("AMAN");
    t->insertWord("RAHUL");
    t->insertWord("SHAH");
    cout<<t->search("AMAN")<<endl;
    t->deleteWord("RAHUL");
    cout<<t->search("R")<<endl;
    return 0;
}