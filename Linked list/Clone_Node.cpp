#include <iostream>
#include<vector>
#include <map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }

    ~Node(){
    int val=data;
    if(this->random != NULL){
        delete random;
        this->random =NULL;
    }
    if(this->next != NULL){
        delete next;
        this->next =NULL;
    }
    cout<<"Memory is free for node having data: "<<val<<endl;
}   
};

void print(Node* head){
    Node* temp=head;
    cout<<"Next ptr data: "<<endl;
    while(temp!=NULL){
        if(temp->next==NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        else{
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }   
    }
    cout<<endl;
    temp=head;
    cout<<"Random ptr data: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" -> "<<temp->random->data<<"     ";
        temp=temp->next;
    }
    cout<<endl<<endl;
}


void insertAtTail(Node* &head,Node* &tail,int d){
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

Node* copyList(Node* head){     //approach 1 :-   T.C.-O(N)     S.C.-O(N)
    //step1: create a clone list
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;

    Node* temp= head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }

    //step2: create a map
    map<Node*,Node*> oldToNewNode;
    Node* originalNode=head; 
    Node* cloneNode= cloneHead;
    while(originalNode!= NULL && cloneNode!=NULL){
        oldToNewNode[originalNode]=cloneNode;
        originalNode=originalNode->next;
        cloneNode= cloneNode->next;
    }

    originalNode=head;
    cloneNode= cloneHead;

    while(originalNode!= NULL){
        cloneNode->random= oldToNewNode[originalNode->random];
        originalNode=originalNode->next;
        cloneNode= cloneNode->next;
    }
    return cloneHead;
}

Node* copyList2(Node* head){    //approach2 :-  T.C.-O(N)       S.C.- O(1)
    //step1: create a clone list
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;

    Node* temp= head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }

    //STEP2: cloneNodes add in between Original List
    Node* originalNode= head;
    Node* cloneNode = cloneHead;

    while(originalNode!=NULL && cloneNode!=NULL){
        Node* next1 = originalNode ->next;
        originalNode ->next=cloneNode;
        originalNode=next1;

        next1= cloneNode->next;
        cloneNode->next= originalNode;
        cloneNode=next1;
    }

    //step3: random pointer copy
    temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            else{ //temp->random = NULL
                temp->next->random=temp->random; 
            }
        }
        temp=temp->next->next;
    }

    //step4: revert changes done in step 2
    originalNode=head;
    cloneNode=cloneHead;
    while(originalNode!=NULL && cloneNode!=NULL){
        originalNode->next= cloneNode->next;
        originalNode =  originalNode->next;

        if(originalNode!=NULL){
            cloneNode ->next = originalNode->next;
        }
        cloneNode=cloneNode->next;
    }

    //step5 : return ans
    return cloneHead;

}
int main(){
    Node* head=new Node(1);
    Node* tail=head;
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);

    //setting randoms
    head->random=head->next->next;  //1
    head->next->random=head;    //2
    head->next->next->random=tail;  //3
    head->next->next->next->random=head->next->next;    //4
    tail->random=head->next;    //5

    //print(head);
    //Node* cloneHead1=copyList(head);
    //Node* cloneHead=copyList2(head);
    //print(cloneHead);

    return 0;
    
}