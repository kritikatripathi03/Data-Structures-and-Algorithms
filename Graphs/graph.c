#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* getHead(){
    return head;
}

int isEmpty(){
    if(head == NULL){
        return 1;
    }
    return 0;
}

void insertAtHead(int data){
    struct node* temp = head;
    temp -> data = data;
    temp -> next = head;
    head = temp;
}

void insertAtTail(int data){
    if(isEmpty()){
        insertAtHead(data);
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    struct node* temp = head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = NULL;
}

void printList(){
    if(isEmpty()){
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    while(temp){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int search(int data){
    if(isEmpty()){
        return 0;
    }
    struct node* temp = head;
    while(temp){
        if(temp -> data == data){
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}