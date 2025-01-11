#include<iostream>
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

void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next = temp;
    tail=temp;
}

Node* swapPairs(Node* head) {
        if(head==NULL || head->next==NULL){  //base case
            return head;
        }

        Node* temp=head->next;    
        head->next=swapPairs(temp->next);
        temp->next=head;
        return temp;
    }

int main(){
    Node* head=new Node(1);
    Node* tail=head;

    InsertAtTail(tail,2);
    InsertAtTail(tail,3);
    InsertAtTail(tail,4);

    Node* k=swapPairs(head);
    print(k);

}