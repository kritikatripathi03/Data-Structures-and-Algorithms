#include<iostream>
#include<string>
using namespace std;

class Node {
    public:
    int data;
    Node* nextElement;

    Node() {
        nextElement = nullptr;
    }
};

class LinkedList {
    private: 
    Node* head;
    public:
    LinkedList(){
        head -> data = 0;
        head -> nextElement = NULL;
    };
    Node* get_head();
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        return false;
    };
    bool printList(){
        if(isEmpty()){
            return false;
        }
        Node* temp = head;
        while(temp -> nextElement != NULL){
            cout << temp -> data << " -> ";
            temp = temp -> nextElement;
        }
        cout << "null" << endl;
        return true;
    };
    void insertAtHead(int value){
        Node* current = new Node();
        current -> data = value;
        current -> nextElement = head;
        head = current;
    };
    string elements(){
        if(isEmpty()){
            cout << "List is Empty!" << endl;
        }
        string result = "";
        Node* current = head;
        while(current != NULL){
            result += to_string(current -> data);
            result += " -> ";
            current = current -> nextElement;
        }
        result += "null";
        return result;
    };
    void insertAtTail(int value);
    bool search(int value);
    bool deleteAtHead();
    bool Delete(int value);
    string reverse();
};

string LinkedList::reverse(){
    Node* current = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(current -> nextElement != NULL){
        forward = current -> nextElement;
        current -> nextElement = prev;
        prev = current;
        current= forward;
    }
    head = prev;
    return elements();
}

int main(){
    LinkedList list;
    for(int j = 1; j <= 7; j ++){
        list.insertAtHead(j);
    }
    list.printList();
    string reversed = list.reverse();
    cout << reversed << endl;
    return 0;
}