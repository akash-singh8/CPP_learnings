#include<iostream>
#include<queue>
using namespace std;

/* The difference in inbuilt queue and the queue created by us is that all the function's name in inbuilt queue is similar 
    as the funciton's name of inbuilt stack i.e. push(), pop(), size(), empty() and front(), also the dequeue i.e. top 
    funciton doesn't return the back of queue, it just delete last element         */

int main(){
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    cout<<que.front()<<endl;
    cout<<que.back()<<endl;
    cout<<"Size : "<<que.size()<<endl;
    cout<<"Is Queue empty : "<<que.empty()<<endl;
    que.pop();
    que.pop();
    cout<<que.front()<<endl;
    cout<<que.back()<<endl;
}