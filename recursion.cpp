#include<iostream>

using namespace std;

// Recursive function to find sum upto n number
int sum(int num){
    
    if (num <= 1){
        return num;
    }
    return num+sum(num-1);

}


// calculate n raise to power p using recursion
int power(int num, int exp){
    if (exp == 2){
        return num*num;
    }
    return num*power(num, exp-1);
}


// write a recursive function to find factorial of given number
int factorial(int num){
    if (num==0){
        return 1;
    }
    return num*factorial(num-1);
}


// Print the number in sequence using recursion 
void IncrSeq(int num){
    if (num == 1){
        cout<<1<<" ";
        return;
    }
    IncrSeq(num-1);
    cout<<num<<" ";
}

void DecrSeq(int num){
    cout<<num<<" ";
    if (num==1){
        return;
    }
    DecrSeq(num-1);
}


int main(){
    
    // Recursion : When a function call itself it's known as recursion, the main use of it to break a problems into sub problem and solve it one by one, almost every recursive has an base case means the end point where we want to stop and start returning the solutions.
    int num;
    cin>>num;
    cout<<"factorial : "<<factorial(num)<<endl;
    cout<<"Sum : "<<sum(num)<<endl;
    cout<<"Power : "<<power(num, 3)<<endl;
    IncrSeq(num);
    cout<<endl;
    DecrSeq(num);
    return 0;

}