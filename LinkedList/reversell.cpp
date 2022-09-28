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
/** #include <iostream>
#include<map>
using namespace std;

class Node {
  public:
    int data; //Data to store (could be int,string,object etc)
  Node * nextElement; //Pointer to next element

  Node() {
    //Constructor to initialize nextElement of newlyCreated Node
    nextElement = nullptr;
  }
};

class LinkedList {
  private:
    Node * head;
  public:

    LinkedList(){
        head = nullptr;
    };
  Node * getHead(){
  return head;
  };
  bool isEmpty(){
    return head == nullptr;
    };
  bool printList();
  void insertAtHead(int value){
    Node* newNode = new Node();
    newNode -> data = value;
    if(isEmpty()){
        head = newNode;
    }
    else{
        newNode -> nextElement = head;
        head = newNode;
        }
    };
  string elements(){
    Node* current = reverse();
    string result ="";
    while(current != nullptr){
        result += to_string(current -> data);
        result += "->";
        current = current -> nextElement;
    }
    result += "null";
    return result;
    };
  void insertAtTail(int value);
  bool search(int value);
  bool deleteAtHead();
  bool Delete(int value);
  int length();
  Node* reverse(){
    Node* current = head;
    Node* prev = nullptr;
    Node*forward = nullptr;
    while(current != nullptr){
        forward = current -> nextElement;
        current -> nextElement = prev;
        prev = current;
        current = forward;
    }
    head = prev;
    return head;
    };
  string removeDuplicates();
  string Union(LinkedList list1, LinkedList list2);
  string Intersection(LinkedList list1, LinkedList list2);
};


string LinkedList::Union(LinkedList list1, LinkedList list2) {
    LinkedList result;
    Node* current = list1.getHead();
    map<int, bool> present;
    while(current != nullptr){
        if(present[current -> data] != true){
            present[current -> data] = true;
            result.insertAtHead(current -> data);
        }
        current = current -> nextElement;
    }
    current = list2.getHead();
    while(current != nullptr){
        if(present[current -> data] != true){
            present[current -> data] = true;
            result.insertAtHead(current -> data);
        }
        current = current -> nextElement;
    }
    return result.elements();
        
}
string LinkedList::Intersection(LinkedList list1, LinkedList list2) {
    LinkedList result;
    Node* current = list1.getHead();
    map<int, bool> present;
    while(current != nullptr){
        present[current -> data] = true;
        current = current -> nextElement;
    }
    current = list2.getHead();
    while(current != nullptr){
        if(present[current -> data] == true){
            result.insertAtHead(current -> data);
        }
        current = current -> nextElement;
    }
    return result.elements();
}**/

/** #include <iostream>

using namespace std;

class Node {
  public:
    int data; //Data to store (could be int,string,object etc)
  Node * nextElement; //Pointer to next element
  Node() {
    //Constructor to initialize nextElement of newlyCreated Node
    nextElement = nullptr;
  }
};

class LinkedList {
  private:
    Node * head;
  public:

    LinkedList(){
        head = nullptr;
    };
  Node * getHead(){
    return head;
    };
  bool isEmpty(){
    return head == NULL;
    };
  void printList(){
    Node* current = head;
    while(current != nullptr){
        cout << current -> data << "->";
        current = current -> nextElement;
    }
    cout << "null" << endl;
    };
  void insertAtHead(int value){
    Node* newNode = new Node();
    newNode -> data = value;
    if(isEmpty()){
        head = newNode;
    }
    else{
        newNode -> nextElement = head;
        head = newNode;
    }
    };
  string elements();
  void insertAtTail(int value);
  bool search(int value);
  bool deleteAtHead();
  bool Delete(int value);
  int length();
  Node* reverse(){
    Node* current = head;
    Node* prev = nullptr;
    Node* forward = nullptr;
    while(current != nullptr){
        forward = current -> nextElement;
        current -> nextElement = prev;
        prev = current;
        current = forward;
    }
    head = prev;
    return head;
    };
  int findNth(int n);
};

int LinkedList::findNth(int n){
    // Write your code here
    Node* current = reverse();
    while(n - 1 && current != nullptr){
        current = current -> nextElement;
        n--;
    }
    if(current == nullptr){
        return -1;
    }
    return current -> data;
}
 * 
 */