#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void storeSorted(struct node* root, int arr[], int i){
    if(root != NULL){
        storeSorted(root -> left, arr, i);
        arr[i ++] = root -> data;
        printf("%d ", i);
        storeSorted(root -> right, arr, i + 1);
    }
}

struct node* insert(struct node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root -> data){
        root -> left = createNode(data);
    }
    else{
        root -> right = createNode(data);
    }
    return root;
}

void treeSort(int arr[], int n){
    int i;
    struct node* root = NULL;
    root = insert(root, arr[0]);
    for(i = 1; i < n; i ++){
        root = insert(root, arr[i]);
    }
    i = 0;
    storeSorted(root, arr, i);
}

int main(){
    int i;
    int arr[] = {5, 4, 7, 2, 11};
    treeSort(arr, 5);
    for(i = 0; i < 5; i ++){
        printf("%d ", arr[i]);
    }
    return 0;
}