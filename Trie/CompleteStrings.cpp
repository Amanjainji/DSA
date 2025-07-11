/*
C++11 implementation that solves the “Longest String with All Prefixes (a.k.a. Complete String)” problem using a Trie.

Intuition 
1. Insert every word into a Trie while marking terminal (end‑of‑word) nodes.
2. While inserting we don’t decide anything; we simply build the Trie.
3. After the build, iterate over all words again and check whether every prefix of the word is terminal.
4. Track the lexicographically‑smallest word among those that satisfy the “all‑prefixes‑present” property and have maximal length.
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26] {};
    bool isTerminal = false;
};

class Trie {
public:
    Trie() : root(new TrieNode) {}
    ~Trie() { freeNode(root); }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* cur = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) cur->child[idx] = new TrieNode;
            cur = cur->child[idx];
        }
        cur->isTerminal = true;
    }

    // Does this word have all prefixes present?
    bool hasAllPrefixes(const string& word) const {
        const TrieNode* cur = root;
        for (char ch : word) {
            int idx = ch - 'a';
            cur = cur->child[idx];
            if (!cur || !cur->isTerminal) return false;
        }
        return true;                // full word is also a prefix of itself
    }

private:
    TrieNode* root;

    void freeNode(TrieNode* node) {
        if (!node) return;
        for (auto nxt : node->child) freeNode(nxt);
        delete node;
    }
};

// Returns the longest complete string; if none exists, returns "None"
string longestCompleteString(const vector<string>& words) {
    Trie trie;
    for (const string& w : words) trie.insert(w);

    string best = "";
    for (const string& w : words) {
        if (trie.hasAllPrefixes(w)) {
            if (w.length() > best.length() ||          // longer
               (w.length() == best.length() && w < best))  // lexicographically smaller
                best = w;
        }
    }
    return best.empty() ? "None" : best;
}

/* -----------------  Driver  ----------------- */
int main() {
    vector<string> words = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    cout << longestCompleteString(words) << "\n";  // outputs: ninja
    return 0;
}
