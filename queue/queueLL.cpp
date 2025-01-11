#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int elem){
            data=elem;
            next=NULL;
        }

        ~Node(){
            if(this->next!=NULL){
                this->next=NULL;
                delete next;
            }
        }
};

class Queue{
    private:
        Node* front;
        Node* rear;
        int size;

    public:

        Queue(int sz){
            front=rear=NULL;
            size=sz;
        }

        void enqueue(int d){
            int cnt=0;
            Node* temp=front;
            while(temp!=NULL){
                cnt++;
                temp=temp->next;
            }
            if(cnt==size){
                cout<<"Overflow!!"<<endl;
                return;
            }

            if(front==NULL){
                front=new Node(d);
                rear=front;
                return;
            }

            Node* newNode=new Node(d);
            rear->next=newNode;
            rear=newNode;
        }

        void dequeue(){
            if(front==NULL){        //empty queue
                cout<<"Underflow!!"<<endl;
                return;
            }
            if(front==rear){        // single element in queue
                Node* temp=front;
                front=rear=NULL;
                cout<<"Element Dequeued is: "<<temp->data<<endl;
                temp->next=NULL;
                delete temp;
                return;   
            }

            Node* temp=front;
            front=front->next;
            cout<<"Element Dequeued is: "<<temp->data<<endl;
            temp->next=NULL;
            delete temp;
        }

void display(){
    if(front==NULL){
        cout<<"Empty queue"<<endl;
    }
    else{
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void peek(){
    if(front==NULL){
        cout<<"Empty queue...No peek"<<endl;
    }
    else{
        cout<<"Peek element is:"<<front->data<<endl;
    }
}


};

int main(){
    Queue que(5);
    que.enqueue(12);
    que.enqueue(13);
    que.enqueue(1);
    que.enqueue(22);
    que.enqueue(24);
    //que.enqueue(22);
    que.display();
    que.peek();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    //que.dequeue();
    //que.display();


}