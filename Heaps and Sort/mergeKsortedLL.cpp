#include<bits/stdc++.h>
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
        int value = this ->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next =NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
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

//merge k sorted linked lists  - TC -O(n*klog k)
class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data>b->data;
        }
};

Node* mergeKLists(vector<Node*> &listArrays){
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    int k=listArrays.size();
    if(k==0){
        return NULL;
    }
    //step 1 : Initialize min Heap 
    for(int i=0;i<k;i++){
        if(listArrays[i]!=NULL){
            minHeap.push(listArrays[i]);
        }
    }

    //step 2
    Node* head=NULL;
    Node* tail=NULL;
    while(minHeap.size()>0){
        Node* top=minHeap.top();
        minHeap.pop();
        if(top->next!=NULL){  //push next element of that list_head from which element is pop.
            minHeap.push(top->next);
        }
        if(head==NULL){          //Initialise list
            head=top;
            tail=top;
        }
        else{         //list already created
            tail->next=top;
            tail=tail->next;
        }
    }

    //step 3
    return head;
}