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


// Recursive function to replace pi to 3.14 in a string
string remPi(string str, string s="", int i=0){
    if (i==str.length()){
        return s;
    }
    if (str[i]=='p' && str[i+1]=='i'){
        s += "3.14";
        return remPi(str, s, i+2);
    }
    else{
        s += str[i];
        return remPi(str, s, i+1);
    }
}


// Given a string, compute recursively a new string where all 'x' chars have been removed.
string remX(string str, string s="", int i=0){
    if (i==str.length()){
        return s;
    }
    if (str[i]!='x'){
        s+= str[i];
    }
    return remX(str, s, i+1);
}


// Write a recursive function to convert a given string into the number it represents
int strToInt(string str, int n=0, int i=0){
    if (i==str.length()){
        return n;
    }
    n = n*10 + str[i]-48;
    return strToInt(str, n, i+1);
}


// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
string adjSep(string str, string s="", int i=0){
    if (i==str.length()){
        return s;
    }
    s += str[i];
    if (i<str.length()-1 &&str[i]==str[i+1]){
        s += '*';
    }
    return adjSep(str, s, i+1);
}


int main(){
    int num;
    cin>>num;
    print(num);
}

