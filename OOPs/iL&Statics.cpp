#include<iostream>

using namespace std;

// Initialization list in OOP is used in cases like we've to assign the value to an const variable inside the class
class Student{
    /* Some of the properity does only belongs to the class not to objects, like for class Student, totalStudent is an properity which 
        should only belong to the class, and to do so we have to declare that properity as static, by declaring a datamember or a method
        static it we be same/common for all the objects  */
    static int totalStudent ;
    public:
        int age;
        const int rollNo;

        Student(int rN, int a) : rollNo(rN), age(a){}; /* this is known as iniitializaton list which first sets the value to class's variable, 
        it is used in two cases when the class contain const variable and we've to set it by user input and other's when the class has 
        reference variable, because for both of them i.e. const & reference variable we've to initialize them at the time of it's creation. */
        
        void setAge(int a){
            this->age = a;
        }

        // To make the function constant write const after the name of function
        void display() const{
            cout<<"Age : "<<age<<" and RollNo : "<<rollNo<<endl;
        }

        /* Similarly we can also create an static function which will be accessible to all objects, but a static function can only use those    
            data members whch are static too e.g. totalStudent  */
        static void getTotal(){
            cout<<"No. of Total Students : "<< totalStudent<<endl;
        }
};

int Student :: totalStudent = 98; // we've to declare static data member outside the class else it'll throw error

int main(){

    Student s1(34, 18);
    s1.setAge(17);
    s1.display();
    // As we creates constants variable like const int a = 5; similarly we can also create const objects
    const Student s2(35, 19);           /* but by constant objects we can only call constants functions, Constant function are those which 
                                   doesn't change any properity of current object */
    s2.display();
    
    Student :: getTotal();

    return 0;
}