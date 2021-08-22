#include <iostream>

using namespace std;

#define Pi 3.14;  // the main advantage of this is it doesn't take any space in memory bts the compiler assigns 3.14 wherever Pi has been used so it's better than using an variable and 3.14 directly, and also improves performance of the programs as we don't have to go and access the value in memory like in case of variable.
// define and include also knows as preprocessor directives as it does everything at compile time.

inline int maxNum(int num1, int num2){
    return (num1 > num2) ? num1 : num2;
}
/* inline funciton is similar as #define it means wherever it has been used the return value will be assigned to it and the 
    actual parameters will be assigned to given parameters at compile time - so it'll be more efficient than norman function. 
    Inline function should not be more than 2-3 lines else the executable file will become bulky and compiler may not take it
    as inline function . */

int main(){

    cout<<Pi;
    int a=4, b=5;
    // cin>>a>>b;
    int c = maxNum(a, b);
    cout<<endl<<c<<endl;

    // Constant Variables 
    const int num = 10;  // we've to initialize while declaring it as it's an constant
    cout<<num<<endl;

    int j = 14; 
    const int &k = j;
    j++;
    cout<<j<<" "<<k<<endl;
    // this time the storage isn't constant but the path of k is, so we can change the storage using j's path.

    int const j1 = 15;
    /* int &k1 = j1; this'll give an error as j itself hasn't any right to change the memory so how can it give the rights to 
    other variable to change them, so by j1 path we can only read the value else if we want to create an reference we have to 
    also make it of a constant path. this rule is same to an pointer pointing to constant dataType, but in the case of pointer 
    we can change the address stored in poitner p=&j ; if pointer is only const to integer i.e. int const *p=&i; 
    */

    return 0;
}