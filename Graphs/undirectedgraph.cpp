#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        next = NULL;
    }
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }
        Node* getHead(){
            return head;
        }
        void insertAtHead(int data){
            Node *newNode = new Node();
            newNode -> data = data;
            newNode -> next = head;
            head = newNode;
        }
        bool isEmpty(){
            if(head == nullptr){
                return true;
            }
            return false;
        }
        void printList(){
            if(isEmpty()){
                cout << "List is Empty!" << endl;
                return;
            }
            Node *temp = head;
            while(temp){
                cout << temp -> data << " -> ";
                temp = temp -> next;
            }
            cout << "NULL" << endl;
        }
        void insertAtTail(int data){
            if(isEmpty()){
                insertAtHead(data);
                return;
            }
            Node* newNode = new Node();
            newNode -> data = data;
            Node *temp = head;
            while(temp -> next){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = nullptr;
        }
        bool search(int data){
            if(isEmpty()){
                return false;
            }
            Node *temp = head;
            while(temp){
                if(temp -> data == data){
                    return true;
                }
                temp = temp -> next;
            }
            return false;
        }
        bool deleteAtHead(int data){
            bool deleted = false;
            if(isEmpty()){
                return false;
            }
            Node *temp = head;
            if(temp -> data == data){
                head = temp -> next;
                deleted = true;
                return deleted;
            }
        }
        bool deleteAtTail(int data){
            bool deleted = false;
            if(isEmpty()){
                return false;
            }
            Node *temp = head;
            if(temp -> data == data){
                deleteAtHead(data);
                deleted = true;
                return deleted;
            }
            Node* prevNode = temp;
            Node* currNode = temp -> next;
            while(currNode){
                if(currNode -> data == data){
                    prevNode -> next = currNode -> next;
                    deleted = true;
                    break;
                }
                prevNode = currNode;
                currNode = currNode -> next;
            }
            if(deleted == false){
                cout << "Element was not found!" << endl;
            }
            else{
                cout << "Element was deleted!" << endl;
            }
            return deleted;
        }
};

class Graph{
private:
    int vertices;
    LinkedList *array;
public:
    Graph(int v) {
        array = new LinkedList[v];
        vertices = v;
    }
    //this is an undirected graph
    void addEdge(int source, int destination){
        if(source < vertices && destination < vertices){
            array[source].insertAtHead(destination);
            array[destination].insertAtHead(source);
        }
    }

    void printGraph(){
        cout << "Adjacent List of Undirected Graph:" << endl;
        Node* temp;
        for(int i = 0; i < vertices; i ++){
            cout << "|" << i << "| => ";
            temp = array[i].getHead();
            while(temp){
                cout << temp -> data << " -> ";
                temp = temp -> next;
            }
            cout << "NULL" << endl;
        }
    }
    LinkedList* getArray(){
        return array;
    }
    int getVertices(){
        return vertices;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    cout << endl;
    g.printGraph();
    return 0;
}