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

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = 0;
    Node *tail = 0;
    while (data != -1){
        Node *n = new Node(data);
        if (head == 0){
            head = n;
        }else{
            tail->next = n;
        }
        tail = n;
        cin >> data;
    }
    return head;
}

// Recursive function to print linked list
void printLL(Node *head){
    if (head->next == NULL){
        cout<<head->data<<endl;
        return;
    }
    cout<<head->data<<" -> ";
    printLL(head->next);
}

// Recursive function to find length of linked list
int lengthLL(Node *head){
    if (head == NULL){
        return 0;
    }
    return 1 + lengthLL(head->next);
}


// Recursive function to print the linked list in reverse order
void printLLrev(Node *head){
    if (head->next == NULL){
        cout<<head->data;
        return;
    }
    printLLrev(head->next);
    cout<<" -> "<<head->data;
}

// insert node at ith index in Linked list using recursion
void insertNode(Node *head, int i, int data, Node *newNode=NULL){
    if (i==0){
        newNode = new Node(head->data);
        head->data = data;
    }
    else if(newNode == NULL) newNode = new Node(data);
    if (i-1 <= 0){
        newNode->next = head->next;
        head->next = newNode;
        return;
    }
    insertNode(head->next, i-1, data, newNode);
}

// Recursive function to delete node at ith index in linked list
void deleteNode(Node *head, int i){
    if (i==0){
        head->data = head->next->data;
    }
    if (i-1<=0){
        Node *a = head->next;
        head->next = head->next->next;
        delete a;
        return;
    }
    deleteNode(head->next, i-1);
}

int main(){
    Node *head = takeInput();
    printLL(head);
    cout<<"Length of LL : "<<lengthLL(head)<<endl;
    
    printLLrev(head);
    cout<<endl;
    
    insertNode(head, 1, 43);
    printLL(head);

    int i;
    cin>>i;

    deleteNode(head, i);
    printLL(head);

    return 0;
}