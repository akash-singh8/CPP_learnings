#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next = NULL;

        Node(int data){
            this->data = data;
        }
};

Node* takeInput(){
    int data;
    cin>>data;
    Node *head=NULL, *tail=NULL;
    while (data!=-1){
        Node *newNode = new Node(data);
        if (!head) head=newNode;
        else tail->next = newNode;
        tail = newNode;
        cin>>data;
    }
    tail->next = head;
    return head;
}


void print(Node *head){
    Node *curr = head;
    while (curr->next!=head){
        cout<<curr->data<<" -> ";
        curr = curr->next;
    }
    cout<<curr->data<<endl;
}


void deleteNodes(Node *head){
    while (head!=NULL){
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}


// function to insert node at ith index in circular linked list
Node* insertNode(Node *head, int i, int data){
    Node *curr = head;
    Node *newNode = new Node(data);
    if (i==0){
        while (curr->next!=head) curr=curr->next;
        head = newNode;
    }
    else while(i-->1) curr=curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}


// delete node at ith index
Node* deleteNode(Node *head, int i){
    Node *curr = head;
    if (i==0){ 
        while (curr->next!=head) curr=curr->next;
        head = head->next;
    }
    else while(i-->1) curr=curr->next;
    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}


int main(){

    Node *head = takeInput();
    print(head);

    int i;
    cin>>i;
    head = insertNode(head, i, 49);
    // head = deleteNode(head, i);
    print(head);

    deleteNodes(head);
    return 0;
}

