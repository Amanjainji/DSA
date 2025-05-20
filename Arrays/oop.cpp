// C++ Program to illustrate the use of virtual inheritance
// to resolve the diamond problem in multiple inheritance
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    void fun() { cout << "Base" << endl; }
};

// Parent class 1 with virtual inheritance
class Parent1 : public Base {
public:
};

// Parent class 2 with virtual inheritance
class Parent2 : public Base {
public:
};

// Child class inheriting from both Parent1 and Parent2
class Child : public Parent1, public Parent2 {
};

int main()
{
    Child* obj = new Child();
    obj->Parent1::fun(); 
    return 0;
}

/*
#include <iostream>
using namespace std;

template <class T>
class Base {
 private:
  T val;

 public:
  void setVal(T a) { val = a; }
  T getVal(){return val;}
};

template <class T, class S>
class Derived : public Base<T> {
 private:
  S data;

 public:
  void setVal(T b) {
    Base<T>::setVal(b);
    data = b;
  }

  void display(){
    cout<<Base<T>::getVal()<<endl;
    cout<<this->data;
  }
};

int main(){
    Derived<int,bool> obj;
    obj.setVal(5);
    obj.display();
}
*/




/*#include <iostream>
using namespace std;

// Template function to print values of any type
template<class T>
void print(T value){
    // Output the value of the specified type
    cout << "Value: " << value << endl;
}

int main()
{
    // Call the print function with an integer argument
    print(10);

    // Call the print function with a double argument
    print(10.5);

    // Call the print function with a string literal
    // argument
    print("Hello");

    return 0;
}
*/


/*
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Calculator {
   private:
    T num1, num2;

   public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    void displayResult() {
        cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
        cout << num1 << " + " << num2 << " = " << add() << endl;
        cout << num1 << " - " << num2 << " = " << subtract() << endl;
        cout << num1 << " * " << num2 << " = " << multiply() << endl;
        cout << num1 << " / " << num2 << " = " << divide() << endl;
    }

    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply() { return num1 * num2; }
    T divide() { return num1 / num2; }
};

int main() {
    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl
         << "Float results:" << endl;
    floatCalc.displayResult();

    return 0;
}

*/





/*
class Base
{
    public:
    virtual ~Base(){
      cout << "Base Destructor\n"; 
    };     
};

class Derived:public Base
{
    public:
    ~Derived() 
    { 
        cout<< "Derived Destructor\n"; 
    }
}; 

int main()
{
    Base* b = new Derived;     // Upcasting
    delete b;
}

*/
 /*
// Time Class
class Time {
    int hour;
    int mins;
 
public:
    // Default Constructor
    Time()
    {
        hour = 0;
        mins = 0;
    }
 
    // Parameterized Constructor
    Time(int t)
    {
        hour = t / 60;
        mins = t % 60;
    }
 
    // Function to print the value
    // of class variables
    void Display()
    {
        cout << "Time = " << hour
             << " hrs and "
             << mins << " mins\n";
    }
};
 
// Driver Code
int main()
{
    // Object of Time class
    Time T1;
    int dur = 95;
 
    // Conversion of int type to
    // class type
    T1=dur;
    T1.Display();
 
    return 0;
}
*/















/*#include<iostream>
using namespace std;

class weight {
  int kilogram;
  int gram;
  public:
    void getdata();
    void putdata();
    weight sum_weight(weight);
};

void weight::getdata() {
  cout<<"\nKilograms:";
  cin>>kilogram;
  cout<<"Grams:";
  cin>>gram;
}

void weight::putdata() {
   cout<<kilogram<<" Kgs. and "<<gram<<" gms.\n";
}

weight weight::sum_weight(weight w2) {
  weight temp;
  temp.gram = gram + w2.gram;
  temp.kilogram=temp.gram/1000;
  temp.gram=temp.gram%1000;
  temp.kilogram+=kilogram+w2.kilogram;
  return(temp);
}

int main() {
  weight w1, w2, w3;
  cout<<"Enter weight in kilograms and grams\n";
  cout<<"\n Enter weight #1" ;
  w1.getdata();
  cout<<" \n Enter weight #2" ;
  w2.getdata();
  w3 = w1.sum_weight(w2);
  cout<<"\n Weight #1 = ";
  w1.putdata();
  cout<<"Weight #2 = ";
  w2.putdata();
  cout<<"Total Weight = ";
  w3.putdata();
  return 0;
}
*/