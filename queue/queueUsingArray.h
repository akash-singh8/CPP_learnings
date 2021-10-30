#include<iostream>
using namespace std;

/* Queue is also an linear data structure which is of abstract dataType means the operations of it should performed only in
    some specific manner/order, in Queue it follows First In First Out(FIFO) means the item can only be inserted at the end 
    and removed from the front (FIFO) 
   Operation related to Queue : 
    1. Insertion -> Enqueue : Used to insert item in Queue
    2. Deletion -> Dequeue : used to remove item from Queue
    & Some other operation like front(), back(), size() and isEmpty().             */

class QueueN{
    int *queue;
    int len;
    int curr = 0;
    int frnt = 0;
    public:
        QueueN(int size){
            this->len = size;
            queue = new int[size];
        }

        bool isEmpty(){
            return curr == 0;
        }

        // this enqueue will take ~O(n) operation when the queue gets full and it's dequeued too!
        void enqueue(int data){
            if (curr==len){
                if (frnt!=0){
                    for (int i=0; i<curr-frnt; i++){
                        queue[i] = queue[frnt+i];
                    }
                    curr = (curr+1) - frnt;
                    queue[curr-1] = data;
                    frnt = 0;
                }
                else cout<<"Queue is Full!"<<endl;
                return;
            }
            queue[curr] = data;
            curr++;
        }
        

        int dequeue(){
            if (isEmpty()){
                cout<<"Queue is Empty!"<<endl;
                return 0;
            }
            frnt++;
            return queue[frnt-1];
        }

        int front(){
            if (isEmpty()) return -1;
            return queue[frnt];
        }

        int back(){
            if (isEmpty()) return -1;
            return queue[curr-1];
        }

        int size(){
            return curr;
        }

        void printQueue(){
            cout<<"--------------------"<<endl;
            for (int i=0; i<curr-1; i++){
                cout<<" "<<queue[i]<<" |";
            }
            cout<<" "<<queue[curr-1]<<endl;;
            cout<<"--------------------"<<endl;
        }
        
        ~QueueN(){
            // As the queue is creating Dynamically we also have to deallocate it manually 
            delete []queue;
        }
};

template <typename dT>
class Queue{
    dT *queue;
    int capacity;
    int len = 0;
    int curr = 0;
    int frnt = 0;
    public:
        Queue(int size){
            this->capacity = size;
            queue = new dT[size];
        }

        bool isEmpty(){
            return len == 0;
        }

        /* There's one other way to implement enqueue() function in O(1), this will function same as queue but we are 
        changing the order of inserting and deleting so that the enqueue operation can be optimized   */
        void enqueue(dT data){
            if (len == capacity){
                cout<<"Queue is Full!"<<endl;
                return;
            }
            queue[curr] = data;
            curr = (curr+1)%capacity; // this is hadle the currIndex if it's > capacity -> curr=0 else it'll be curr++
            len++;
        }

        dT dequeue(){
            if (isEmpty()){
                cout<<"Queue is Empty!"<<endl;
                return 0;
            }
            dT data = queue[frnt];
            frnt = (frnt+1)%capacity;
            len--;
            return data;
        }

        dT front(){
            if (isEmpty()){
                cout<<"Queue is Empty!"<<endl;
                return 0;
            };
            return queue[frnt];
        }

        dT back(){
            if (isEmpty()){
                cout<<"Queue is Empty!"<<endl;
                return 0;
            };
            return queue[curr-1];
        }

        int size(){
            return len;
        }

        void printQueue(){
            cout<<"--------------------"<<endl;
            if (!isEmpty()){
                int temp = (curr<=frnt)? capacity : curr;
                for (int i=frnt; i<temp; i++){
                    cout<<" "<<queue[i]<<" |";
                }
                if (curr<=frnt){
                    for(int i=0; i<curr; i++){
                        cout<<" "<<queue[i]<<" |";
                    }
                }
            }
            cout<<"\n--------------------"<<endl;
        }
        
        ~Queue(){
            delete []queue;
        }
};