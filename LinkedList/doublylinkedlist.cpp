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

    //destructor
    ~Node(){
        int val =this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
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

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        head -> prev = temp;
        temp -> next = head;
        head = temp;
    }
    
}

void insertAtTail(Node* &tail, Node* &head, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
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
        insertAtHead(head, tail, d);
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
        insertAtTail(tail, head, d);
        return;
    }
    num -> next = temp -> next;
    temp -> next -> prev = num;
    temp -> next = num;
    num -> prev = temp;

}

void deleteNode(int position, Node* &head, Node* &tail){

    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;        
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }
        if(position == GetCount(head)){
            tail = prev;
        }
        prev -> next = curr -> next;
        curr -> prev = NULL;
        curr -> next = NULL; 

        delete curr;
    }
}

int main(){
    //Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    /*cout << GetCount(head) << endl;

    insertAtHead(head, tail, 5);

    print(head);

    insertAtTail(tail, head, 15);

    print(head);*/

    insertAtHead(head, tail, 0);

    print(head);

    /*insertAtTail(tail, head, 25);

    print(head);

    insertAtPosition(20, head, tail, 5);

    print(head);*/

    deleteNode(1, head, tail);

    print(head);

    //cout << tail -> data << endl;

    return 0;
}