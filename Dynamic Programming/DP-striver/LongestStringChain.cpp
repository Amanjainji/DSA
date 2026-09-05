#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(); // Size of the array 
        sort(words.begin(), words.end(), compare);
        vector<int> dp(n, 1); // DP array 

        // To store the length of longest string chain
        int maxLen = 0;

        // Computing the DP array 
        for(int i = 0; i < n; i++) {

            // For each previous index
            for(int j = 0; j < i; j++) {
                
                /* If the element at index i can be 
                included in the chain ending at index j */
                if(checkPossible(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1; // Update the DP value
                }
            }

            // If a longer chain is found, update the values
            if(dp[i] > maxLen) maxLen = dp[i];
        }
        
        return maxLen;
    }
    
private:
    // Custom comparator function 
    bool static compare(string &s, string &t) {
        return s.size() < t.size();
    }
    
    // Function to check if the string can be added to the chain
    bool checkPossible(string &s, string &t) {
        //  Base case
        if(s.size() != t.size() + 1) return false;
        
        int i = 0, j = 0; // Pointers
        
        // Traverse until the first string is exhausted
        while(i < s.size()) {
            
            // Move both pointers if characters matches
            if(j < t.size() && s[i] == t[j]) {
                i++, j++;
            }
            // Otherwise 
            else {
                i++;
            }
        }
        
        // Return true if both the string gets exhausted
        if(i == s.size() && j == t.size()) return true;
        return false; // Return false otherwise
    }
};


int main() {
    vector<string> words = {"a", "ab", "abc", "abcd", "abcde"};
    
    // Creating an object of Solution class
    Solution sol;
    int lengthOfLongestStringChain = sol.longestStrChain(words);
    
    cout << "The length of the Longest String Chain is: " << lengthOfLongestStringChain << endl;
    
    return 0;
}