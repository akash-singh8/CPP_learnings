#include "../binaryTrees/input&Print.h"


class BST{
    binaryNode<int> *root = NULL;
    int length = 0;

    public:
        void insert(int data){
            
        }


        // To do search in BST recursively, we've to use a helper function or to make the function static.
        // but the iterative approach is best, as the S.C is constant
        bool search(int target){
            binaryNode<int> *temp = root;
            while(temp != NULL){
                if (target == temp->data) return true;
                if (target < temp->data) temp = temp->left;
                else temp = temp->right;
            }
            return false;
        }

        void printTree(){
            printBTlevelWise(this->root);
        }

        ~BST(){
            deleteBinaryTree(root);
        }
};

int main(){
    BST bst;
 
    bst.printTree();
    cout<<"Search : "<<bst.search(6)<<endl;;
    return 0;
}