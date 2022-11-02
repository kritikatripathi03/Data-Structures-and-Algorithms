#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;

};

struct node * head;

int main(){
    int num = 3;
    int * n = &num;

    struct node * new_node = (struct node*)malloc(sizeof(struct node*));
    new_node -> data = 5;
    head = new_node;
    struct node * next_node = (struct node*)malloc(sizeof(struct node*));
    next_node -> data = 77;
    new_node -> next = next_node;
    //new_node -> data = 5;
    //head = new_node;

    printf("%d ", head -> next -> data);
    printf("%u %d", new_node -> next -> data, next_node -> data);
    
   /**struct node* n1 = (struct node*)malloc(sizeof(struct node*));
   n1 -> data = 3;
   printf("%d\n", n1 -> data);
   
   struct node* n2 = (struct node*)malloc(sizeof(struct node*));
   n2 -> data = 44;
   printf("%d\n", n2 -> data);

   struct node* n3 = (struct node*)malloc(sizeof(struct node*));
   n3 -> data = 77;
   printf("%d\n", n3 -> data);
   **/
   return 0;
}