#include<iostream>

using namespace std;

int main(){
    int num1, num2;
    // << this is called insertion operator in C++
    cout<<"Enter value of Number 1 : \n";
    // cin is used to take inputs from user and >> is an extraction operator
    cin>>num1;
    cout<<"Enter value of Number 2: \n";
    cin>>num2;

    /* We can also give the both value as input at same time, because the way cin works is first while taking an input it 
    creates an input buffer(like an array of values) in which it stores all the input given by user separated by space and  
    after that it'll passed to the output buffer in which it stores all the outputs for given value and then it displays it,    
    so basically the cin statement doesn't read from the screen it reads from the input buffer, and cin doesn't read white 
    spaces because WS is an special character for cin, so in such case we do use get() function which does also read WS.
    */

    cout<<"The sum of num1 and num2 : "<<num1+num2;
    return 0;
}