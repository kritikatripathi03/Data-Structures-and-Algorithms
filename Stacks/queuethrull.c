#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL, *rear = NULL;

void enqueue(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    if(front == NULL){
        newNode -> next = front;
        front = newNode;
        rear = front;
    }
    rear -> next = newNode;
    rear = newNode;
    rear -> next = NULL;
}

void dequeue(){
    if(front == NULL){
        printf("Stack Underflow!\n");
    }
    struct node* temp = front;
    front = temp -> next;
    free(temp);
}

void print(){
    struct node* temp = front;
    while(temp){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    print();
    dequeue();
    dequeue();
    print();
    return 0;
}