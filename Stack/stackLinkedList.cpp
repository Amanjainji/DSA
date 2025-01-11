#include<iostream>
using namespace std;
 
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        next=NULL;
    }
};

class Stack{
    public:
    Node* node;  //head
    int top;
    int size;

    Stack(int s){
        this->size=s;
        top=-1;
        node= NULL; 
    }

    void push(int element) {
        if (top < size - 1) {
            if (node == NULL) {
                node = new Node(element);
            } 
            
            else {
                Node* temp = node;
                while (temp->next != nullptr) {
                    temp = temp->next; // last node
                }
                temp->next = new Node(element);
            }
            top++;
        } 
        else{
            cout << "Stack Overflow!!" << endl;
        }
    }

    void pop(){
        if(top>=0){
            if(node->next==NULL){  //one node
                delete node;
                node=NULL;
            }
            else{
            Node* temp = node;
                while (temp->next->next != NULL) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
            top--;
        }    
        else{
            cout<<"Stack Underflow!!"<<endl;
        }
    }

    void peek(){
        if(top>=0){
            Node* temp=node;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            cout<<"Top Element is:"<<temp->data<<endl;
        }
        else{
            cout<<"Stack is Empty!!"<<endl;
        }
    }

    void isEmpty(){
        if(top<0){
            cout<<"Stack is Empty!!"<<endl;
        }
        else{
            cout<<"Stack is not Empty!!"<<endl;
        }
    }
};

void print(Stack s,Node* node){
    if(node==NULL){
        return;
    }
    print(s,node->next);
    cout<<node->data<<" ";
}


int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    print(s,s.node);
    //s.peek();
    //s.isEmpty();


}