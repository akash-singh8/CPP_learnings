#include<iostream>

using namespace std;


/* Object Oriented Programming : 
    Classes : A class is basically an blueprint/template using which we can create objects having all the properties of that class.
    ->A class name is similar as a dataType because for creating an integer we do int num; whereas to create an object using class name, we do 
      className obj; which is like creating an int, float... 
    ->As we create an int like int num; it takes some space(4bytes) in memory similarly as we create an class object it also takes some space
      in memory which depends on the size of variable does the class contain.
    
    Access Modifiers : It take care of, where we can access the variable & methods of class.
     1. Private : we can access it only inside the class (by default it is Private)
     2. Public : It is accessible through the whole program.
     3. Protected : It is accessible inside class and all the derived class(class inherited from that)
*/

class Student {
    int rollNo;
    string name;

    public:
        void getData(){
            cout<<name<<" "<<rollNo<<endl;
        }

        /* Here's a question arises what's the benefit of making rollNo and name private variable if we can simple access it & change it 
           using getters & setters, so the main reason to use is that we can set some constraints to set the value of private variable using 
           setters like in rollNo we can set a condition if the rollNo is -ve don't set the value of it. */
        void setData(string n, int rN){
            name = n;
            if (rN<0){
                rollNo = -1;
                return;
            }
            rollNo = rN;
        }
} ;


int main(){
    // Creating an Object in Static Memory
    Student s1;
    s1.setData("Akash", -2);
    s1.getData();

    // The space taken by the object will almost equal to the total size of variable the class has. 
    cout<<sizeof(s1)<<endl;

    /* Creating an Object using Dynamic Memory (or in Heap Memory) : 
        It's similar as creating an int/float... in heap memory e.g. int *p = new int; */
    Student *s2 = new Student;
    /* remember s2 is just an pointer variable(of size 8bytes and store in static memory) which stores the address of object created in heap 
    memory, we are using Student as a dataType to create a pointer because since it also has some specific memory so while accessing the data 
    using pointer, it should know upto which byte it has to read the data */
    (*s2).setData("Selena", 43);
    // another way to access the methods/function or variable of object's class which is in heapMemory is objName->setData("selena", 43);
    s2->getData();

    delete s2;

    return 0;
}