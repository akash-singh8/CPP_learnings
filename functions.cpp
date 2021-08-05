#include<iostream>

using namespace std;

/*
Syntax of an Function : 
    returnType functionName (parameter1, parameter2, ....){
        // function body
        return <returnType_Value>;
    }
  -> When a function does not return any value, in that case the return type of the
     function is ‘void’.
*/

void print(int value){
    cout<<value<<endl;
    return;
}


// Write a function to add two numbers;
int addNums(int num1, int num2){
    print(num1);
    print(num2);
    int sum = num1 + num2;
    return sum;
}

// the function call should be inside main() function because as we run the program the execution of main function starts first!
int main(){
    int value = addNums(5, 4);
    cout<<value<<endl;
    value = addNums(234, 51);
    cout<<value<<endl;

    return 0;
}

// It is important to return at the end of the function because it uses a fuctions stack in memory and when a function is called it pushed to the stack and only when it return some value then it'll be popped from the functions stack.