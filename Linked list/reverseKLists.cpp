#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to print the linked list
void print(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse nodes in k-group
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1)
        return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        // Count the number of nodes in the list
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }

        // Reverse k nodes at a time
        while (count >= k) {
            curr = prev->next;
            ListNode* next = curr->next;

            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            prev = curr;
            count -= k;
        }

        return dummy.next;
    }


int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reverse in groups of 2
    ListNode* Node = reverseKGroup(head, 3);

    // Print the reversed linked list
    print(Node);

    return 0;
}
