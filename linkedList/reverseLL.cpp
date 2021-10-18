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

int findMid(Node *head){
    int i=0;
    if (head->next == NULL){
        return i;
    }
    Node *temp = head->next;
    while (temp!=NULL && temp->next!=NULL){
        head = head->next;
        temp = temp->next->next;
        i++;
    }
    return i;
}

// reversing linked list in one shot but the Time Complexity : ~O(n2)
Node* revll(Node *head){
    if (head->next == NULL){
        return head;
    }
    Node *newHead = revll(head->next);
    Node *temp = newHead;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return newHead;
}


// Reversing a linked list using a class, with recursion, Time Complexity : O(n)
class Pair{
    public:
        Node *head;
        Node *tail;
};
Pair helperf(Node *head){
    if (head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = helperf(head->next);

    smallAns.tail->next = head;
    head->next = NULL;
    smallAns.tail = head;
    return smallAns;
}
Node* revLL(Node *head){
    return helperf(head).head;
}


// Recursive function to reverse the linked list using Helper function. Time Complexity : O(n)
void helper(Node *head){
    if (head->next==NULL){
        return;
    }
    Node *tail = head->next;
    helper(tail);
    tail->next = head;
    head->next = NULL;
}
Node* reversell(Node *head){
    Node *newHead = head;
    while (newHead->next!=NULL){
        newHead = newHead->next;
    }
    helper(head);
    return newHead;
}


// Recursive function to reverse the linked list in O(n) wihtout using any helper function
Node* reverseLL(Node *head){
    if (head->next==NULL){
        return head;
    }
    Node *newHead = reverseLL(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;

    return newHead;
}


// Reverse the linked list iteratively Tiem Complexity : O(n), Space Complexity : O(n)
void reverselli(Node *head){
    int size=0;
    Node *temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
        size++;
    }
    int arr[size];
    temp = head;
    for (int i=0; temp!=NULL; temp=temp->next){
        arr[i] = temp->data;
        i++;
    }
    for (int i=size; i>=0; i--){
        head->data = arr[i];
        head = head->next;
    }
}


// Reverse the linked list iteratively with TC:O(n), Space Complexity : O(1).
Node* reverseLLi(Node *head){
    if (head==NULL || head->next==NULL) return head;
    Node *curr = head->next;
    Node *nxt = curr->next;
    head->next = NULL;
    while (nxt!=NULL){
        curr->next = head;
        head = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = head;
    return curr;
}


int main(){
    Node *head = takeInput();
    printLL(head);
    
    // head = revll(head);
    // head = revLL(head);
    // head = reversell(head);
    // head = reverseLL(head);
    // reverselli(head);
    head = reverseLLi(head);
    printLL(head);


    return 0;
}