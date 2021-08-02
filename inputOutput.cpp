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

    cout<<"The sum of num1 and num2 : "<<num1+num2;
    return 0;
}