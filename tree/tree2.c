#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
};

struct node* createNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> leftChild = NULL;
    temp -> rightChild = NULL;
    return temp;
}

struct node** insertNode(struct node** root, int data){
    struct node* newNode = createNode(data);
    if(*root == NULL){
        *root = newNode;
        return root;
    }
    if((*root) -> data < data){
        (*root) -> rightChild = insertNode((*root) -> leftChild, data);
        return root;
    }
    (*root) -> leftChild = insertNode((*root) -> rightChild, data);
    return root;
}

void insertBST(struct node** root, int data){
    if((*root) == NULL){
        (*root) = createNode(data);
        return;
    }
    insertNode(root, data);
}

void preOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> data);
    preOrderTraversal(root -> leftChild);
    preOrderTraversal(root -> rightChild);
    return;
}

void inOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root -> leftChild);
    printf("%d ", root -> data);
    inOrderTraversal(root -> rightChild);
    return;
}

void postOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root -> leftChild);
    postOrderTraversal(root -> rightChild);
    printf("%d ", root -> data);
    return;
}


int main(){
    struct node* root = NULL;
    insertNode(&root, 5);
    insertNode(&root, 4);
    insertNode(&root, 6);
    preOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    return 0;
}