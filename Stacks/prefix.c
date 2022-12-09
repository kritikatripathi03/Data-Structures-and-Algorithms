#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = top;
    top = temp;
}

int pop(){
    struct node* temp = top;
    int value = temp -> data;
    top = top -> next;
    free(temp);
    return value;
}

void printStack(){
    struct node* temp = top;
    while(temp){
        printf("%d ->", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int prefix(char arg[], int n){
    int one, two, result = 0;
    for(int i = 0; i < n; i ++){
        if(arg[i] >= 0 && arg[i] <= 9){
            push(arg[i] - '0');
        }
        else{
            one = pop();
            two = pop();
            if(arg[i] == '+'){
                result = one + two;
                push(result);
            }
            else if(arg[i] == '-'){
                result = one - two;
                push(result);
            }
            else if(arg[i] == '*'){
                result = one * two;
                push(result);
            }
            else{
                result = one / two;
                push(result);
            }
        }
    }
}

int main(){
    push(6);
    push(7);
    pop();
    printStack();
}