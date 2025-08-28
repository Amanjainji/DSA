#include <iostream>
#include <string>
#include <climits>
using namespace std;
// function to find the smallest substring of s1 containing s2 as subsequence

// brute force
//function to check if s2 is a subsequence of s1
bool isSubsequence(string &s1, string &s2) {
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) j++;
        i++;
    }
    return j == s2.size();
}

string minWindow(string &s1, string &s2) {
    int n = s1.size();
    string ans = "";
    int minLen = INT_MAX;

    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            string s = s1.substr(start, end - start + 1);
            if (isSubsequence(s, s2)) {
                if (s.size() < minLen) {
                    minLen = s.size();
                    ans = s;
                }
                // no need to extend further for this start
                // as we want smallest
                break; 
            }
        }
    }
    return ans;
}

//sliding window
//optimal approach  
string minWindow2(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int minLen = INT_MAX, start = -1;

    int i = 0, j = 0;
    while (i < n) {
        // forward: try to match s2
        if (s1[i] == s2[j]) {
            j++;
            if (j == m) { // found a match
                int end = i;
                j--; // backtrack on s2

                // backward: shrink window
                while (j >= 0) {
                    if (s1[i] == s2[j]) j--;
                    i--;
                }
                i++; // correct overshoot
                j = 0;

                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }
            }
        }
        i++;
    }
    return (start == -1) ? "" : s1.substr(start, minLen);
}

int main() {
    string s1 = "abcdebdde";
    string s2 = "bde";
    cout << minWindow(s1, s2) << endl;
    return 0;
}