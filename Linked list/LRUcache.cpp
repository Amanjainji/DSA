#include<bits/stdc++.h>
using namespace std;

//Doubly linked lists
class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(){
            key=-1,value=-1;
            next=NULL;
            prev=NULL;
        }
        Node(int k, int val){
            key=k;
            value=val;
            next=NULL;
            prev=NULL;
        }
};

void insertAtHead(Node* node,Node *head){
    Node* currAfterHead=head->next;
    head->next=node;
    node->next=currAfterHead;
    node->prev=head;
    currAfterHead->prev=node;
}

void deleteNode(Node* node){
    Node* prevNode=node->prev;
    Node* afterNode=node->next;
    prevNode->next=afterNode;
    afterNode->prev=prevNode;
}

unordered_map<int,Node*> mpp;

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity=capacity;
        mpp.clear();
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())    //not found
            return -1;
        
        Node* node=mpp[key];
        deleteNode(node);
        insertAtHead(node,head); //LRU
        return node->value;
    }
    
    void put(int key, int val) {
        if(mpp.find(key)!=mpp.end()){     //already exist
            Node* node=mpp[key];
            node->value=val;
            deleteNode(node);
            insertAtHead(node,head);
        }
        else{       //not exist,create new
            if(mpp.size()==capacity){       //size=full ,delete last node
                Node* lruNode = tail->prev;
                mpp.erase(lruNode->key);
                deleteNode(lruNode);
            }
            Node* node=new Node(key,val);
            mpp[key]=node;
            insertAtHead(node,head);
        }
        //cout<<"Object Added Successfully"<<" ";
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    int key=2,value=4,capacity=4;
    LRUCache* obj = new LRUCache(capacity);
    int param = obj->get(key);
    obj->put(key,value);
    int param2 = obj->get(key);
    cout<<param2;
}