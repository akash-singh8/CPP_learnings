#include<iostream>
// In order to use inbuild Stack first we've to include the header file named stack
#include<stack>
/* Inbuilt Stact has all the function like push(), pop(), top(), size() & empty() but the only change in inbuilt Stack is that the pop() 
   only deletes the top item & don't return it! and It's also created using templates so we also have to pass dataType as parameter  */
using namespace std;

int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    cout<<"Size : "<<stk.size()<<endl;
    cout<<"Empty : "<<stk.empty()<<endl;
    cout<<stk.top()<<endl;
    stk.pop();        // it only deletes the last item and will not return it, so don't print it!
    stk.pop();
    stk.pop();
    stk.pop();
    cout<<"Size : "<<stk.size()<<endl;
    cout<<"Empty : "<<stk.empty()<<endl;
    cout<<stk.top()<<endl;

    

    return 0;
}