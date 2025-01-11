#include<iostream>
using namespace std;

class deque{  //using circular array
    private:
    int size;
    int front;
    int rear;
    int *arr;

    public:
    deque(int sz){
        size=sz;
        front=-1;
        rear=-1;
        arr=new int(size);
    }

    void enqueueFront(int d){
        if((front==0 && rear==size-1 )||front==rear+1){
            cout<<"Queue is full..Overflow!"<<endl;
        }
        
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[front]=d;
        }
        else if(front==0){
            front=size-1;
            arr[front]=d;
        }
        else{
            front--;
            arr[front]=d;
        }
    }

    void enqueueRear(int d){
        if((front==0 && rear==size-1 )||front==rear+1){
            cout<<"Queue is full..Overflow!"<<endl;
        }
        
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[rear]=d;
        }
        else if(rear==size-1){
            rear=0;
            arr[rear]=d;
        }
        else{
            rear++;
            arr[rear]=d;
        }
    }

    void dequeueFront(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty..Underflow!!"<<endl;
        }
        else if(front==rear){
            cout<<"Dequeued element is: "<<arr[front]<<endl;
            arr[front]=0;
            front=rear=-1;
        }
        else if(front==size-1){
            cout<<"Dequeued element is: "<<arr[front]<<endl;
            arr[front]=0;
            front=0;
        }
        else{
            cout<<"Dequeued element is: "<<arr[front]<<endl;
            arr[front]=0;
            front++;
        }
    }

    void dequeueRear(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty..Underflow!!"<<endl;
        }
        else if(front==rear){
            cout<<"Dequeued element is: "<<arr[rear]<<endl;
            arr[rear]=0;
            front=rear=-1;
        }
        else if(rear==0){
            cout<<"Dequeued element is: "<<arr[rear]<<endl;
            arr[rear]=0;
            rear=size-1;
        }
        else{
            cout<<"Dequeued element is: "<<arr[rear]<<endl;
            arr[rear]=0;
            rear--;
        }
    }
    void display(){
        int i= front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
        cout<<arr[rear]<<endl;
    }
};

int main(){
    deque que(5);

    que.enqueueFront(5);
    que.enqueueFront(15);
    que.enqueueFront(25);
    que.enqueueRear(58);
    //que.enqueueFront(65);
    que.enqueueRear(65);

    que.display();
     
    que.dequeueFront();
    que.display();
    
    que.dequeueRear();
    que.display();
}