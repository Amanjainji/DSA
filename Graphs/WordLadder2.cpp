#include <bits/stdc++.h>
using namespace std;

//Interview Solution , gives TLE/MLE On Leetcode
class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,vector<string> &wordList){
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // Creating a queue which stores the words in a sequence which is
        // required to reach the targetWord after successive transformations.
        queue<vector<string>> q;

        // BFS traversal with pushing the new formed sequence in queue 
        // when after a transformation, a word is found in wordList.

        q.push({beginWord});

        // A vector defined to store the words being currently used
        // on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
       
        // A vector to store the resultant transformation sequence.
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // Now, erase all words that have been
            // used in the previous levels to transform
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();

            // store the answers if the end word matches with targetWord.
            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {   
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word) > 0)
                    { 
                        // Check if the word is present in the wordList and
                        // push the word along with the new sequence in the queue.
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

//Leetcode optimized(CP approach)
class Solution2 {
    string b;
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
public:
    void dfs(string word , vector<string> &seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mpp[word];
        int sz = word.size();
        for(int i=0 ; i<sz ; i++){
            char org = word[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end()  && mpp[word] + 1 == steps){

                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> findLadders(string st, string tar, vector<string>& word) {
        unordered_set<string> s(word.begin(),word.end());
        queue<string> q;
        q.push(st); 
        mpp[st] = 1;
        b = st;

        while(!q.empty()){
            string str = q.front();
            int steps = mpp[str];
            q.pop();
            if(str == tar) break;

            int wordLen = str.size(); 
            for(int i=0 ; i<wordLen ; i++){
                char org = str[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    str[i] = ch;
                    if(s.count(str) && mpp.find(str) == mpp.end()){
                        q.push(str);
                        mpp[str] = steps+1;
                    }
                }
                str[i] = org;
            }
        }
        if(mpp.find(tar) != mpp.end()){
            vector<string> seq;
            seq.push_back(tar);
            dfs(tar,seq);
        }
        
        return ans;
    }
};

int main()
{

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    vector<vector<string>> ans1 = obj.findSequences(startWord, targetWord, wordList);
    
    Solution2 obj1;
    vector<vector<string>> ans = obj1.findLadders(startWord, targetWord, wordList);
    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}