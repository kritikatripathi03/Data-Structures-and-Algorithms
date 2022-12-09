#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void insertionInBeginning(int data, struct node ** head){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = *head;
    *head = ptr;
    printf("done insertion in beginning \n");
}

void insertionAtEnd(int data, struct node * head){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = NULL;
    struct node * temp1 = NULL;
    struct node * temp2 = head;
    while(temp2 != NULL){
        printf("%d ->", temp2 -> data);
        temp1 = temp2;
        temp2 = temp2 -> next;
    }
    temp1 -> next = ptr;     //this code won't generate an error now :)
    printf("done insertion at end \n");
}

void insertionInBetween(int position, int data, struct node ** head){
    if(position == 1){
        insertionInBeginning(data, head);
        return;
    }
    struct node * new = *head;
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    int i = 1;
    while(i<position && new != NULL){
        // by the time this loop ends, the value of i will be equal to position 
        // by the time this loop gets over, new will point at the node on specified position
        printf("%d\n", i);
        new = new -> next;
        i++;
    }
    if(new -> next == NULL){
        insertionAtEnd(data, *head);
        return;
    }
    ptr -> next = new -> next;
    new -> next = ptr;
    printf("done3\n");
}

void printingLinkedList(struct node * head){
    struct node * new = head;
    while(new != NULL){
        printf("%d -> ", new -> data);
        new = new -> next;
    }

    printf("NULL\n");
}


int main(){
    struct node * head = NULL;
    //printf("%u\n", head);
    insertionInBeginning(78, &head);
    printf("%d\n", head -> data);
    //struct node * ptr2 = (struct node*)malloc(sizeof(struct node));
    //ptr2 = insertionInBeginning(79, head);
    insertionAtEnd(79, head);
    printingLinkedList( head );
    insertionInBetween(2, 11, &head);
    insertionAtEnd(22, head);
    
    
    
    printingLinkedList(head);
    
    
    return 0;
}