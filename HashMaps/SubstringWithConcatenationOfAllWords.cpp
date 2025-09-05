#include<bits/stdc++.h>
using namespace std;

//brute force
vector<int> findSubstringBrute(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int n = s.size();
        int m = words.size();
        int L = words[0].size();
        int totalLen = m * L;

        if (n < totalLen) return result;

        unordered_map<string,int> need;
        for (auto& w : words) need[w]++;

        for (int i = 0; i <= n - totalLen; i++) {
            unordered_map<string,int> have;
            int j = 0;
            for (; j < m; j++) {
                string word = s.substr(i + j * L, L);
                if (!need.count(word)) break;
                have[word]++;
                if (have[word] > need[word]) break;
            }
            if (j == m) result.push_back(i);
        }

    return result;
}

//optimal
vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount; //window size

        if (s.size() < totalLen) return result;

        // Build frequency map of words
        unordered_map<string, int> need;
        for (string& w : words) need[w]++;

        // Try different starting offsets
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> have;

            // Slide the window in steps of wordLen
            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (need.find(word)!=need.end()) {
                    have[word]++;
                    count++;

                    // If a word is used too many times, shrink from left
                    while (have[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        have[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If window has exactly all words
                    if (count == wordCount) {
                        result.push_back(left);
                        // Move left forward
                        string leftWord = s.substr(left, wordLen);
                        have[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } 
                else {
                    // Reset if word not in list
                    have.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
}

int main(){

}