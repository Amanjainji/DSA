#include<iostream>
using namespace std;
#define Stacksize 50
class stack{
    public:
    int top;
    int *arr;

    stack(){
        top=-1;
        arr=new int(Stacksize);
    }

    void push(int d){
        if(top==Stacksize-1){
            cout<<"Overflow!!"<<endl;
            return;
        }
        top++;
        arr[top]=d;
    }

    int pop(){
        if(top<0){
            cout<<"Underflow!!"<<endl;
            return -1;
        }
        int k=arr[top];
        arr[top]=0;
        top--;
        return k;
    }
};
int count=0;
class Queue{
    private:
    stack s1;
    stack s2;   
    int Size;

    public: 
        Queue(int sz){
            Size=sz;
        }

        void enqueue(int d){
            if(count==Size){
                cout<<"Overflow"<<endl;
                return;
            }
            s1.push(d);
            count++;
        }

        void dequeue(){
            if(s1.top==-1 && s2.top==-1){
                cout<<"Underflow"<<endl;
                return;
            }
            int i;
            for(int i=0;i<count;i++){
                s2.push(s1.pop());
            }
            cout<<"Dequeued element is:"<<s2.pop()<<endl;
            count--;
            for(int i=0;i<count;i++){
                s1.push(s2.pop());
            }
        }

        void display(){
            if(s1.top==-1){
                cout<<"Empty queue!"<<endl;
            }
            else{
                for(int i=0;i<=s1.top;i++){
                    cout<<s1.arr[i]<<" ";
                }
                cout<<endl;
            }
        } 
};

int main(){
    Queue que(5);
    que.enqueue(62);
    que.enqueue(56);
    que.enqueue(60);
    que.enqueue(36);
    que.enqueue(26);
    
    que.dequeue();
    que.display();

    que.dequeue();
    que.display();

    que.dequeue();
    que.display();

    que.dequeue();
    que.display();

    que.dequeue();
    que.display();
    
    que.dequeue();
}

