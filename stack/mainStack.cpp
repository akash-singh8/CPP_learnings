#include<iostream>
#include "stackUsingArray.h"
#include "stackUsingLinkedList.h"

using namespace std;

int main(){
    // StackLL<int> stk;
    // stk.push(1);
    // stk.push(2);
    // stk.push(3);
    // stk.push(4);
    // stk.push(5);
    // stk.push(7);
    // cout<<"Size : "<<stk.size()<<endl;
    // cout<<stk.top()<<endl;
    // stk.printStack();
    // cout<<stk.pop()<<endl;
    // cout<<stk.pop()<<endl;
    // stk.push(6);
    // stk.push(5);
    // stk.printStack();

    StackLL<char> stk;
    cout<<stk.top()<<endl;
    stk.push('A');
    stk.push('k');
    stk.push('a');
    stk.push('s');
    stk.push('h');
    stk.push('m');
    cout<<stk.pop()<<endl;
    stk.printStack();
    

    return 0;
}