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

void printLL(Node *head){
    while (head->next != 0){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}



// delete every node after node n
Node* deleteNode(Node *head, int n=0){
    Node* curr = head;
    for (int i=1; i<n && curr!=NULL; i++){
        curr = curr->next;
    }
    Node *temp = curr->next;
    if (n>0) curr->next = NULL;
    else{
       delete curr;
       return NULL;
    }
    curr = temp->next;
    while (curr!=NULL){
        delete temp;
        temp = curr;
        curr = curr->next;
    }
    delete temp;
    return head;
}


// Given the linked list and two integers m & n, retain the 'M' nodes, then delete the next 'N' nodes until the end of ll.
Node* deleteNodes(Node *head, int m=0, int n=0){
    Node *temp = head;
    Node *nH=NULL, *nT, *nH1=NULL, *nT1;
    if (m!=0){
        while (temp!=NULL){
            for (int i=0; i<m && temp!=NULL; i++){
                if (nH==NULL) nH=temp;
                else nT->next = temp;
                nT = temp;
                temp = temp->next;
            }
            for (int i=0; i<n && temp!=NULL; i++){
                if (nH1==NULL) nH1 = temp;
                else nT1->next = temp;
                nT1 = temp;
                temp = temp->next;
            }
        }
        nT->next = NULL;
        nT1->next = NULL;
    }
    else Node *nH1 = head;
    temp = nH1->next;
    while(temp!=NULL){
        delete nH1;
        nH1 = temp;
        temp = temp->next;        
    }
    delete nH1;
    return nH;
}

int main(){

    Node *head = takeInput();
    printLL(head);

    // evenAodd(head);
    // head = evenAfodd(head);
    // head = deleteNodes(head, 2);
    head = deleteNodes(head, 2, 1);
    printLL(head);

    return 0;
}