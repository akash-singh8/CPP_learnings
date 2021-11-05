#include<iostream>
#include<stack>
#include<queue>
#include<map>

using namespace std;

// Function to print the Stack
void printStack(stack<int> stk){
    // don't take the stack as reference as we're making changes into the stack
    cout<<endl;
    while (stk.size()){
        cout<<"| "<<stk.top()<<" |"<<endl;
        cout<<"'---'"<<endl;
        stk.pop();
    }
    cout<<endl;
}

// Function to print the Queue
void printQueue(queue<int> que){
    int l = que.size();
    cout<<"----------------"<<endl;
    while (l--){
        cout<<que.front()<<" | ";
        que.pop();
    }
    cout<<"\n----------------"<<endl;
}

// Function to check if the given brackets are balanced or not!
bool isBalBrackets(string b){
    stack<char> stk;
    for (int i=0; b[i]!='\0'; i++){
        if (b[i]=='(' || b[i]=='[' || b[i]=='{') stk.push(b[i]);
        if (!stk.empty() && (b[i]==')' && stk.top()=='(' || b[i]==']' && stk.top()=='[' || b[i]=='}' && stk.top()=='{')) stk.pop();
    }
    if (stk.empty()) return true;
    return false;
}


// Reverse the stack using one empty stack
void revStack(stack<int> &stk){
    stack<int> temp;
    while (stk.size()){
        int top = stk.top();
        stk.pop();
        temp.push(top);
    }
    stk = temp;
}


// Reverse the actual given stack using an empty stack Iteratively. Time Complexity = O(n2)
void reverseStack(stack<int> &stk){
    stack<int> tempStk;
    int l = stk.size();
    for (int i=0; i<l-1; i++){
        int temp = stk.top();
        stk.pop();
        while (stk.size()>i){
            int top = stk.top();
            stk.pop();
            tempStk.push(top);
        }
        stk.push(temp);
        while (tempStk.size()){
            int top = tempStk.top();
            tempStk.pop();
            stk.push(top);
        }
    }
}


/*Reverse the actual given Stack in just O(n) Time Complexity with the help of only one empty stack! It's impossible to 
reverse actual Stack just by using an empty stack, yeah but it'll be easy to revese actual stack by using two empty stack
Since we have given only one empty stack we can't create one more empty stack explicitly, but we can use and stack which is 
in our memory and that's................. Function Stack........ recursion, 
Time Complexity : O(n), Space Complexity : O(n)  -> Better then the last one         */
void helper(stack<int> &stk, stack<int> &temp){
    if (temp.size()==0) return;
    int top = temp.top();
    temp.pop();
    helper(stk, temp);
    stk.push(top);
}
void reverseStk(stack<int> &stk){
    stack<int> temp;
    while(stk.size()){
        int top = stk.top();
        stk.pop();
        temp.push(top);
    }
    helper(stk, temp);
}


// Program to reverse a Queue TC:O(n) SC:O(n) as we are using a stack explicitly.
void revQueue(queue<int> &que){
    stack<int> stk;
    while (!que.empty()){
        stk.push(que.front());
        que.pop();
    }
    while (!stk.empty()){
        que.push(stk.top());
        stk.pop();
    }
}

// Another program to reverse a Queue this time also we are using a stack but implicitly means a call/function stack!
void reverseQueue(queue<int> &que){
    if (que.empty()){
        return;
    }
    int temp = que.front();
    que.pop();
    reverseQueue(que);
    que.push(temp);
}

// Check Rebundant brackets!
int isRebundantB(string b){
    stack<char> stk;
    for (int i=0; b[i]!='\0'; i++){
        if (b[i]=='('){
            stk.push(b[i]);
        }
        else if (!stk.empty() && stk.top()=='(' && (b[i]=='+' || b[i]=='*' || b[i]=='-' || b[i]=='/')){
            stk.push(b[i]);
        }
        else if (b[i]==')' && (stk.top()=='+' || stk.top()=='-' || stk.top()=='*' || stk.top()=='/')){
            stk.pop();
            stk.pop();
        }
    }   
    if (stk.empty()) return 0;
    return 1;
}


// Function to find the stock span.... Brute force approach Time Complexity : O(n^2)
void stockSpan(int arr[], int size){
    int k=1, temp[size]={1};
    for (int i=1; i<size; i++){
        int span=1;
        for (int j=i-1; j>=0; j--){
            if (arr[j]<arr[i]) span++;
            else break;
        }
        temp[k] = span;
        k++;
    }
    cout<<"[ ";
    for (int i=0; i<size-1; i++){
        cout<<temp[i]<<", ";
    }
    cout<<temp[size-1]<<" ]"<<endl;
}

/* Optimizing the Stock span problem using stack and maps TC:O(n) SC:O(n) but one problem with this that it'll not work 
properly when the given array has duplicates values */
void stockSpans(int arr[], int size){
    map<int, int> m;
    m[arr[0]] = 1;
    stack<int> stk;
    stk.push(arr[0]);
    int i=1, span=1;
    while (i<size){
        if (stk.empty() || arr[i]<=stk.top()){
            stk.push(arr[i]);
            m[arr[i]] = span;
            span = 1;
        }
        else{
            span += m[stk.top()];
            stk.pop();
            continue;
        }
        i++;
    }
    cout<<"[ ";
    for (int i=0; i<size-1; i++){
        cout<<m[arr[i]]<<", ";
    }
    cout<<m[arr[size-1]]<<" ]\n";
}

// Stock span most optimized solution TC : O(n) SC:O(n) works for every case
void findStockSpan(int arr[], int size){
    int spans[size];
    stack<int> stk;
    int i=0, span=1;
    while (i<size){
        if (stk.empty()){
            spans[i]=i+1;
            stk.push(i);
            span = 1;
        }else if (arr[i]<=arr[stk.top()]){
            spans[i] = span;
            stk.push(i);
            span = 1;
        }else{
            span += spans[stk.top()];
            stk.pop();
            continue;
        }
        i++;
    }
    cout<<"[ ";
    for (i=0; i<size-1; i++){
        cout<<spans[i]<<", ";
    }
    cout<<spans[size-1]<<" ]\n";
}


// Function to find minimum bracket reversal in order to make the brackets balanced
int minBracketsRev(string b){
    int l = b.length(), c=0;
    if (l & 1) return -1;
    stack<char> stk;
    for (int i=0; i<l; i++){
        if (b[i]=='{') stk.push('{');
        else{
            if (stk.empty()){
                c++;
                continue;
            }else stk.pop();
        }
    }
    return (stk.size()+1)/2+(c+1)/2;
}


int main(){

    string brack="([]{})";
    (isBalBrackets(brack))? cout<<"True\n" : cout<<"False\n";
    
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    printStack(stk);
    // revStack(stk);
    // reverseStack(stk);
    reverseStk(stk);
    printStack(stk);

    
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    printQueue(que);
    // revQueue(que);
    reverseQueue(que);
    printQueue(que);

    string br = "(a+((b*c)+c))";
    cout<<isRebundantB(br)<<endl;

    // int arr[7] = {100, 80, 60, 70, 60, 75, 85};
    // int arr[8] = {60, 70, 80, 100, 90, 75, 80, 120};
    int arr[9] = {5, 3, 8, 7, 10, 7, 7, 12, 16};
    // stockSpan(arr, 9);
    // stockSpans(arr, 9); 
    findStockSpan(arr, 9);

    string b = "{{{{}}";
    cout<<minBracketsRev(b)<<endl;


    return 0;
}