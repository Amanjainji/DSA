#include <iostream>
#include<vector>
#include <map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* down;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->down=NULL;
    }

    ~Node(){
    if(this->next != NULL){
        delete next;
        this->next =NULL;
    }
    if(this->down != NULL){
        delete down;
        this->down =NULL;
    }
}   
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl<<endl;
}

Node* findMid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

Node* merge2SortedList(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    if (head1->data <= head2->data) {
        head1->next = merge2SortedList(head1->next, head2);
        return head1;
    } 
    else {
        head2->next = merge2SortedList(head1, head2->next);
        return head2;
    }
}

// Function to flatten a linked list
Node* flattenList(Node* head) {
    if (head == NULL) { // base case
        return NULL;
    }
    Node* temp = head;
    // right part
    Node* head2 = flattenList(temp->next);
    temp->next = NULL;
    // creating a down list
    Node* downListHead = NULL;
    Node* downListTail = NULL;
    while (temp != NULL) {
        if (downListHead == NULL) {
            downListHead = temp;
            downListTail = temp;
        }
        else {
            insertAtTail(downListHead, downListTail, temp->data);
        }
        temp = temp->down;
    }

    Node* final = merge2SortedList(downListHead, head2);

    return final;
}

int main(){
    Node* head=new Node(1);
    head->down=new Node(2);
    head->down->down=new Node(3);

    head->next=new Node(4);
    head->next->down=new Node(5);
    
    head->next->next=new Node(6);

    print(head);
    Node* ans=flattenList(head);
    print(ans);

}