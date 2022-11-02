#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//void insert(struct Node ** head, struct Node ** temp);
//void printlist(struct Node*);
struct node** insert (struct Node **head, struct Node **temp){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    int data; char ch;
    printf("Enter the data:");
    scanf("%d", &data);
    newnode -> data = data;
    newnode -> next = *head;
    *head = newnode;
    printf("Do you want to enter the data in the linked list?(Y or y):");
    scanf("%c", &ch);
    if (ch=='Y' || ch=='y'){
        insert(head, temp);
    }
    return head;
}

void printlist(struct Node *head){
    struct Node *n = head;
    printf("Data:\n");
    while (n!=NULL){
        printf("%d\n", n->data);
        n=n->next;
    }
    return ;
}

int main(){
    struct Node *head=NULL, *temp=NULL;
    char ch;
    printf("Do you want to enter the data in the linked list?(Y or y):");
    scanf("%c", &ch);
    if (ch=='Y' || ch=='y'){
        head = insert(&head, &temp);
    }
    else{
        return 0;
    }
    printlist(head);
    return 0;
}