#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1){
            return NULL;
        }
        ListNode* temp=head;
        int count=1;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        int k=count-n;
        temp=head;
        if(k==0){
            ListNode* node=temp->next;
            delete temp;
            return node;
        }
        count=1;
        while(count<k){
            temp=temp->next;
            count++;
        }
        ListNode* rem=temp->next;
        if(rem!=NULL)
            temp->next=rem->next;
        else{
            temp->next=NULL;
        }

        delete rem;

        return head;
}
