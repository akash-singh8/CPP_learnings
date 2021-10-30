#include<iostream>
#include"queueUsingArray.h"
#include"queueUsingLinkedList.h"

using namespace std;

int main(){

    QueueLL<char> que;
    que.front();
    que.enqueue(71);
    que.enqueue(72);
    que.enqueue(73);
    que.enqueue(74);
    que.enqueue(75);
    cout<<"Size : "<<que.size()<<endl;
    cout<<que.front()<<endl;
    cout<<que.back()<<endl;
    que.printQueue();
    cout<<que.dequeue()<<endl;
    cout<<que.dequeue()<<endl;
    cout<<que.front()<<endl;
    cout<<que.back()<<endl;
    cout<<"Size : "<<que.size()<<endl;
    que.printQueue();
    que.enqueue(76);
    que.enqueue(77);
    cout<<"Size : "<<que.size()<<endl;
    que.printQueue();

    return 0;
}