#include<bits/stdc++.h>
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

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail,  int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

int getCount(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count ++;
    }
    return count;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    else{
        int cnt = 1;
        Node* temp = head;
        while(cnt < position - 1){
            temp = temp -> next;
            cnt ++;
        }
        if(position == getCount(head)){
            insertAtTail(tail, data);
            return;
        }
        Node* nodeToInsert = new Node(data);
        nodeToInsert -> next = temp -> next;
        temp -> next = nodeToInsert;

    }
}

void deleteNode(Node* head, Node* tail, int position){
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;

        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }

        if(position == getCount(head)){
            tail = prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}

int main(){
    
    return 0;
}