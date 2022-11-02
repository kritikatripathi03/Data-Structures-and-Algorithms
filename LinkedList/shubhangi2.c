// the following code performs insertion and traversal. ( to perform - deletion, )

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * previous;
};

struct node * head;

// done 
struct node * firstNode(int data, struct node * head){
    struct node * ptr = (struct node * )malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = NULL;
    ptr -> previous = NULL; 
    head = ptr;
    printf("done1\n");
    return ptr;
    
}

// done 
struct node * insertionInBeginning(int data, struct node * head){
    struct node * ptr = (struct node * )malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    ptr -> previous = NULL;
    head -> previous = ptr;
    head = ptr;
    printf("done2\n");
    
    return ptr;
    
}

struct node * insertionInBetween(int position, int data, struct node * head){
    struct node * new = head -> next;
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    int i = 0;
    while(i<position){
        // by the time this loop ends, the value of i will be equal to position 
        // by the time this loop gets over, new will point at the node on specified position
        printf("%d\n", i);
        new = new -> next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = new -> next;
    new -> next = ptr;
    printf("done3\n");
    
    return ptr;
    
}

// done 
struct node * insertionAtEnd( int data, struct node * head){
    struct node * new = head;
    struct node * ptr = ( struct node * )malloc(sizeof(struct node));
    while(new -> next != NULL){
        new = new -> next;
    }
    ptr -> data = data;
    ptr -> next = NULL;
    ptr -> previous = new;
    new -> next = ptr;
    printf("done4\n");
    
    return ptr;
}

void printingLinkedList(struct node * head){
    struct node * new = head;
    while(new -> next != NULL){
        printf("%d\n", new -> data);
        new = new -> next;
    }
    printf("printed\n");
    
}


int main()
{
    struct node * head = NULL;

    struct node * ptr1 = (struct node*)malloc(sizeof(struct node));
    ptr1 = firstNode(55, head);
    
    /struct node * ptr2 = (struct node)malloc(sizeof(struct node));
    ptr2 = insertionInBeginning(78, head);
    
    struct node * ptr3 = (struct node*)malloc(sizeof(struct node));
    ptr3 = insertionInBeginning(79, head);*/
    
    /*
    struct node * ptr5 = (struct node*)malloc(sizeof(struct node));
    ptr5 = insertionInBetween(2, 11, head);
    
    struct node * ptr6 = (struct node*)malloc(sizeof(struct node));
    ptr6 = insertionAtEnd(22, head);
    */
    
    
    printingLinkedList(head);
    
    
    return 0;
}