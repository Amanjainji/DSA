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

void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next = temp;
    tail=temp;
}

Node* findMid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL || fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
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

void printCircular(Node* head){
    Node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl<<endl;
}
/*
void RemoveDuplicates(Node* head) {
    if (head == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* curr = head;
    while (curr != NULL) {
        if((curr->next!=NULL) && (curr->data==curr->next->data)){
            Node* next_next = curr->next->next;
            Node* nodeToDelete= curr->next;
            nodeToDelete->next=NULL;
            delete nodeToDelete;
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return;
}

void RemoveDuplicatesUnsorted(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        Node* runner = curr;
        while (runner->next != NULL) {
            if (curr->data == runner->next->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                temp->next=NULL; //memory leak
                delete temp;
            } 
            else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

void RemoveDuplicatesMapUnsorted(Node* head){
    map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL) {
        if (visited[curr->data] == true) {
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            temp->next = NULL; //memory leak condn
            delete temp;
        } 
        else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}
*/
/*
Node* CircularListsHalves(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    int cnt=1;
    Node* temp=head;
    while(temp->next!=head){
        cnt++;  //length of list
        temp=temp->next;
    }
    cout<<cnt<<endl;
    int h1;
    if(cnt%2==0){h1=1;}  
    else{h1=0;}
    temp=head;
    Node* head2=temp;
    while(h1<(cnt/2)){
        temp=temp->next;
        head2=temp->next;
        h1++;    
    }
    temp->next=head; //first half list
    
    temp=head2;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head2; //second half list
    return head2;  
}
*/
/*
void sort012(Node* head){  //replacing values
    if(head==NULL || head->next==NULL){
        return;
    }
    Node* temp=head;
    int zeroCount=0,oneCount=0,twoCount=0;
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }
        else if(temp->data==2){
            twoCount++;
        }
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }
        else if(twoCount!=0){
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return;
}

void insertAtTailSort(Node* &tail,Node* temp){
    tail->next=temp;
    tail=temp;
}
void Sort012Nodes(Node* &head){
    //create three dummy nodes
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;

    Node* temp=head;
    //creating 3 lists
    while(temp!=NULL){
        if(temp->data==0){
            insertAtTailSort(zeroTail,temp);
        }
        else if(temp->data==1){
            insertAtTailSort(oneTail,temp);
        }
        else if(temp->data==2){
            insertAtTailSort(twoTail,temp);
        }
        temp=temp->next;
    }
    //merging 3 lists
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
        oneTail->next=twoHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }
    twoTail->next=NULL;

    //updating head
    head=zeroHead->next;

    //delete dummy nodes
    zeroHead->next=NULL;
    delete zeroHead;
    oneHead->next=NULL;
    delete oneHead;
    twoHead->next=NULL;
    delete twoHead;
}
*/
/*
Node* solve(Node* first,Node* second){
    //if first list only have one node
    if(first->next ==NULL){
        first->next=second;
        return first;
    }

    Node* curr1= first;
    Node* next1= curr1->next;

    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 !=NULL && curr2!=NULL){
        if((curr2 ->data>= curr1 ->data)&&(curr2 ->data <= next1->data)){
            //add node in between the node of first list
            curr1->next =curr2;
            next2 = curr2->next;
            curr2->next = next1;
            //updating pointer
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1 =next1;
            next1 =next1->next;
            if(next1==NULL){       //first list over
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}

Node* merge2SortedList(Node* head1,Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<= head2->data){
        return solve(head1,head2);
    }
    else{
        return solve(head2,head1);
    }
}
*/
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

void insertAtHead(Node* &head,int k){
    if(head==NULL){
        Node* temp=new Node(k);
        head=temp;
        return;
    }
    Node* temp=new Node(k);
    temp->next=head;
    head=temp;
}

Node* reverseList(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

/*
bool checkPallindrome(Node* head){  //Approach 1   T.C.- O(N), S.C. - O(N)
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* reverseHead;
    Node* temp=head;
    while(temp!=NULL){
        int k=temp->data;
        insertAtHead(reverseHead,k);
        temp=temp->next;
    }
    temp=head;
    Node* temp1=reverseHead;
    while(temp!=NULL){
        if(temp->data!=temp1->data){
            return false;
        }
        temp=temp->next;
        temp1=temp1->next;
    }
    return true;
}


bool checkPallindrome2(Node* head){ //approach 2  T.C.-O(N)  S.C. - O(1)
    if(head==NULL || head->next==NULL){
        return true;
    }
    int ans=1;
    //find middle node
    int len=getLength(head);
    Node* temp=head;
    int cnt=0;
    while(cnt<len/2){
        temp=temp->next;
        cnt++;
    }
    //making two halves
    Node* temp2=reverseList(temp->next);
    Node* temp3=head;
    //checking
    while(temp2!=NULL){
        if(temp3->data!=temp2->data){
            ans=0;
            break;
        }
        temp3=temp3->next;
        temp2=temp2->next;
    }

    reverseList(temp->next); //reverse again to make list same as starting
    return ans;   
}
*/


Node* add(Node* first,Node* second){
    //for back to previous states of first and second
    Node* f= first;
    Node* s= second;

    //sum program:
    int carry=0;
    Node* ansHead=NULL;
    Node* ansTail= NULL;

    while(first!=NULL || second!=NULL || carry!=0){
        int val1=0;
        if(first!=NULL){
            val1=first->data;
        }

        int val2=0;
        if(second!=NULL){
            val2=second->data;
        }

        int sum=carry+ val1+val2;

        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;

        if(first!=NULL)
            first=first->next;
        if(second!=NULL)
            second=second->next;
    }
    
//previous state
    first=f;
    second=s;

    return ansHead;
}

Node* add2Lists(Node* first,Node* second){
    //reverse input linked list
    first=reverseList(first);
    second=reverseList(second);

    //add 2 LL
    Node* ans=add(first,second);
    
    //reverse ans
    ans=reverseList(ans);

    //back to previous state of first and second
    first=reverseList(first);
    second=reverseList(second);
    

    return ans;
}

int main(){
    Node* head1 = new Node(1); //sorted linked list and remove duplicates
    Node* tail=head1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,5);
    InsertAtTail(tail,8);
    //print(head1);
    //RemoveDuplicates(head1);
    //RemoveDuplicatesMapUnsorted(head1);

/* //circular halves question
    tail->next=head1; //circular
    Node* head2=CircularListsHalves(head1);
    printCircular(head1);
    printCircular(head2);
*/

/*
Node* head2 = new Node(0); //sorted linked list
Node* tail2=head2;
    InsertAtTail(tail2,2);
    InsertAtTail(tail2,0);
    InsertAtTail(tail2,0);
    InsertAtTail(tail2,0);
    InsertAtTail(tail2,0);
    InsertAtTail(tail2,2);
    //sort012(head2);
    Sort012Nodes(head2);
    print(head2);
*/
/*
Node* head3 = new Node(3); //sorted linked list
Node* tail3=head3;
    InsertAtTail(tail3,4);
    InsertAtTail(tail3,5);
    InsertAtTail(tail3,9);
    InsertAtTail(tail3,10);
    
    //Node* sorter=merge2SortedList(head1,head3);
    //print(sorter);
*/

/*
Node* head4 = new Node(1); 
Node* tail4=head4;
    InsertAtTail(tail4,2);
    InsertAtTail(tail4,3);
    InsertAtTail(tail4,3);
    InsertAtTail(tail4,2);
    InsertAtTail(tail4,1);
    cout<<checkPallindrome2(head4)<<endl;
*/   

  
    Node* first=new Node(9);
    Node* firstTail=first;
    InsertAtTail(firstTail,4);
    InsertAtTail(firstTail,5);

    Node* second=new Node(9);
    Node* secondTail=second;
    InsertAtTail(secondTail,5);

    Node* SumAnswer=add2Lists(first,second);
    print(SumAnswer);

    
    
    return 0;
   
}