#include "../binaryTrees/input&Print.h"


// Given a binary tree check if it's Binary Search Tree.
// One way is to do inorder traveral of given tree & store it in an array/vector if arr is sorted, then it'll be a BST else not.
void isBinarySearchTreeHelper(binaryNode<int> *root, vector<int> &vec){
    if (root == NULL){
        return;
    }
    isBinarySearchTreeHelper(root->left, vec);
    vec.push_back(root->data);
    isBinarySearchTreeHelper(root->right, vec);
}
// Time Complexity : O(n)  Space Complexity : O(n)
bool isBinarySearchTree(binaryNode<int> *root){
    vector<int> vec;
    isBinarySearchTreeHelper(root, vec);
    for (int i=1; i<vec.size(); i++){
        if (vec[i] < vec[i-1]){
            return false;
        }
    }
    return true;
}


// 2nd Approach to check BST
bool checkBST(binaryNode<int> *root){
    if (root == NULL){
        return true;
    }
    int lmax = findMaxMin(root->left).first;
    int rmin = findMaxMin(root->right).second;

    if (lmax >= root->data || rmin < root->data){
        return false;
    }
    bool isLBST = checkBST(root->left);
    bool isRBST = checkBST(root->right);

    return isLBST && isRBST;
}/* The Problem with the above approach is that we are accessing the same left & right child again & again, while finding the max & min 
    and again to check if the left & right child are BST or not, instead of that we can go once & in one shot we can find the max/min of 
    left & right child and if it was BST or not using an class or pair or struct, as we did in binary tree diameter problem */


// 3rd & best approach to check BST
struct pairs{
    bool isBST;
    int maxN;
    int minN;
};
pairs bstCheck(binaryNode<int> *root){
    if (root == NULL){
        pairs temp;
        temp.isBST = true;
        temp.minN = 10000;
        temp.maxN = -10000;
        return temp;
    }
    pairs left = bstCheck(root->left);
    pairs right = bstCheck(root->right);
    pairs temp;
    temp.minN = min(min(left.minN, right.minN), root->data);
    temp.maxN = max(max(left.maxN, right.maxN), root->data);

    if (left.maxN >= root->data || right.minN < root->data){
        temp.isBST = false;
    }
    else temp.isBST = left.isBST && right.isBST; 

    return temp;
}


// 4th & another best approach to check BST, this is top down approach which will check the curr data is in range/limits or not
bool checkIfBST(binaryNode<int> *root, int s = INT_MIN, int e = INT_MAX){
    if (root == NULL){
        return true;
    }
    if (root->data < s || root->data > e){
        return false;
    }
    bool left = checkIfBST(root->left, s, root->data-1);
    if (!left) return false;
    bool right = checkIfBST(root->right, root->data, e);

    return right;
}


int main(){

    binaryNode<int> *bstRoot = inputBTLevelWise();

    cout<<"Is Binary Search Tree : "<< isBinarySearchTree(bstRoot) <<endl;
    cout<<"Is Binary Search Tree : "<< checkBST(bstRoot) <<endl;


    pairs ans = bstCheck(bstRoot);
    cout<<"Minimum : "<<ans.minN<<"  &  Maximum : "<<ans.maxN<<endl;
    cout<<"Is Binary Search Tree : "<< ans.isBST <<endl;

    cout<<"Is BST : "<<checkIfBST(bstRoot)<<endl;

    deleteBinaryTree(bstRoot);
    
    return 0;
}