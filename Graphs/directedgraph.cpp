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
            head = NULL;
        }
        Node* getHead(){
            return head;
        }
        bool isEmpty(){
            return head == NULL;
        }
        void insertAtHead(int data){
            Node* newNode = new Node();
            newNode -> data = data;
            newNode -> next = head;
            head = newNode;
        }
        void insertAtTail(int data){
            Node* newNode = new Node();
            newNode -> data = data;
            if(isEmpty()){
                insertAtHead(data);
                return;
            }
            Node* temp = head;
            while(temp -> next){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = NULL;
        }
        void printList(){
            Node* temp = head;
            while(temp){
                cout << temp -> data << " -> ";
                temp = temp -> next;
            }
            cout << "NULL" << endl;
        }
        void deleteAtHead(){
            Node* temp = head;
            head = temp ->next;
            free(temp);
        }
        bool deleteAtTail(int data){
            if(isEmpty()){
                return false;
            }
            if(head -> data == data){
                deleteAtHead();
                return true;
            }
            Node* curr = head -> next;
            Node* prev = head;
            while(curr -> next){
                if(curr -> data == data){
                    prev -> next = curr -> next;
                    free(curr);
                    return true;
                }
                prev = curr;
                curr = curr -> next;
                return false;
            }
        }
};

class Graph{
    private:
        int vertices;
        LinkedList* array;
    public:
        Graph(int v){
            array = new LinkedList[v];
            vertices = v;
        }
        void addEdge(int source, int destination){
            if(source < vertices && destination < vertices){
                array[source].insertAtHead(destination);
            }
        }
        void printGraph(){
            cout << "Adjacent list of directed graph:" << endl;
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