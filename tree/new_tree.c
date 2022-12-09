#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root -> data = data;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

void insertAtLeft(struct node* root, int data){
    root -> left = createNode(data);
}

void insertAtRight(struct node* root, int data){
    root -> right = createNode(data);
}

void inOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root -> left);
    printf("%d ", root -> data);
    inOrderTraversal(root -> right);
}

void preOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> data);
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    printf("%d ", root -> data);
}


int main(){
    struct node* root = createNode(1);
    insertAtLeft(root, 2);
    insertAtRight(root, 3);
    insertAtLeft(root -> left, 4);
    insertAtRight(root -> left, 5);
    inOrderTraversal(root);
    printf("\n");
    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
}