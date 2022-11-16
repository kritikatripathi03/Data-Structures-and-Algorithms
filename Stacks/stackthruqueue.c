#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node * head1 = NULL, *head2 = NULL;

void enqueue(struct node* head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(head == NULL){
        head = newNode;
    }
    struct node* temp = head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

int dequeue(struct node* head){
    struct node* temp = head;
    int data = temp -> data;
    head = temp -> next;
    free(temp);
    return data;
}

void push(int data){
    enqueue(head1, data);
    while(head2){
        enqueue(head1, head2 -> data);
        dequeue(head2);
    }
    struct node* temp = head1;
    head1 = head2;
    head2 = temp;
}

void pop(){
    if(head2 == NULL){
        return;
    }
    dequeue(head2);
}

int top(){
    if(head2 == NULL){
        return -1;
    }
    return head2 -> data;
}

int main()
{
    push(1);
    push(2);
    push(3);
 
    printf("%d\n", top());
    pop();
    printf("%d\n", top());
    pop();
    printf("%d\n", top());
    pop();
    return 0;
}
