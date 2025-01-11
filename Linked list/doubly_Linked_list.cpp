#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        int temp=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
       
        cout<<"Memory free for data:"<<temp<<endl;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node*temp1 = new Node(data);
        head=temp1;
        return;
    }
    Node*temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node* temp1 = new Node(data);
        tail=temp1;
        return;
    }
    Node* NewNode= new Node(data);
    tail->next=NewNode;
    NewNode->prev=tail;
    tail=NewNode;
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    //insertion at start
    if(position==0){
        insertAtHead(head,tail,data);
        return;
    }
    //insert in middle or end:-
    Node* temp= head;
    int cnt=1;

    while(cnt<=position-1){
        temp=temp->next;
        cnt++;
        if(temp->next==NULL && cnt<position){
            return;
        }
    }
    //inserting at  last position
    if(temp->next == NULL){
        insertAtTail(head,tail,data);
        return;
    }

    //creating a node for data for middle
    Node* nodeToInsert=new Node(data);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}

void DeleteNode(Node* &head,Node* &tail,int position){ 
    if(position==0){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        int cnt=0;
        Node* curr=head;
        while(cnt<=position-1){
            curr=curr->next;
            cnt++;
        }
        Node* previous=curr->prev;
        curr->prev=NULL;
        previous->next=curr->next;
        if(curr->next==NULL){
            tail=previous;
            delete curr;
            return;
        }
        curr->next->prev=previous;
        curr->next=NULL;
        delete curr;
        return;
    }}

int search(Node* head){
    if(head==NULL){
        printf("List is empty");
        return -1;
    }
    int elem;
    printf("Enter element to search: ");
    scanf("%d",&elem);
    int ans=-1;
    Node* temp=head;
    int cnt=1;
    while(temp!=NULL){
        if(temp->data==elem){
            ans=cnt;
            break;
        }
        cnt++;
        temp=temp->next;
    }
    return ans;
}



int main(){
      Node* node1=new Node(10);  
      Node* head=node1;
      Node* tail=node1;
      //print(head);
      //cout<<getLength(head);
      insertAtHead(head,tail,12);
      insertAtTail(head,tail,5);
      //cout<<"head "<<head->data<<endl;
      insertAtPosition(head,tail,9,3);
      //print(head);
      //DeleteNode(head,tail,3);
      //print(head);
      //cout<<"head "<<head->data<<endl;
      //cout<<"tail "<<tail->data<<endl;
/*
      Node* head1=NULL;
      insertAtHead(head1,5);
      print(head1);
      cout<<"head "<<head1->data<<endl;
*/   
    cout<<search(head);
    return 0;

}