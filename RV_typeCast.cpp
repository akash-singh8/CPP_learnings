#include<iostream>

using namespace std;


void increment(int &num){
    num++;
}


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
  int i = 65;
  int j = i;

  i++;
  // i and j are currently in different memory location so on changing the value of one other will remain same
  cout<<i<<" "<<j<<endl;

  // if we want to change both while changing value of one varialbe, for that we use reference variable : int &<var>
  int x = 21;
  x++;
  int &y = x; // this means y is just reference to an existing memory
  cout<<x<<" "<<y<<endl;  // and the memory address of both x and y will be same

  // the use of reference variable is to pass it to the function in which we want to reflect the changes, and it known as pass by reference. we can also use pointers but to takes extra space in memory whereas a reference variable points to existing memory so it'll have better space complexity.
  int z = 42;
  cout<<z<<" ";
  increment(z);
  cout<<z<<endl;

  // Type Casting -> changing the data type of variable
  float num = 4.54f;
  cout<<"The value of num is : "<<(int)num<<endl;
  // OR
  cout<<"The value of num is : "<<int(num);
  return 0;
}