#include<iostream>
using namespace std;

/* To optimize the functions of queue operations it's better to implement the Queue using linked list in forward order like
    1 -> 2 -> 3 -> 4 -> 5 where 1 is front/head and 5 is tail where insertion take places so all the queue operation will be
    of Time Complexity O(1) */
template <typename dT>
class Node{
    public:
        dT data;
        Node<dT> *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

template <typename dT>
class QueueLL{
    Node<dT> *head = NULL;
    Node<dT> *tail = NULL;
    int len = 0;
    public:
        void enqueue(dT data){
            Node<dT> *newNode = new Node<dT>(data);
            if (head==NULL) head = newNode;
            else tail->next = newNode;
            tail = newNode;
            len++;
        }

        bool isEmpty(){
            return len == 0;
        }

        dT dequeue(){
            if (isEmpty()){
                cout<<"Queue Empty!"<<endl;
                return 0;
            }
            Node<dT> *temp = head;
            dT data = head->data;
            head = head->next;
            delete temp;
            len--;
            return data;
        }

        dT front(){
            if (isEmpty()){
                cout<<"Queue Empty!"<<endl;
                return 0;
            }
            return head->data;
        }

        dT back(){
            if (isEmpty()){
                cout<<"Queue Empty!"<<endl;
                return 0;
            }
            return tail->data;
        }

        int size(){
            return len;
        }

        void printQueue(){
            if (head!=NULL){
                Node<dT> *temp = head;
                cout<<"\n--------------------\n ";
                while (temp->next!=NULL){
                    cout<<temp->data<<" | ";
                    temp = temp->next;
                }
                cout<<temp->data<<endl;
                cout<<"--------------------\n";
            }
        }

        ~QueueLL(){
            while (head!=NULL){
                Node<dT> *temp = head->next;
                delete head;
                head = temp;
            }
        }
};