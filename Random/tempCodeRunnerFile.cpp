#include <iostream>
#include <vector>

using namespace std;

class rectangle{
    private:
    int length;
    int breadth;
    public:
    rectangle(){
        length=1;
        breadth=1;
    }
    rectangle(int l,int b){
        length=l;
        breadth=b;
    }

    int area(){
        return length*breadth;
    }
};

int main(){
    rectangle r1(5,10);
    cout<<"area is: "<<r1.area()<<endl;
}