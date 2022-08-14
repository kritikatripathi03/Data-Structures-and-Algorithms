#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertionAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertionAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertionAtPosition(Node* &tail, Node* &head, int position, int d){
    if(position == 1){
        insertionAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp -> next;
        cnt ++;
    }

    if(temp -> next == NULL){
        insertionAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(int position, Node* &head){

    if(position == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;        
    }
    else{

    }
}

int main(){
    Node* node1 = new Node(1);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertionAtHead(head, 12);

    print(head);
    
    insertionAtTail(tail, 15);

    print(head);

    insertionAtPosition(tail, head, 1, 22);

    print(head);
    
    insertionAtPosition(tail, head, 4, 3);

    print(head);
    return 0;
}