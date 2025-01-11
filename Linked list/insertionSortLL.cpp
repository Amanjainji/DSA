#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    
    ListNode(int val) : value(val), next(NULL) {}
};


ListNode* insertionSortList(ListNode* head) {
    // If the list is empty or has only one element, it's already sorted
    if (!head || !head->next) {
        return head;
    }
    
    ListNode* sorted = NULL; // This will be the new sorted list

    // Iterate through the original list
    ListNode* current = head;
    while (current) {
        // Store the next node to process
        ListNode* nextNode = current->next;
        
        // Insert current into the sorted list
        if (!sorted || sorted->value >= current->value) {
            // Insert at the beginning
            current->next = sorted;
            sorted = current;
        } else {
            // Find the appropriate position to insert
            ListNode* search = sorted;
            while (search->next && search->next->value < current->value) {
                search = search->next;
            }
            // Insert in the sorted list
            current->next = search->next;
            search->next = current;
        }
        
        // Move to the next node
        current = nextNode;
    }
    
    return sorted; // Return the new sorted list
}
