#include <iostream>
using namespace std;

class Node{
    public:
        int num;
        int expo;
        Node* next;   

        Node(int num,int expo){
            this->num=num;
            this->expo=expo;
            next=NULL;
        }
        
};

Node* SumPolynomial(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* answer=new Node(0,0); //dummy node

    Node* head=answer;

    while((temp1->expo)!=0 && (temp2->expo)!=0){
        int n=0;
        int k=0;
        if(temp1->expo==temp2->expo){
            n=temp1->num + temp2->num;
            k=temp1->expo;
        }
        Node* temp=new Node(n,k);
        answer->next=temp;
        answer=answer->next;

        temp1=temp1->next;
        temp2=temp2->next;       
    }
    if(temp1->expo==0 || temp2->expo==0){
        int s=temp1->num+temp2->num;
        Node* temp=new Node(s,0);
        answer->next=temp;
    }
    return head->next;
}

void display(Node* head){
    if(head==NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        if(temp->expo==0){
            cout<<temp->num;
            temp=temp->next;
        }
        else{
            cout<<temp->num<<"x^"<<temp->expo<<" + ";
            temp=temp->next;
        }
    }
    cout<<endl;
}


int main(){

    Node* head1=new Node(3,2);
    head1->next=new Node(5,1);
    head1->next->next=new Node(6,0);

    Node* head2=new Node(4,2);
    head2->next=new Node(2,1);
    head2->next->next=new Node(3,0);

    Node* head=SumPolynomial(head1,head2);
    display(head);

}