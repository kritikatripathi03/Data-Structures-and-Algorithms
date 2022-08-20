#include<iostream>
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
        int value = this -> data;
        while(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
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


void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int getCount(Node* head){
    int count = 0;
    Node* curr = head;
    while(curr != NULL){
        curr = curr -> next;
        count ++;
    }
    return count;
}

void deleteNode(Node* head, int position, Node* tail){
    if(position == 1){
        Node* temp = head;
        head = head -> next;
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
        if(position == getCount(head)){
            tail = prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

//Approach1
void removeDuplicates(Node* head, Node* tail){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    int position = 1;
    while(temp != NULL){
        while((temp -> next != NULL) && (temp -> next -> data == temp -> data)){
            deleteNode(head, position + 1, tail);
        }
        temp = temp -> next;
    }
}

//Approach2
Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(head == NULL){
        return head;
    }
    
    Node* curr = head;
    while(curr != NULL){
        while((curr -> next != NULL) && (curr -> next -> data == curr -> data)){
            Node* next_next = curr -> next -> next;
            delete(curr -> next);
            curr -> next = next_next;
        }
        curr = curr -> next;
    }
    return head;
}

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
        curr = curr -> next;
    }
}

int main(){
        Node* node1 = new Node(15);

    Node* head = node1;
    Node* tail = node1;

    insertionAtHead(head, 12);
    
    insertionAtTail(tail, 15);

    insertionAtTail(tail, 11);
    
    insertionAtTail(tail, 12);

    print(head);

    removeduplicates(head);

    print(head);
    return 0;
}