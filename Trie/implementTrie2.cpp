#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        Node* child[26];
        int endCount;
        int prefixCount;

        Node() {
            fill(child, child + 26, nullptr);
            endCount = 0;
            prefixCount = 0;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!node->child[idx])
                node->child[idx] = new Node();

            node = node->child[idx];
            node->prefixCount++;
        }

        node->endCount++;
    }

    int countWordsEqualTo(const string& word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!node->child[idx])
                return 0;

            node = node->child[idx];
        }

        return node->endCount;
    }

    int countWordsStartingWith(const string& prefix) {
        Node* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (!node->child[idx])
                return 0;

            node = node->child[idx];
        }

        return node->prefixCount;
    }

    void erase(const string& word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!node->child[idx])
                return;

            node = node->child[idx];
            node->prefixCount--;
        }

        node->endCount--;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    cout << "Equal to apple: "
         << trie.countWordsEqualTo("apple") << '\n';

    cout << "Starting with app: "
         << trie.countWordsStartingWith("app") << '\n';

    trie.erase("app");

    cout << "Equal to apple: "
         << trie.countWordsEqualTo("apple") << '\n';

    cout << "Starting with app: "
         << trie.countWordsStartingWith("app") << '\n';

    return 0;
}