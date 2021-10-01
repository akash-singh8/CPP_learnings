#include<iostream>

using namespace std;

/* Constructor in OOPs : 
    -> Constructor is function/method of class which automatically invoked(called) as we create an object using that class. e.g. as we create o
        object e.g. Student.s1; internally s1.Student() statement called automatically which is an constructor.
        -> It has same name as class.
        -> No return type.
        -> We can also input some arguments using constructor to assign value to private variable. 
*/

class Student{
    int rollNo = -1;
    int age;
    public :
        Student(){
            cout<<"Constructor called!"<<endl;
        }
        /* We can also create more than one constructor but they should have different no./dataTypes of parameters this is also known as 
           constructor overloading in which the constructor which matches the given dataType & no. of parameters will invoked */
        Student(int rN){
            if (rN < 0){
                return;
            }
            rollNo = rN;
        }

      /*  this is an keyword which can only be used inside a class. this is an pointer which stores the address of current class's object 
          in memory, the main use of this keyword is when we want to represent only the class's variable, for e.g. a Constructor takes argument 
          named same as the private variable, so if we want to set the argument to private variable it'll not work in such case we can use 
          this-><private var> = <argument var> it'll successfully set the argument value to private variable  */
        Student(int rollNo, int age){
            // rollNo = rollNo;   it does nothing just access the local var rollNo & assign it to itself 
            this->rollNo = rollNo;
            this->age = age;
        }

        void display(){
            cout<<"The address of class's object in memory : "<<this<<endl;
            cout<<"Roll Number : "<<rollNo<< " and Age : "<<age<<endl<<endl;
        }

        /* Copy Constructor is used to copy the arguments of constructor of one object to other object, it's already present by default, 
           We can also create our own copy constructor */
        // Student(Student &stu){
        //     cout<<"Called Copy Constructor!"<<endl;
        //     this->rollNo = stu.rollNo;
        //     this->age = stu.age;
        // }

        /* Destructor is opposite to constructor means it invoked/executes when the scope of object comes to end, the main use of Destructor
           is to deallocate the memory of the variable inside the class which is created in heap memory, it has also same name as class */
        ~Student(){
            cout<<"Destructor called!"<<endl;
        }
};


int main(){

    Student s1;
    // As we create an object, Constructor will automatically invoked 
    cout<<"Address of s1 object : "<< &s1<<endl;
    s1.display();

    // Using constructor with object created in Heap memory, this time parameterized constructor will be invoked as we're passing some int val.
    Student *s2 = new Student(18, 34);
    (*s2).display();

    Student s3((*s2));      // The s2's constructor argument values will be copied to s3's constructor
    s3.display();
    // Another way to copy the constructor of an object to other after its creation is : obj1 = <sourceObj>;
    
    // Since s2's object is created in heap memory, for it Destructor will not be invoked until we deallocate it from heap memory.
    delete s2;
    
    // There's two way to call the constructor 1. Calling constructor explicitly
    Student obj = Student(34, 18);
    // or 2. Calling Constructor implicitly
    // Student obj(34, 18);


    return 0;
}