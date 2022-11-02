#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
void count_nodes(NODE *head){
    int count=0;
    if (head == NULL)
    {
        printf("Linked List is EMPTY!");
    }
    NODE *ptr = head;
    while (ptr != NULL){
    count++;
    ptr = ptr->next;
    }
    printf("\nNo. of Nodes: %d\n", count);
}

void print_data(NODE *head){
    if(head == NULL)
    printf("Linked List is Empty!");

    NODE *ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }    
}

void insert_at_end(int item, NODE *head){
    NODE *ptr, *temp;

    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->next = NULL;

    ptr = head;

    if(head == NULL){
        printf("Linked List is Empty!");
        head->next = temp;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
    }
    ptr->next = temp;
}

void insert_at_beg(int item, NODE **head){
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->next = *head;
    *head = temp;
}

int main(){

    NODE *head = (NODE *)malloc(sizeof(NODE));

    head->data = 45;
    head->next = NULL;

    insert_at_end(95, head);
    insert_at_end(85, head);
    insert_at_end(55, head);

    count_nodes(head);
    print_data(head);
    printf("\n%d\n", head -> data);
    insert_at_beg(25, &head);
    count_nodes(head);
    print_data(head);
    return 0;
}