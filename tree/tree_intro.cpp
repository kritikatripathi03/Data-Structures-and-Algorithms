#include<iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* leftChild;
        Node* rightChild;
        Node(){
            value = 0;
            leftChild = NULL;
            rightChild = NULL;
        }
        Node(int val){
            value = val;
            leftChild = NULL;
            rightChild = NULL;
        }
};

class BinarySearchTree {
    private:
        Node* root;
    public:
        BinarySearchTree(){
            root = NULL;
        }
        BinarySearchTree(int rootVal){
            root = new Node(rootVal);
        }
        Node* getRoot(){
            return root;
        }
        Node* insert(Node* currentNode, int val){
            if(currentNode == NULL){
                return new Node(val);
            }
            if(currentNode -> value > val){
                currentNode -> leftChild = insert(currentNode -> leftChild, val);
            }
            else{
                currentNode -> rightChild = insert(currentNode -> rightChild, val);
            }
            return currentNode;
        }
        void insertBST(int val){
            if(getRoot() == NULL){
                root = new Node(val);
                return;
            }
            insert(this -> getRoot(), val);
        }
        void preOrderTraversal(Node* currentNode){
            if(currentNode != NULL){
                cout << currentNode -> value << " ";
                preOrderTraversal(currentNode -> leftChild);
                preOrderTraversal(currentNode -> rightChild);
            }
        }
        void inOrderTraversal(Node* currentNode){
            if(currentNode != NULL){
                inOrderTraversal(currentNode -> leftChild);
                cout << currentNode -> value << " ";
                inOrderTraversal(currentNode -> rightChild);
            }
        }

        void postOrderTraversal(Node* currentNode){
            if(currentNode != NULL){
                postOrderTraversal(currentNode -> leftChild);
                postOrderTraversal(currentNode -> rightChild);
                cout << currentNode -> value << " ";
            }
        }
};

int main() {

    BinarySearchTree BST(6);
    BST.insertBST(4);
    BST.insertBST(9);
    BST.insertBST(5);
    BST.insertBST(2);
    BST.insertBST(8);
    BST.insertBST(12);

    cout << "PreOrder Print" << endl;
    BST.preOrderTraversal(BST.getRoot());
    cout << endl;
    BST.inOrderTraversal(BST.getRoot());
    cout << endl;
    BST.postOrderTraversal(BST.getRoot());
    cout << endl;

    return 0;
}