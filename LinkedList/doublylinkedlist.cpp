#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int GetCount(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp -> next;
        cnt ++;
    }
    return cnt;
}

void insertAtHead(Node* &head, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        head -> prev = temp;
        temp -> next = head;
        head = temp;
    }
    
}

void insertAtTail(Node* &tail, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(int d, Node* &head, Node* &tail, int position){
    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    Node* num = new Node(d);
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp -> next;
        cnt ++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }
    num -> next = temp -> next;
    temp -> next -> prev = num;
    temp -> next = num;
    num -> prev = temp;

}

int main(){
    //Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    cout << GetCount(head) << endl;

    insertAtHead(head, 5);

    print(head);

    insertAtTail(tail, 15);

    print(head);

    insertAtHead(head, 0);

    print(head);

    insertAtTail(tail, 25);

    print(head);

    insertAtPosition(20, head, tail, 5);

    print(head);

    return 0;
}