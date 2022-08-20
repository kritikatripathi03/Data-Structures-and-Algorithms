#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        while(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};

void removeduplicates(Node* head){
    if(head == NULL){
        return;
    }
    Node* curr = head;
    while(curr != NULL){
        Node* prev = curr;
        Node* temp = curr -> next;
        while(temp != NULL){
            if(temp -> data == curr -> data){
                Node* next_next = temp -> next;
                delete temp;
                prev -> next = next_next;
            }
            prev = temp;
            temp = temp -> next;
        }
    }
}

int main(){

    return 0;
}