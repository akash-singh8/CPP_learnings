#include<iostream>

using namespace std;

int num3 = 32;

int main(){
  int num1, num2, num3;
  cout<<"Enter the Value of num1 : "<<endl;
  cin>>num1;
  cout<<"Enter the Value of num2 : "<<endl;
  cin>>num2;
  num3 = num1 + num2;
  cout<<"The sum is : "<<num3<<endl;
  // :: is known as scope resolution operator
  cout<<"The Global value of num3 is : "<<::num3;

  // Float and double literals
  float deci = 34.4f;
  double dob = 34.4l;
  cout<<"The Size of deci : "<<sizeof(deci)<<endl;
  cout<<"The Size of dob : "<<sizeof(dob)<<endl;

  // Reference Variables
  // Akash --> dipu --> bihari --> chota
  float x = 455;
  // now the y will refer to the value of x
  float & y = x;
  cout<<"The Value of x : "<<x<<"  sand The Value of y : "<<y<<endl;

  // Type Casting -> changing the data type of variable
  float num = 4.54f;
  cout<<"The value of num is : "<<(int)num<<endl;
  // OR
  cout<<"The value of num is : "<<int(num);
  return 0;
}