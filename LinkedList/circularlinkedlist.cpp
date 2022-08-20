#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int val = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
    }

};

void insertAtNode(Node* &tail, int element, int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* &tail){
    Node* temp = tail;

    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return;
    }

    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int element){
    if(tail == NULL){
        cout << "List is empty!" << endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;
        while(curr -> data != element){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        //>= 2 Node LL
        if(curr == prev){
            tail = NULL; // tail is still pointing to 3, so, need to point it to last element
        }
        //1 Node LL
        else if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    Node* tail = NULL;

    insertAtNode(tail, 5, 3);

    print(tail);

    /*insertAtNode(tail, 3, 5);

    print(tail);

    insertAtNode(tail, 5, 7);

    print(tail);

    insertAtNode(tail, 7, 9);

    print(tail);

    insertAtNode(tail, 5, 6);

    print(tail);

    insertAtNode(tail, 9, 8);

    print(tail);

    insertAtNode(tail, 3, 1);

    print(tail);

    deleteNode(tail, 1);

    print(tail);*/

    deleteNode(tail, 3);

    print(tail);

    return 0;
}