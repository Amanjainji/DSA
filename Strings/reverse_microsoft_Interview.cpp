#include<bits/stdc++.h>
using namespace std;

bool alphanumberic(char c){
    if(c>='0' && c<='9') return true;
    if(c>='a' && c<='z') return true;
    if(c>='A' && c<='Z') return true;
    return false;
}

string solve(string s){
    string ans="";
    int n=s.size();

    vector<string> words;
    vector<string> startP, endP;

    int i=0;

    while(i<n){
        string start_p="";
        // starting punctuation
        while(i<n && !alphanumberic(s[i])){
            start_p.push_back(s[i]);
            i++;
        }
        startP.push_back(start_p);
        string end_p="";
        string word="";
        while(i<n){
            if(alphanumberic(s[i])){
                word.push_back(s[i]);
                i++;
                continue;
            }

            if(s[i]!=' '){
                string p="";
                while(i<n && !alphanumberic(s[i]) && s[i]!=' '){
                    p.push_back(s[i]);
                    i++;
                }

                if(i<n && alphanumberic(s[i])){   // punctuation inside word
                    word+=p;
                    continue;
                }
                else{                             // ending punctuation
                    end_p=p;
                }
            }
            else{
                break;
            }
        }

        words.push_back(word);
        endP.push_back(end_p);

        i++;
    }

    for(int i=0;i<words.size();i++){
        ans+=startP[i];
        ans+=words[words.size()-1-i];
        ans+=endP[i];

        if(i!=words.size()-1)
            ans+=" ";
    }

    return ans;
}

int main(){
    //Assuming there is no multiple white spaces and no trailing and leading white spaces
    string s="//he__llo! World>>";
    cout<<solve(s)<<endl;      // //World! he__llo>>

    string k="Hello>> <<world";
    cout<<solve(k)<<endl;      // world>> <<Hello
}