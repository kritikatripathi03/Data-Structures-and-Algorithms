#include<iostream>
#include<string>

using namespace std;

class Node{
    public:
    int data;
    Node* nextElement;

    Node(){
        nextElement = nullptr;
    }
};

class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head -> data = 0;
        head -> nextElement = NULL;
    };
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
        Node* current = head;
        while(current -> nextElement != NULL){
            cout << current -> data << " -> ";
            current = current -> nextElement;
        }
        cout << "null" << endl;
        return true;
    };
    void insertAtHead(int value){
        Node* current = new Node;
        current -> data = value;
        current -> nextElement = head;
        head = current;
    };
    string elements(){
        if(isEmpty()){
            cout << "List is Empty!" << endl;
        }
        Node* current = head;
        string result = "";
        while(current != NULL){
            result += to_string(current -> data);
            result += " -> ";
            current = current -> nextElement;
        }
        result += "null";
        return result;
    }
    void reverse(){
        Node* current = head;
        Node* forward = NULL;
        Node* prev = NULL;
        while(current -> nextElement != NULL){
            forward = current -> nextElement;
            current -> nextElement = prev;
            prev = current;
            current = forward;
        }
        head = prev;
        cout << elements() << endl;
    };
    void insertLoop(){
        if(isEmpty()){
            return;
        }
        Node* tail = head;
        while(tail -> nextElement){
            tail = tail -> nextElement;
        }
        tail -> nextElement = head -> nextElement;
    };
    bool detectLoop(){
        Node* slow = head;
        Node* fast = head;

        if(head == NULL){
            return NULL;
        }

        while(slow != NULL && fast != NULL){
            fast = fast -> nextElement;
            if(fast != NULL){
                fast = fast -> nextElement; 
            }
            slow = slow -> nextElement;
            if(fast == slow){
                return true;
            }
        }
        return false;
    };
};

int main(){
    LinkedList list;
    for(int i = 1; i <= 7; i ++){
        list.insertAtHead(i);
    }
    list.insertLoop();
    //list.printList();
    string listLoop = list.elements();
    cout << listLoop << endl;
    bool checkLoop = list.detectLoop();
    if(checkLoop){
        cout << "True" << endl;
    }
    else cout << "False" << endl;
    return 0;
}