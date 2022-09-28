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
    ~Node() {
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
    }
    }
};

bool has_loop(Node* head){
    if(head == NULL){
        return false;
    }
    Node* temp = head;
    map<Node*, bool> visited;
    while(temp != NULL){
        if(visited[temp] == true){
            cout << "Loop at " << temp -> data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

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

Node* floydDetectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    if(head == NULL){
        return NULL;
    }

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next; 
        }
        slow = slow -> next;
        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingPoint(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* fast = floydDetectLoop(head);
    Node* slow = head;
    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL)
        return;

    Node* startOfLoop = getStartingPoint(head);
    Node* traverse = startOfLoop;
    while(traverse -> next != startOfLoop)
        traverse = traverse -> next;
    traverse -> next = NULL;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertionAtHead(head, 12);
    
    insertionAtTail(tail, 15);

    insertionAtPosition(tail, head, 1, 22);
    
    insertionAtPosition(tail, head, 4, 3);

    print(head);

    tail -> next = head -> next;

    //print(head);

    cout << has_loop(head) << endl;
    cout << floydDetectLoop(head) -> data << endl;
    Node* intersection = getStartingPoint(head);
    cout << intersection -> data << endl;

    removeLoop(head);

    print(head);

    cout << head -> data << endl;
    cout << tail -> data << endl;
    return 0;
}

/**#include <iostream>
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
  Node * getHead();
  bool isEmpty(){
    return head == nullptr;
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
  //printList();
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
  if(detectLoop()){
    return "";
    }
    Node* current = head;
    string result = "";
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
  string reverse();
  void insertLoop(){
    Node* current = head -> nextElement;
    current -> nextElement = head;
    };
  bool detectLoop();
};

bool LinkedList::detectLoop(){
  // Write your code here
  if(isEmpty()){
    return false;
    }
  Node* slow = head;
  Node* fast = head;
  while(fast != nullptr && slow != nullptr){
    fast = fast -> nextElement;
    if(fast != nullptr){
        fast = fast -> nextElement;
    }
    slow = slow -> nextElement;
    if(fast -> data == slow -> data){
        return true;
    }
    }
  return false;
}**/