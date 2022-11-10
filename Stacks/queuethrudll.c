#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* lastnode;
    newnode -> data = data;
    if(front == NULL){
        front = newnode;
        front -> prev =  NULL;
        front -> next =  NULL;
        rear = front;
        return;
    }
    lastnode = rear;
    rear -> next = newnode;
    rear = newnode;
    rear -> prev = lastnode;
    rear -> next =  NULL;
}

void dequeue(){
    
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
    enqueue(8);
    enqueue(7);
    enqueue(6);
    print();
    return 0;
}