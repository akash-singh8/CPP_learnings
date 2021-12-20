#include "../binaryTrees/input&Print.h"

/* Binary Search Tree is a special type of Binary Tree in which the data of left node should be less than it's root data and
   the data of right node should be greater than it's root data & this condition should be true for each node. Binary search
   tree is specially inspired from Binary Search algorithm which time complexity is much less than general search algos.  */

// Given a BST & integer, check if the given integer is present in binary search tree or not
bool searchInBST(binaryNode<int> *root, int target){
    if (root == NULL){
        return false;
    }
    if (root->data == target) return true;
    if (target > root->data){
        return searchInBST(root->right, target);
    }
    return searchInBST(root->left, target);
}

// Iterative approach to Search in BST,  T.C : O(height),   S.C : O(1)
bool searchBST(binaryNode<int> *root, int target){
    while (root != NULL){
        if (root->data == target) return true;
        if (target < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

// print the nodes in between the given range 
void printNodesInRange(binaryNode<int> *root, int start, int end){
    if (root == NULL){
        return;
    }
    if (root->data>=start && root->data<=end){
        printNodesInRange(root->left, start, end);
        cout<<root->data<<" ";
        printNodesInRange(root->right, start, end);
    }
    else{
        if (end < root->data){
            printNodesInRange(root->left, start, end);
        }
        if (start > root->data){
            printNodesInRange(root->right, start, end);
        }
    }
}




/*  Binary Search Tree Inputs : 
     4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
     8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1  
*/

int main(){
    
    binaryNode<int> *bstRoot = inputBTLevelWise();
    cout<<endl;
    printBTlevelWise(bstRoot);

    cout<<"Is Present : "<<searchInBST(bstRoot, 5)<<endl;

    cout<<"Search in BST : "<<searchBST(bstRoot, 5);

    // printNodesInRange(bstRoot, 5, 8);


    deleteBinaryTree(bstRoot);

    return 0;
}