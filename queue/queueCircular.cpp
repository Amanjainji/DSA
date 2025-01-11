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

        void enqueue(int d){
            if(front==-1 && rear==-1){
                front=rear=0;
                arr[rear]=d;
            }

            else if(((rear+1)%size)==front){
                cout<<"Queue is full"<<endl;
            }

            else{
                rear=(rear+1)%size;
                arr[rear]=d;
            }
        }

        void dequeue(){
            if(front==-1 && rear==-1){
                cout<<"Underflow!!"<<endl;
            }

            else if(front==rear){
                cout<<"Element dequeued is: "<<arr[front]<<endl;
                arr[front]=0;
                front=rear=-1;
            }

            else{
                cout<<"Element dequeued is: "<<arr[front]<<endl;
                arr[front]=0;
                front=(front+1)%size;
            }
        }

        void display(){
            int i=front;
            if(front==-1 && rear==-1){
                cout<<"Queue is empty"<<endl;
            }
            else{
                while(i!=rear){
                    cout<<arr[i]<<" ";
                    i=(i+1)%size;
                }
            }
            cout<<arr[rear]<<endl;
        }
};

int main(){
    Queue que(5);

    que.enqueue(15);
    que.enqueue(25);
    que.enqueue(35);
    que.enqueue(45);
    que.enqueue(55);
    que.enqueue(45);

    que.display();

    que.dequeue();
    que.dequeue();
    que.dequeue();
    //que.dequeue();

    que.enqueue(30);
    que.enqueue(40);
    que.display();
    

}