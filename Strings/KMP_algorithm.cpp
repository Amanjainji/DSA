#include <iostream>
#include <vector>
#include <string>
using namespace std;
class SubstringSearch {
public:
    // Naive method of pattern matching
    bool hasSubstring(const string& text, const string& pattern) {
        int i = 0, j = 0, k = 0;
        while (i < text.size() && j < pattern.size()) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            } else {
                j = 0;
                k++;
                i = k;
            }
        }
        return (j == pattern.size());
    }

    // KMP algorithm of pattern matching
    bool KMP(const std::string& text, const std::string& pattern) {
        std::vector<int> lps = computeTemporaryArray(pattern);
        int i = 0, j = 0;

        while (i < text.size() && j < pattern.size()) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return (j == pattern.size());
    }

private:
    // Compute LPS (Longest Prefix Suffix) array
    vector<int> computeTemporaryArray(const string& pattern) {
        vector<int> lps(pattern.size(), 0);
        int index = 0;
        for (int i = 1; i < pattern.size();) {
            if (pattern[i] == pattern[index]) {
                lps[i] = index + 1;
                index++;
                i++;
            } else {
                if (index != 0) {   //avoids redundant comparisons
                    index = lps[index - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

int main() {
    std::string text = "abcxabcdabcdabcy";
    std::string pattern = "abcdabcy";

    SubstringSearch ss;
    bool result = ss.KMP(text, pattern);
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}
