#include<iostream>

/*
There are Two types of Header file: 
  1. System Header files : It comes with the compiler eg. <iostream>
  2. User defined Header files : It's written by us. to create our own header file .h extention is used.
*/

using namespace std;

int main(){
    // Today we'll learning about operators in C++
    int num1, num2;
    cin>>num1;
    cin>>num2;

    // Arthematic Operators
    cout<<"The Sum of num1 and num2 is : "<<num1+num2;
    cout<<"\nThe Product of num1 and num2 is : "<<num1*num2;
    cout<<"\nThe Difference of num1 and num2 is : "<<num1-num2;
    cout<<"\nThe division of num1 and num2 is : "<<num1/num2;
    cout<<"\nThe remainder of num1 and num2 is : "<<num1%num2;
    // num1++ will first print the value of it and then increment by 1
    cout<<"\nThe value of num1++ is : "<<num1++;
    // ++num2 will be increment first and then print the value of it
    cout<<"\nThe value of ++num2 is : "<<++num2;
    cout<<"\nThe value of num1-- is : "<<num1--;
    cout<<"\nThe value of --num2 is : "<<--num2;

    // Assignment Operators
    num1 = 43, num2 = 20;
    num1 += 42, num2 -= 21;
    cout<<"\nValue of num1 : "<<num1<<" and value of num2 : "<<num2;

    // Relation Operators and Logical Operators
    cout<<"\n\nIs num1 and num2 equal : "<<((num1==num2) || (num1>=num2));
    cout<<"\nIs num1 greater than num2  : "<<(num1>num2);
    cout<<"\nIs num1 less than num2 equal : "<<!(num1<num2);
    return 0;
}