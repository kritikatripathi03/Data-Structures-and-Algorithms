#include<stdio.h>

int stack[10];
int top = 0;

void push(int data){
    stack[top ++] = data;
}

void pop(){
    int element = stack[top];
    top --;
}

int top(){
    return top;
}

void print(){
    int i = top;
    for(; i >= 0; i --){
        print("%d ", stack[i]);
    }
}

int main(){

}