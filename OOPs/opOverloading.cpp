#include<iostream>
using namespace std;

/* Operator overloading in C++ : 
    -> C++ allows us to specify more than one definition for an operator in same scope .
    -> We can redefine or overload most of built-in operator available in c++
    -> It is a type of Polymorphism in which an operator is overloaded to give user defined meaning of it
    -> Soem operators in C++ can be overloaded like Scope(::), sizeof, memberSelector(.), pointer(*) and ternary Operator(?:) 
*/

class Complex{
    int real;
    int imaginary;
    public:
        Complex(int real, int imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }

        Complex add(Complex const &c){
            int real = this->real + c.real;
            int imaginary = this->imaginary + c.imaginary;
            Complex comp(real, imaginary);
            return comp;
        }
        // Writing the same add method using operator overloading
        Complex operator+(Complex const &c){
            int real = this->real + c.real;
            int imag = this->imaginary + c.imaginary;
            Complex com(real, imag);
            return com;
        }

        //Overloading == operator
        void operator==(Complex const &c){
            if (real==c.real && imaginary==c.imaginary){
                cout<<"Equal"<<endl;
            }
            else{
                cout<<"Not Equal"<<endl;
            }
        }

        // Overloading ++num (pre-increment) operator
        Complex operator++(){
            real++;
            imaginary++;
            return *this;
        }

        void display(){
            cout<<real<<" + "<<imaginary<<"i\n";
        }

        // Overloading num++ (post increment) operator, to do so it also have int as an argument else it'll be treated as pre Increment
        Complex operator++(int){
            Complex c(real, imaginary);
            real++;
            imaginary++;
            return c;
        }

};

// int operator+(int a, int b){
//     return a*b;
// }

int main(){

    Complex c1(4, 5);
    Complex c2 = Complex(9, 11);
    Complex c3 = c1+c2;
    Complex c4 = c1.add(c2);
    c1.display();
    c2.display();
    c3.display();    
    c4.display();

    // We can also use operator on more than one objects like we do in 3+4+5
    Complex c5 = c1+c2+c3;
    c5.display();
    c1==c2;
    c3==c4;
    
    // Using overloaded pre-increment operator
    Complex c6 = ++c1;
    c1.display();
    c6.display();

    // Using overloaded post-increment operator
    Complex c7 = c2++;
    c2.display();
    c7.display();


    return 0;
}