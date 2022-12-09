#include<stdio.h>
#include<stdlib.h>

struct node {
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

void insertInBST(struct node* root, int data){
    if(root == NULL){
        root = createNode(data);
        return;
    }
    if(data < root -> data){
        root -> left = createNode(data);
        return;
    }
    root -> right = createNode(data);
    return;
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

struct node* minVal(struct node* root){
    struct node* temp = root;
    if(root == NULL){
        return root;
    }
    while(temp -> left){
        temp = temp -> left;
    }
    return temp;
}

struct node* delNode(struct node* root, int data){
    struct node* temp = NULL;
    if(root == NULL){
        return root;
    }
    else if(data < root -> data){
        root -> left = delNode(root -> left, data);
    }
    else if(data > root -> data){
        root -> right = delNode(root -> right, data);
    }
    else{
        if(root -> left == NULL){
            temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            temp = root -> left;
            free(root);
            return temp;
        }
        temp = minVal(root -> right);
        root -> data = temp -> data;
        root -> right = delNode(root -> right, temp -> data);
    }
    return root;
}

int main(){
    struct node* root = createNode(10);
    insertInBST(root, 2);
    insertInBST(root, 13);
    insertInBST(root -> left, 0);
    insertInBST(root -> left, 5);
    insertInBST(root -> right, 12);
    insertInBST(root -> right, 15);
    inOrderTraversal(root);
    printf("\n");
    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    printf("%d is the minimum value in the BST.", minVal(root) -> data);
    root = delNode(root, 10);
    inOrderTraversal(root);
}