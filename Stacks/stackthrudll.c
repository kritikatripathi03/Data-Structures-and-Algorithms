#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* top = NULL;

void push(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    if(top == NULL){
        newNode -> prev = NULL;
        newNode -> next = NULL;
        top = newNode;
    }
    else{
        newNode -> next = top;
        top -> prev = newNode;
        newNode -> prev = NULL;
        top = newNode;
    }
}

void pop(){
    struct node* temp;
    if(top == NULL){
        printf("Stack UnderFlow");
    }
    temp = top;
    top -> next -> prev = NULL;
    top = temp -> next;
    temp -> next = NULL;
    free(temp);    
}

void print(){
    struct node* temp = top;
    while(temp){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){
    push(5);
    print();
    /*push(6);
    print();
    push(7);
    print();
    push(8);
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();*/
    pop();
    //print();
    return 0;
}