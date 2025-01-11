#include <iostream>
#include<vector>
#include <map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
    if(this->next != NULL){
        delete next;
        this->next =NULL;
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

void InsertAtTail(Node* &head,Node* &tail,int d){
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next = temp;
        tail=temp;
    }
}
Node* merge(Node* &left,Node* &right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    Node* ans=new Node(-1); //dummy node
    Node* temp=ans;

    //merge 2 sorted Linked list
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    Node* res=ans->next;
    ans->next=NULL;
    delete ans;
    return res;
}

Node* mergeSort(Node* head){
    //base case
    if(head==NULL || head->next == NULL){
        return head;
    }

    //break linked list into two halves,after finding mid
    Node* mid =findMid(head);

    Node* left=head;
    Node* right= mid->next;
    mid->next=NULL;

    //recursive calls to sort both halves
    left=mergeSort(left);
    right= mergeSort(right);

    //merge both left and right halves
    Node* result=merge(left,right);

    return result;
}

int main(){
    Node* head1 = new Node(10); //sorted linked list and remove duplicates
    Node* tail=head1;
    InsertAtTail(head1,tail,2);
    InsertAtTail(head1,tail,5);
    InsertAtTail(head1,tail,1);
    print(head1);
    Node* head=mergeSort(head1);
    print(head);
    
}