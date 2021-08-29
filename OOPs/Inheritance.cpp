#include<iostream>

using namespace std;

/* Inheritance in Object Oriented Programming :
    so basically Inheritance means, when a class2 is inheriting class1 so all the functions/Constructor can also be
    invoked by class2 as it inherited class1
    ~The concept of reusibility in C++ is suported using inheritance
    ~The class which we inheriting is known as Base Class.
    ~and The class which is inheriting is known as Derived Class.

   Their are different Types of Inheritance in OOP : 
    ~ Single Inheritance : A derived class with only one base class.
        e.g. an Programmer class is inheriting Employee class.
    ~ Multiple Inheritance : A derived class with more than one base class.
        e.g. an Programmer class is inheriting Employee and Manager class.
    ~ Hirarchical Inheritance : Several derived classes from a single class.
        e.g. Programmer and Manager is inherited from Employee.
    ~ Multilevel Inheritance : Deriving a class from already Derived class.
        e.g. Programmer inherited from Employee and Manager is inherited from Programmer.
    ~ Hybrid Inheritance is combination of Multiple Inheritance,  Multilevel Inheritance..
*/

// Inheritance Syntax and Visibility Mode in C++
// Creating a base class : 
class Employee{
    /* proctected are the access modifier like Private/Public but it's like medium private, means only base & derived class can 
    access the variables/members inside proctected. Outside the base & derived class we can't access it. */
    protected:
        string name;
    // so now whenever the Employee class'll be inherited, only derived class can make change to name variable.
    private: 
        int sal;

    public:
        Employee(string Ename, int salary){
            name = Ename;
            sal = salary;
        }
        // for base class default constructor is important as we inherit it, automatically it's constructor's called!
        Employee(){}
        void display(){
            cout<<name<<" "<<sal<<endl;
        }
};

// Syntax for Creating a Derived Class.
/*  class <drivedClassName> : <visibilityMode> <baseClassName>{
        `Class Member, function, methods`
      }
*/
/* <visibilityMode> can be Public or Private,if it's Public then the public members of Base Class  will be public for  
    Derived class whereas if it's Private then the public members of Base Class will be private for derived class means we can 
    use those methods only inside the class.
    -ByDefault the Visibility Mode is Private
    - Private Members of Base Class can't be inherited, to access the private variables/members of base class we can easliy 
        do it by creating a function/member which will return that or change that.
    - if the visibility of derived class is proctected, similary all the public member of base class will be proctected for the
        derived class and we can't use it outside the base class and it's derived class. bitch Multilevel Inheritence.
*/

// Creating a Derived Class Programmer by inheriting Employee
class Programmer : Employee{
    public: 
        Programmer(string Pname){
            name = Pname;
        }
        void greet(){
            cout<<"Hello Noob Coder!"<<name<<endl;
        }
};


int main(){
    Employee emp1("Akash", 1000);
    emp1.display();
    Programmer akii("CoderBruh");
    akii.greet();


    return 0;
}