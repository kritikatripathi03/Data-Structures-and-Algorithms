#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
};

struct node* root = NULL;

struct node* insert(struct node* currentNode, int val){
    if(currentNode == NULL){
        currentNode = (struct node*)malloc(sizeof(struct node));
        currentNode -> data = val;
    }
    if(currentNode -> data < val){
        currentNode -> leftChild = (struct node*)malloc(sizeof(struct node));
        currentNode -> leftChild -> data = val;
    }
    else{
        currentNode -> rightChild = (struct node*)malloc(sizeof(struct node));
        currentNode -> rightChild -> data = val;
    }
    return currentNode;
}

struct node* insertBST(int val){
    if(root == NULL){
        root = (struct node*)malloc(sizeof(struct node));
        root -> data = val;
    }
    insert(root, val);
}

void preOrderTraversal(struct node* currentNode){
    if(currentNode != NULL){
        printf("%d ", currentNode -> data);
        preOrderTraversal(currentNode -> leftChild);
        preOrderTraversal(currentNode -> rightChild);
    }
}

void inOrderTraversal(struct node* currentNode){
    if(currentNode != NULL){
        inOrderTraversal(currentNode -> leftChild);
        printf("%d ", currentNode -> data);
        inOrderTraversal(currentNode -> rightChild);
    }
}

void postOrderTraversal(struct node* currentNode){
    if(currentNode != NULL){
        postOrderTraversal(currentNode -> leftChild);
        postOrderTraversal(currentNode -> rightChild);
        printf("%d ", currentNode -> data);
    }
}

struct node* getRoot(){
    return root;
}

int main() {
    insertBST(4);
    insertBST(9);
    insertBST(5);
    insertBST(2);
    insertBST(8);
    insertBST(12);

    printf("PreOrder Print\n");
    preOrderTraversal(getRoot());
    printf("\n");
    inOrderTraversal(getRoot());
    printf("\n");
    postOrderTraversal(getRoot());
    printf("\n");

    return 0;
}