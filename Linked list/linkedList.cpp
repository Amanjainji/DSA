#include <iostream>
#include<vector>
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

int getLength(Node* head){
    int cnt=0;
    if(head==NULL){
        return cnt;
    }
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }


void InsertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}


void InsertAtTail(Node* &tail,int d);
void InsertAtPosition(Node* &head,Node* tail,int d,int p){
    //inserting at start position
    if(p==0){
        InsertAtHead(head,d);
        return;
    }

    Node* temp=head;
    int cnt=1;
    while(cnt<p){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertAtTail(tail,d);
        return;
    }
    //creating a node for d
    Node* NodeToInsert=new Node(d);
    NodeToInsert -> next =temp->next;
    temp->next= NodeToInsert;
}


void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next = temp;
    tail=temp;
}

void deleteNode(Node* &head,Node* &tail, int position){
    if(position == 0){
        Node* temp = head;
        head=head-> next;
        //memory free 
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt=1;
        while(cnt<=position){
            prev=curr;
            curr=curr->next;
            if(curr->next==NULL && cnt<position){
                return;
            }
            cnt++;
        }
        prev->next = curr->next;
        if(prev->next==NULL){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

/*
void deleteNodeWithValue(Node* &head,Node* &tail, int value){
    if(value == head->data){
        Node* temp = head;
        head=head-> next;
        //memory free 
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        while(curr->data!= value){
            prev=curr;
            curr=curr->next;
            if(curr->next==NULL && curr->data!= value){
                cout<<"No value found"<<endl;
                return;
            }
        }
        prev->next = curr->next;
        if(prev->next==NULL){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

*/

void ReverseRecursionAlgo(Node* &head,Node* curr,Node* prev){
    if(curr==NULL){
        head=prev; //head just to update
        return;
    }

    Node* forward= curr->next;
    ReverseRecursionAlgo(head,forward,curr);
    curr->next=prev;
}

Node* ReverseRecursionAlgo1(Node* &head){
    if(head==NULL ||head->next==NULL){
        return head;
    }
    Node* chotahead= ReverseRecursionAlgo1(head->next); //it will return the reverse list and the head of the reverse part
    head->next->next=head;
    head->next=NULL;

    return chotahead;
}

void ReverseRecursion(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    //cout<<"Reverse by Recursion method1:"<<endl;
    //ReverseRecursionAlgo(head,curr,prev);
    cout<<"Reverse by Recursion method2:"<<endl;
    head=ReverseRecursionAlgo1(head);
}

void Reverse(Node* &head){
    cout<<"Reverse is:"<<endl;
    if(head==NULL || head->next==NULL){
        return;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        Node* temp=NULL;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr; 
            curr=temp; 
        }
        head=prev;
    }
}

Node* getMiddle(Node* &head){  //T.C. - O(N)
    if(head==NULL || head->next==NULL){
        return head;
    }
    int len=getLength(head);
    int middle=(len/2)+1;
    Node* temp=head;
    int cnt=1;
    while(cnt<middle){
        temp=temp->next;
        cnt++;
    }
    return temp;
}

Node* getMiddle2(Node* &head){ //T.C. - O(N/2)
    if(head==NULL || head->next==NULL){
        return head;
    }
    else if(head->next->next==NULL){
        return head->next;
    }
    else{
        Node* slow=head;
        Node* fast=head->next;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }  
}

Node* kReverse(Node* &head , int k){
    //base call
    if(head==NULL){
        return NULL;
    }

    //step1: reverse first k nodes
    Node* next1 = NULL;
    Node* curr= head;
    Node* prev = NULL;
    int count=0;

    while(curr!= NULL && count<k){
        next1= curr->next;
        curr->next=prev;
        prev=curr;
        curr=next1;
        count++;
    }

    //step2: recursion dekhlega aage ka
    if(next1!=NULL){
        head->next=kReverse(next1,k);
    }

    //step3: return head of reversed list
    return prev;
}

/*
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
bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }
    
    map<Node*,bool> visited;
    Node* temp=head;
    while(temp!=NULL){
        //cycle is present
        if(visited[temp]==true){
            return true;
        }
        //else
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }

        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    if(intersection==NULL){
        return NULL;
    }
    Node* slow=head;

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head==NULL){
        return;
    }

    Node* start= getStartingNode(head);
    if(start==NULL){
        return;
    }
    Node* temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=NULL;
    return;
}
*/


Node* RemoveDuplicates(Node* head) {
    if (head == NULL) {
        cout<<"List is empty"<<endl;
        return head;
    }

    Node* curr = head;
    while (curr != NULL) {
        if((curr->next!=NULL) && (curr->data==curr->next->data)){
            Node* next_next = curr->next->next;
            Node* nodeToDelete= curr->next;
            delete nodeToDelete;
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Node* node1=new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next;

    Node* head= node1;
    //InsertAtHead(head,12);
    //print(head);
    Node* tail=node1;
    //print(tail);
    InsertAtTail(tail,14);
    InsertAtTail(tail,19);
    InsertAtTail(tail,29);
    //print(head);
    //InsertAtPosition(head,tail,16,2);
    //InsertAtPosition(head,tail,21,4);
    //deleteNode(head,tail,4);
    print(head);
    //print(head);
    //deleteNodeWithValue(head,tail,21);
    //cout<<"head "<<head->data<<endl;
    //cout<<"tail "<<tail->data<<endl;
    //ReverseRecursion(head);
    //Node* mid=getMiddle2(head);
    //Node* reverseHead=kReverse(head,2);
    //print(reverseHead);
    //cout<<mid->data;
    //cout<<isCircularList(head);
    //tail->next=head->next; 
    //cout<<detectLoop(head);
    //Node* aj= floydDetectLoop(head);
    //cout<<aj->data<<endl;
    //Node* loop=getStartingNode(head);
    //cout<<"Loop starts at: "<< loop->data<<endl;
    //removeLoop(head);
    //print(head);
    


    return 0;
}