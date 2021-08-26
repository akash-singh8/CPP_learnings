#include <iostream>

using namespace std;

// Recursive program to print the number from 1 to n
// we are using tail recursion in it as we first want to call recursive func & while returning we'll print the numbers.
void printSeq(int num){
    if (num==0){
        return;
    }
    printSeq(num-1);
    cout<<num<<" ";
}

// recursive factorial function
int factorial(int num){
    if (num==0){
        return 1;
    }
    int smallerFact = factorial(num-1);
    return num*smallerFact;
}

// recursive fibonacci function
int fibonacci(int num){
    if (num==0 || num==1){
        return num;
    }
    int smallFibo1 = fibonacci(num-1);
    int smallFibo2 = fibonacci(num-2);
    return smallFibo1+smallFibo2;
}

// print spelling recursive function
string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
void print(int num){
    if (num == 0){
        return;
    }
    print(num/10);
    cout<<arr[num%10]<<" ";
}

// power of number using recursion
int power(int num, int pow){
    if (pow==0){
        return 1;
    }
    int smallPowOfNum = power(num, pow-1);
    return num*smallPowOfNum;
}

int main(){
    int num;
    cin>>num;
    print(num);
}

