#include <iostream>

using namespace std;

/* Template in C++ is used to pass the dataTypes as parameter to the classes and function, so that we don't have to rewrite 
    the whole class/function just for the change in dataType, the way it works in backend is when we starts compilation
    the compiler creates a same class/function for the dataType given as parameter(basically templates are expandet at compile
    time). This is like macros, but the difference is the compiler does type checking before template expantion(source code 
    contains only function/class but compiled code may contain multiple copies of function/class).
*/

// basic example of template function : taking a user input of any dataType and print it.
template <typename dataType>
void print(dataType value){
    cout<<value<<endl;
}

/* Using Function Templates, We write a generic function that can be used for different data types. Examples of function 
templates are sort(), max(), min(), printArray(), swap(). */
template <typename swapDT>
void mySwap(swapDT &fst, swapDT &sec){
    swapDT temp = fst;
    fst = sec;
    sec = temp;
}


// This will sort item of any dataType string, array of int/float/char.
template <typename sdT>
void letSort(sdT &s, int size){
    for (int i=1; i<size; i++){
        for (int j=0; j<size-i; j++){
            if (s[j]>s[j+1]){
                mySwap(s[j], s[j+1]);
            }
        }
    }
}


/* Similarly we can use template with class but this time it's mandatory to pass the dataType while create an object using that 
class example creating a class which will find min/max of two values of any dataType */
template <class DT>
class MathOP{
    DT val1, val2;
    public:
        MathOP(DT a, DT b){
            val1 = a;
            val2 = b;
        }
        DT myMin(){
            if (val1<val2){
                return val1;
            }
            return val2;
        }
        DT myMax(){
            if (val1>val2){
                return val1;
            }
            return val2;
        }
};


int main(){
    print<string>("Akash");
    /*At the compile time an indentical function will be created for the given dataType and then will be used, in this case a 
      same print() function will be created for string dataDype. In caes of using templates with function it's not mandatory to 
      pass the dataType, because the comiler automatically detects it. So we can simply write like : */
    print(4231);

    string name = "Akash Kumar Singh";
    letSort(name, 17);
    for (int i=0; i<17; i++){
        cout<<name[i]<<" ";
    }
    cout<<endl;

    // while creating the object it's mandatory to pass the dataType as parameter to template Class.
    MathOP <int> op(9, 8);
    print(op.myMax());
    print(op.myMin());

    return 0;
}