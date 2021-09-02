#include<iostream>

using namespace std;

/* Polymorphism in C++ : One name multiple forms/work
    Theree are two types of polymorphism in c++ 
     1. Compile Time Polymorphism : the decision has been taken at compile time(when we compile the program and create an      
                                    executabel file)
        -> e.g. Function Overloading and Operator Overloading.
     
     2. Run Time Polymorphism : the dicision is taken at Run time(when we all the executable file)
        -> e.g. virtual Function
    Initially I thought that Function/Constructor Overloading are also the example of Runtime Polymorphism, when the take 
    the arguments of it as user input, it was because when we input the value than it'll see that which function/Operator it 
    should invoke but I was wrong because also while we take arguments from user input we do specify the datatype of it, so at 
    the compile time it'll automatically match the function/Operator with correct dataType. That's it.
*/

class Employee{
    int salary;
    public:
        string name;
        /* if we make the diplay a virtual function than it'll overwrite the default behavious and in place of executing 
        display of base class it'll go for derived class, only if we're using an pointer of base class and pointing it to an 
        address of object of derived class */
        void virtual display(){
            cout<<"Hey My name is : "<<name<<" and I earns "<<salary<<endl;
        }
};

class Programmer : public Employee{
    public:
        string language;
        void display(){
            cout<<"Hey I'm "<<name<<" and I'm specilized in Language "<<language<<endl;
        }
};

int main(){
    // Base class pointers to derived class objects
    Programmer pg; // pg is an object of derived class programmer
    Employee * emptr = &pg;  // emptr is an pointer of type Employee(Base Class) storing the address of derived class
    // in such case whenever we want to access any member using poitner emptr it'll only invoke the member of Base class itself
    (*emptr).name = "Akash";   // it can also be written as emptr->name = "Akash";
    emptr->display();   // the display() function of base class will be called

    Programmer *ptr = &pg;
    ptr->language = "Python";
    ptr->display();

    return 0;
}