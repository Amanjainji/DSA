#include<bits/stdc++.h>
using namespace std;

class AllOne {
public:

    struct Node {
        int freq;
        unordered_set<string> st;
        Node *prev, *next;

        Node(int f) {
            freq = f;
            prev = next = NULL;
        }
    };

    unordered_map<string, Node*> mpp;

    Node *head, *tail;

    AllOne() {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node, Node* prevNode) {
        node->next = prevNode->next;
        node->prev = prevNode;

        prevNode->next->prev = node;
        prevNode->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void inc(string key) {

        // Key doesn't exist -> frequency 1
        if (!mpp.count(key)) {

            Node* node;

            // Create frequency 1 bucket if needed
            if (head->next == tail || head->next->freq != 1) {
                node = new Node(1);
                addNode(node, head);
            }
            else {
                node = head->next;
            }

            node->st.insert(key);
            mpp[key] = node;
        }

        // Key already exists
        else {

            Node* curr = mpp[key];
            Node* nextNode;

            // Need frequency curr->freq + 1
            if (curr->next == tail ||
                curr->next->freq != curr->freq + 1) {

                nextNode = new Node(curr->freq + 1);
                addNode(nextNode, curr);
            }
            else {
                nextNode = curr->next;
            }

            // Move key to next frequency
            nextNode->st.insert(key);
            curr->st.erase(key);

            mpp[key] = nextNode;

            // Delete empty bucket
            if (curr->st.empty())
                removeNode(curr);
        }
    }

    void dec(string key) {

        Node* curr = mpp[key];

        // Frequency 1 -> remove key completely
        if (curr->freq == 1) {

            curr->st.erase(key);
            mpp.erase(key);

            if (curr->st.empty())
                removeNode(curr);

            return;
        }

        Node* prevNode;

        // Need frequency curr->freq - 1
        if (curr->prev == head ||
            curr->prev->freq != curr->freq - 1) {

            prevNode = new Node(curr->freq - 1);
            addNode(prevNode, curr->prev);
        }
        else {
            prevNode = curr->prev;
        }

        // Move key to previous frequency
        prevNode->st.insert(key);
        curr->st.erase(key);

        mpp[key] = prevNode;

        // Delete empty bucket
        if (curr->st.empty())
            removeNode(curr);
    }

    string getMaxKey() {

        if (head->next == tail)
            return "";

        return *tail->prev->st.begin();
    }

    string getMinKey() {

        if (head->next == tail)
            return "";

        return *head->next->st.begin();
    }
};