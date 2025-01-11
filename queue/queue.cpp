#include<iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int size;
        int front;
        int rear;
    public:
        Queue(int size){
            this->arr=new int(size);
            this->size=size;
            front=-1;
            rear=-1;
        }

        void enqueue(int elem){
            if(front==-1 && rear==-1){
                front++;
                rear++;
                arr[front]=elem;
                return;
            }
            if(rear>=size-1){
                cout<<"Overflow"<<endl;
                return;
            }
            else{
                arr[rear+1]=elem;
                rear++;
            }
        }

        void dequeue(){
            if(front==-1 && rear==-1){
                cout<<"Underflow"<<endl;
                return;
            }
            if(front==rear){
                cout<<"Element Dequeued is:"<<arr[front]<<endl;
                arr[front]=0;
                front=rear=-1;
                return;
            }
            cout<<"Element Dequeued is:"<<arr[front]<<endl;
            arr[front]=0;
            front++;
        }

        void peek(){
            if(front==-1){
                cout<<"Invalid Operation"<<endl;
                return;
            }
            cout<<"Peek element is:"<<arr[front]<<endl;
        }
        void display(){
        if(front==-1){
            cout<<"Empty Queue"<<endl;
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue que(5);
    que.enqueue(5);
    que.enqueue(6);
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(8);
    que.display();
    que.peek();
    //que.enqueue(9);
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    //que.dequeue();


}