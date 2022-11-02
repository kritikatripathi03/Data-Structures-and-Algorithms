#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertAtHead(struct node** head, int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = *head;
    *head = newNode;
}

void insertAtEnd(struct node* head, int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    struct node* temp = head;
    newNode -> data = data;
    newNode -> next = NULL;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newNode;
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
        printf("%d\n", prev -> data);
        count ++;
    }
    newNode -> next = prev -> next;
    prev -> next = newNode;
}


void printList(struct node* head){
    struct node* temp = head;
    while(temp){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void deleteAtHead(struct node** head){
    struct node* temp = *head;
    *head = temp -> next;
    free(temp);
}

void deleteAtEnd(struct node** head){
    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp -> next){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
}

void deleteAtPosition(struct node** head, int position){
    struct node* temp = *head;
    struct node* prev = NULL;
    int count = 1;
    if(position == 1){
        deleteAtHead(head);
    }
    while(count < position){
        prev = temp;
        temp = temp -> next;
        count += 1;
    }
    prev -> next = temp -> next;
    free(temp);
}

int main(){
    struct node* head = NULL;
    insertAtHead(&head, 10);
    insertAtEnd(head, 20);
    insertAtPosition(&head, 30, 3);
    printList(head);
    insertAtEnd(head, 40);
    printList(head);
    insertAtPosition(&head, 50, 3);
    printList(head);
    deleteAtHead(&head);
    deleteAtEnd(&head);
    deleteAtPosition(&head, 2);
    printList(head);
}
