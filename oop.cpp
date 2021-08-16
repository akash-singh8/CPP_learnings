#include<iostream>

using namespace std;

class Employee{
    static int noOfEmployee;
    // noOfEmployee is the static data member(variable) of class Employee, similary like this we can create static function which can be execute without creating any objects.

    string name;
    int empId;
    friend Employee addPartner(Employee e1, Employee e2);
    public:
        void setEmployee(string eName, int Eid){
            name = eName;
            empId = Eid;
            noOfEmployee += 1;
        };
        void getEmployee(void){
            cout<<"Number of Employee : "<<noOfEmployee<<endl;
            cout<<"Name : "<<name<<" and Id : "<<empId<<endl;
        }

        static void sayHello(void){
            cout<<"Hello Brother Welcome to our TEAM!"<<endl;
        }
};

int Employee :: noOfEmployee=0; // by default the value is also initialized to 0


// creating an function using class, yeah class can also be used to create function which'll return objects :
Employee addPartner(Employee e1, Employee e2){
    // since this function is using private members of class Complex we need to used keyword friend so that we can use the private variables!
    Employee e3;
    string name = e1.name + " - " + e2.name;
    e3.setEmployee(name, e1.empId+e2.empId);

    return e3;
}
/*
    The Friend function is not in the scope of class! this means the friend func can only access the private member and it cannot be called from the object of that class! and this can be called without any object. and it usually contains objects as arguments. It cannot access the private members directly by their name and need objName.memberName to access any member.
*/


int main(){
    Employee akash, alexa;
    akash.setEmployee("Akash", 12389);
    akash.getEmployee();

    alexa.setEmployee("Alexa", 3892);
    alexa.getEmployee();

    // to use the static method created inside class Employee the:
    Employee::sayHello();

    cout<<endl;

    // Arrays of objects 
    // Employee class is like a dataType! we use it in a same a way as we use int, float etc. and they are also an class! like we do int varName; similary we do className(i.e. Employee) varName; varName is an object in both cases
    Employee codeX[2];
    for (int i=0; i<2; i++){
        string name;
        cout<<"Enter the Name of Employee : ";
        cin>>name;
        codeX[i].setEmployee(name, i);
        codeX[i].getEmployee();
    }

    Employee jodi = addPartner(akash, alexa);
    jodi.getEmployee();

    return 0;
}