#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
};

struct node* makeNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> leftChild = NULL;
    newNode -> rightChild = NULL;
    return newNode;
}

void inOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root -> leftChild);
    printf("%d ", root -> data);
    inOrderTraversal(root -> rightChild);
}

void preOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> data);
    preOrderTraversal(root -> leftChild);
    preOrderTraversal(root -> rightChild);
}

void postOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root -> leftChild);
    postOrderTraversal(root -> rightChild);
    printf("%d ", root -> data);
}

//is every complimentary lattice is a complete lattice

int main(){
    struct node* root = makeNode(5);
    printf("Chal gya!\n");
    root -> leftChild = makeNode(6);
    printf("Chal gya!\n");
    root -> rightChild = makeNode(7);
    printf("Chal gya!\n");
    root -> leftChild -> leftChild = makeNode(8);
    root -> leftChild -> rightChild = makeNode(9);
    root -> rightChild -> leftChild = makeNode(10);
    root -> rightChild -> rightChild = makeNode(11 );
    inOrderTraversal(root);
    printf("\n");
    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    return 0; 
}
