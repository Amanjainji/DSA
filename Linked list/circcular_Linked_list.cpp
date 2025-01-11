#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }

    ~Node(){
        int val= this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for data:"<<val<<endl;
    }
};


void print(Node* tail){
    Node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
    cout<<endl;
}

void insert(Node* &tail,int elem,int d){
    if(tail==NULL){
        Node* newNode=new Node(d);
        newNode->next=newNode;
        tail=newNode;
        return;
    }
    else{
        //assuming element elem is present in the list
        Node* new_Node=new Node(d);
        Node* temp=tail;
        while(temp->data!=elem){
            temp=temp->next;
        }
        //we got the position to insert in temp
        new_Node->next=temp->next;
        temp->next=new_Node;
    }
}

void deletion(Node* &tail,int value){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    else{
        Node* curr=tail->next;
        Node* prev=tail;
       
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        if(tail==curr){
            tail=prev;       
        }
        if(curr->next==curr){
            delete curr;
            tail=NULL;
            return;
        }
        else{
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
        }

    }
}

bool isCircularList(Node* head){
    if(head==NULL){
        return true;
    }
    
    Node* temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==NULL){
        return false;
    }
    else{
        return true;
    }
}



int main(){
    Node* tail=NULL;
    insert(tail,2,5);
    //print(tail);
    insert(tail,5,6);
    //print(tail);
    insert(tail,6,8);
    insert(tail,6,18);
    insert(tail,6,2);
    insert(tail,6,7);
    //print(tail);
    //cout<<tail->data;
    //deletion(tail,5);
    //deletion(tail,8);
    //print(tail);
    //cout<<isCircularList(tail);
    return 0;
}