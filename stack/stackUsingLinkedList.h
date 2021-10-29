#include<iostream>
using namespace std;

template <class dt>
class Node{
    public:
        dt data;
        Node<dt> *next = NULL;
        Node(){}
        Node(dt data){
            this->data = data;
        }
};

template <class dT>
class Stackll{
    Node<dT> *head = NULL;
    Node<dT> *tail = NULL;
    int len=0;
    // A helper function to print the Stack created using linked list
    void helper(Node<dT> *curr){
        if (curr==NULL) return;
        helper(curr->next);
        cout<<"| "<<curr->data<<" |"<<endl;
        cout<<"'---'"<<endl;
    }
    public:
        void push(dT data){
            Node<dT> *newNode = new Node<dT>(data);
            if (head==NULL) head = newNode;
            else tail->next = newNode;
            tail = newNode;
            len++;
        }

        bool isEmpty(){
            return head==NULL;
        }

        dT pop(){
            if (isEmpty()){
                cout<<"Stack UnderFlow!"<<endl;
                return 0;
            }
            Node<dT> *temp = tail;
            tail = head;
            if (tail->next==NULL) head=NULL;
            else{
                while (tail->next!=temp){
                    tail = tail->next;
                }
            }
            tail->next = NULL;
            dT data = temp->data;
            delete temp;
            len--;
            return data;
        }

        dT top(){
            if (isEmpty()){
                cout<<"Stack is Empty!"<<endl;
                return 0;
            }
            return tail->data;
        }
        
        int size(){
            return len;
        }

        void printStack(){
            Node<dT> *curr = head;
            helper(curr);
        }
        /* Creating a Destructor which will delete the whole Stack, since this time we have created it using Linked list we have to 
           dynamically deallocate all the Nodes in linked list from Heap memory */
        ~Stackll(){
            while(head!=NULL){
                Node<dT> *temp = head->next;
                delete head;
                head = temp;
            }
        }
};


/* The problem with above class is the pop() function will take o(n) operations since we are implementing the stack using linked list int 
order 1->2->3->4->5 to pop() we have to traverse from head to tail-1 then only we can delete the last Node, There's one way to optimize is 
that is to create linked list in reversed order like 5->4->3->2->1 where the head is pointing to last item, so to pop() through stack we \
just only have to delete head and move head to head->next thus the Time complexity will be O(1);
*/
template <class dT>
class StackLL{
    Node<dT> *head = NULL;
    int len = 0;
    public:
        void push(dT data){
            Node<dT> *newNode = new Node<dT>(data);
            newNode->next = head;
            head = newNode;
            len++;
        }

        bool isEmpty(){
            return head==NULL;
        }

        dT pop(){
            if (isEmpty()){
                cout<<"Stack UnderFlow!"<<endl;
                return 0;
            }
            dT data = head->data;
            Node<dT> *temp = head->next;
            delete head;
            head = temp;
            len--;
            return data;
        }

        dT top(){
            if (isEmpty()){
                cout<<"Stack is Empty!"<<endl;
                return 0;
            }
            return head->data;
        }

        int size(){
            return len;
        }

        void printStack(){
            Node<dT> *temp = head;
            cout<<endl;
            while (temp!=NULL){
                cout<<"| "<<temp->data<<" |"<<endl;
                cout<<"'---'"<<endl;
                temp = temp->next;
            }
        }

        ~StackLL(){
            while (head!=NULL){
                Node<dT> *temp = head->next;
                delete head;
                head = temp;
            }
        }
};