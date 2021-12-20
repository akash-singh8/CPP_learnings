#include "../binaryTrees/input&Print.h"


// Construct a Binary Search Tree from given sorted array.
binaryNode<int> *BSTHelper(int arr[], int s, int e){
    if (s > e){
        return NULL;
    }
    int mid = (s + e)/2;
    binaryNode<int> *root = new binaryNode<int>(arr[mid]);
    root->left = BSTHelper(arr, s, mid-1);
    root->right = BSTHelper(arr, mid+1, e);

    return root;
}


// Construct a sorted linked list using the given binary search tree
class Node{
    public:
        int data;
        Node *next = NULL;
        Node(int data){
            this->data = data;
        }
};
void linkedLstUsingBSTHelper(binaryNode<int> *root, vector<int> &vec){
    if (root == NULL) return;
    linkedLstUsingBSTHelper(root->left, vec);
    vec.push_back(root->data);
    linkedLstUsingBSTHelper(root->right, vec);
}
Node *linkedLstUsingBST(binaryNode<int> *root){
    vector<int> vec;
    linkedLstUsingBSTHelper(root, vec);
    Node *head = NULL, *tail = NULL;
    for (int i=0; i<vec.size(); i++){
        Node *newNode = new Node(vec[i]);
        if (head == NULL) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }
    return head;
}


// Given BST and an integer k, find and print the path from node with data k to root
void pathFromKtoRoot(binaryNode<int> *root, int k){
    if (root == NULL){
        return;
    }
    if (k == root->data){
        cout<<root->data<<" ";
        return;
    }
    if (k < root->data) pathFromKtoRoot(root->left, k);
    else pathFromKtoRoot(root->right, k);
    
    cout<<root->data<<" ";
}


// Now given only Binary tree, find & print the path from node with data k to root or visa-versa
bool pathBtwKndRoot(binaryNode<int> *root, int k){
    if (root == NULL) return false;
    if (root->data == k){
        cout<<root->data<<" ";
        return true;
    }
    
    bool left = pathBtwKndRoot(root->left, k);
    if (left == true){
        cout<<root->data<<" ";
        return true;
    }

    bool right = pathBtwKndRoot(root->right, k);
    if (right) cout<<root->data<<" ";
    return right;
}


// Implement a insert function, which will insert a node in binary search tree
binaryNode<int> *insert(binaryNode<int> *root, int item){
    if (root == NULL){
        binaryNode<int> *node = new binaryNode<int>(item);
        return node;
    }
    if (item >= root->data){
        root->right = insert(root->right, item); // 1 2
    }
    else{
        root->left = insert(root->left, item);
    }
    return root;
}

pair<int, binaryNode<int>*> minNode(binaryNode<int> *root){
    if (root == NULL){
        pair<int, binaryNode<int>*> temp;
        temp.first = INT_MAX;
        temp.second = NULL;
        return temp;
    }
    pair<int, binaryNode<int>*> left = minNode(root->left);
    pair<int, binaryNode<int>*> right = minNode(root->right);

    pair<int, binaryNode<int>*> temp;
    temp.first = min(min(left.first, right.first), root->data);
    if (min(left.first, right.first) > root->data) temp.second = root;
    else{
        if (left.first < right.first) temp.second = left.second;
        else temp.second = right.second;
    }
    return temp;
}

// Delete the given node from binary search tree
binaryNode<int> *deleteNode(binaryNode<int> *root, int item){
    if (root == NULL){
        return NULL;
    }
    if (root->data == item){
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL){
            binaryNode<int> *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL){
            binaryNode<int> *temp = root->right;
            delete root;
            return temp;;
        }
        if (root->left != NULL && root->right != NULL){
            binaryNode<int> *temp = minNode(root->right).second;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            return root;
        }
    }
    if (item < root->data) root->left = deleteNode(root->left, item);
    else root->right = deleteNode(root->right, item);

    return root;
}


// 5 3 6 2 4 7 -1 -1 -1 -1 -1 -1 -1

int main(){

    // int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    // binaryNode<int> *root = BSTHelper(arr, 0, 6);
    binaryNode<int> *root = inputBTLevelWise();
    printBTlevelWise(root);

    root = deleteNode(root, 3);
    printBTlevelWise(root);

    // pathFromKtoRoot(root, 4);
    // pathBtwKndRoot(root, 7);

    deleteBinaryTree(root);

    return 0;
}