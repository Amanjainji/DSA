// #include <iostream>  
// #include <string>    
// using namespace std;  


// // Node structure representing
// // each node in the trie
// struct Node {
//     Node* links[26];  
//     // Array of pointers to child nodes,
//     // each corresponding to a letter
//     // of the alphabet
//     bool flag = false;  
//     // Flag indicating if the current
//     // node represents the end of a substring

//     // Method to check if a specific character key
//     // exists in the children of the current node
//     bool containsKey(char ch) {  
//         // Check if the current node has a child node
//         // corresponding to character 'ch'
//         return (links[ch - 'a'] != NULL);
//     }

//     // Method to get the child node corresponding
//     // to a specific character key
//     Node* get(char ch) {  
//         // Get the child node
//         // corresponding to character 'ch'
//         return links[ch - 'a'];
//     }

//     // Method to insert a new child
//     // node with a specific character key
//     void put(char ch, Node* node) {  
//         // Insert a new child
//         // node for character 'ch'
//         links[ch - 'a'] = node;
//     }

//     // Method to mark the current
//     // node as the end of a substring
//     void setEnd() {  
//         // Mark the current node
//         // as the end of a substring
//         flag = true;
//     }

//     // Method to check if the current
//     // node marks the end of a substring
//     bool isEnd() {  
//         // Check if the current node
//         // marks the end of a substring
//         return flag;
//     }
// };

// // Function to count the number of
// // distinct substrings in the given string
// int countDistinctSubstrings(string &s) {  
//     // Function to count distinct
//     // substrings in the input string 's'
//     Node* root = new Node();  
//     // Creating the root
//     // node of the trie
//     int cnt = 0;  
//     // Counter to keep track
//     // of distinct substrings
//     int n = s.size();  
//     // Length of the input string

//     // Nested loops to iterate through all
//     // possible substrings of the input string
//     for (int i = 0; i < n; i++) {  
//         // Iterate through each
//         // starting position of the substring
//         Node* node = root;  
//         // Start from the root for each substring
//         for (int j = i; j < n; j++) {  
//             // Iterate through each character of the substring
//             // If the current character is not a child
//             // of the current node, insert it as a new child node
//             if (!node->containsKey(s[j])) {
//                 node->put(s[j], new Node());  
//                 // Insert a new child
//                 // node for character s[j]
//                 cnt++;  
//                 // Increment the counter
//                 // since a new substring is found
//             }
//             node = node->get(s[j]);  
//             // Move to the child node
//             // corresponding to character s[j]
//         }
//     }
//      // Return the total count of distinct substrings
//      // (+1 to account for the input string itself)
//     return cnt + 1;  
  
// }

// int main() {  
//     // Main function to test the
//     // countDistinctSubstrings function
//     string s = "striver";  
//     cout << "Current String: " << s << endl;
//     // Input string
//     cout << "Number of distinct substrings: " << countDistinctSubstrings(s) << endl;  
//     return 0;  

// }

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Trie {
    struct Node {
        Node* child[26];

        Node() {
            fill(child, child + 26, nullptr);
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    bool contains(Node* node, char ch) {
        return node->child[ch - 'a'] != nullptr;
    }

    Node* get(Node* node, char ch) {
        return node->child[ch - 'a'];
    }

    void insert(Node* node, char ch) {
        node->child[ch - 'a'] = new Node();
    }

    int countDistinctSubstrings(const string& s) {
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            Node* node = root;

            for (int j = i; j < n; j++) {
                char ch = s[j];

                if (!contains(node, ch)) {
                    insert(node, ch);
                    count++;
                }

                node = get(node, ch);
            }
        }

        return count + 1;
    }
};

int main() {
    string s = "striver";

    Trie trie;

    cout << "Current String: " << s << '\n';
    cout << "Number of distinct substrings: "
         << trie.countDistinctSubstrings(s) << '\n';

    return 0;
}