#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL; 


void enqueue(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode -> data = data;
    if(front == NULL){
        front = newnode;
        front -> next = NULL;
        rear = front;
        return;
    }
    rear -> next = newnode;
    rear = newnode;
    rear -> next = NULL;
}

void dequeue(){
    struct node* temp = front;
    front = front -> next;
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
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    print();
    dequeue();
    print();
    dequeue();
    print();
    dequeue();
    print();
    dequeue();
    print();
    return 0;
}