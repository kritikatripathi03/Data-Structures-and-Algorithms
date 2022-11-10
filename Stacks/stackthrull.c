#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = top;
    top = newNode;
}

void pop(){
    struct node* temp = top;
    top = temp -> next;
    printf("%d\n", temp -> data);
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
    push(1);
    print();
    push(2);
    print();
    push(3);
    print();
    push(4);
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
}