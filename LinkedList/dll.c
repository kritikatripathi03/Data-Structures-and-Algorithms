#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insertAtHead(struct node** head, int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = *head;
    newNode -> prev = NULL;
    if(*head != NULL){
        (*head) -> prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(struct node** head, int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    struct node* temp = *head;
    newNode -> data = data;
    newNode -> next = NULL;
    if(*head == NULL){
        newNode -> prev = NULL;
        *head = newNode;
        return;
    }
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
}

int getCount(struct node* head){
    struct node* temp = head;
    int count = 1;
    while(temp){
        count ++;
        temp = temp -> next;
    }
    return count;
}

void insertAtPosition(struct node** head, int data, int position){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* prev = *head;
    int count = 1;
    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    newNode -> data = data;
    while(count < position - 1){
        printf("%d", prev -> data);
        count ++;
    }
    newNode -> next = prev -> next;
    newNode -> prev = prev;
    prev -> next = newNode;
}

void printList(struct node* head){
    struct node* temp = head;
    while(temp){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
}

int main(){
    struct node* head = NULL;
    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);
    insertAtHead(&head, 4);
    insertAtHead(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);
    insertAtPosition(&head, 11, 3);
    printList(head);
    return 0;
}
