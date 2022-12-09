#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;
struct Node* left = NULL;
struct Node* right = NULL;

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inOrder (struct Node* node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
    return;
}

void preOrder (struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
    return;
}

void postOrder (struct Node* node) {
    if (node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
    return;
}

struct node *inOrderPredecessor(struct Node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int value){
    struct Node* iPre;
    if(root == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        free(root);
        return NULL;
    }
    else if(value < root -> data){
        deleteNode(root -> left,value);
    }
    else if(value > root -> data){
        deleteNode(root -> right, value);
    }
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main(){
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    left = root->left;
    right = root->right;
    left->left = createNode(4);
    left -> right = createNode(5);
    right->left = createNode(6);
    right -> right = createNode(7);
    printf("IN-ORDER TRAVERSAL: \n");
    inOrder(root);
    printf("\n");
    printf("POST-ORDER TRAVERSAL: \n");
    postOrder(root);
    printf("\n");
    printf("PRE-ORDER TRAVERSAL: \n");
    preOrder(root);
    printf("\n");
    return 0;
}