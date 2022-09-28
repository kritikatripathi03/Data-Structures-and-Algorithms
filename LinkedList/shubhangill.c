#include<stdio.h>

struct node{
        int data;
        struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

void insertAtFirst(int data){
        struct node* current = (struct node*) malloc(sizeof(struct node));
        current -> data = data;
        current -> next = head;
        head = current;
}

int main(){
    
    int count = 3;
    while(count != 0){
        insertAtFirst(count);
    }
}