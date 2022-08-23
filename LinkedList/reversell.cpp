#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;    
    }

    ~Node(){
        int val = this -> data;
        while(this -> next != NULL){
            delete next; this -> next = NULL;
        }
    }
};

Node* reverse1(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void reverse2(Node* head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    reverse2(head, curr -> next, curr);
    curr -> next = prev;    
}

Node* reverse3(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* smallHead = reverse3(head -> next);
    head -> next -> next = head;
    head -> next= NULL;
    return smallHead;
}

int main(){

    return 0;
}