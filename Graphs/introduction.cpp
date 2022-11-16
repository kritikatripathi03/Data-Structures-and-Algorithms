#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *nextElement; // Pointer to next element
    Node()
    {
        nextElement = nullptr;
    }
};

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList() {
            head = nullptr;
        }
        bool isEmpty(){
            if (head == nullptr) // Check whether the head points to null
                return true;
            else
                return false;
        }

        Node *getHead(){
            return head;
        }

        bool printList() {
            if (isEmpty())
            {
                cout << "List is Empty!";
                return false;
            }
            Node *temp = head;
            cout << "List : ";

            while (temp != nullptr) {
                cout << temp->data << "->";
                temp = temp->nextElement;
            }
            cout << "null " << endl;
            return true;
        }

        bool insertAtHead(int value) {
            Node *newNode = new Node();
            newNode->data = value;
            newNode->nextElement = head; // Linking newNode to head's nextNode
            head = newNode;
            return true;
        }

        void insertAtTail(int value) {
            if (isEmpty()) { // inserting first element in list
                insertAtHead(value);
            }
            else {
                Node *newNode = new Node();
                Node *last = head;

                while (last->nextElement != nullptr) {
                    last = last->nextElement;
                }

                newNode->data = value;
                newNode->nextElement = nullptr;
                last->nextElement = newNode;
            }
    }

    bool search(int value) { // function to check if element exists in list
        Node *temp = head;

        while (temp != nullptr){
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->nextElement;
        }
        return false;
    }

    bool deleteAtHead(int value){

        bool deleted = false;
        if (isEmpty()) {
            return deleted;
        }
        Node *currentNode = head;
        Node *nextNode = head->nextElement; // nextNode point to head's nextElement

        if (currentNode->data == value) {
            currentNode = nextNode;
            head = currentNode;
            deleted = true;
            return deleted;
        }
        return deleted;
    }

    bool Delete(int value){
        bool deleted = false; // returns true if the node is deleted, false otherwise

        if (isEmpty()) { // check if the list is empty
            return deleted; // deleted will be false
        }

        Node *currentNode = head;     // currentNode to traverse the list  
        Node *previousNode = nullptr; // previousNode starts from null 

        if (currentNode->data == value)
        { // deleting value of head
            deleted = deleteAtHead(value);
            deleted = true; // true because value found and deleted
            return deleted; // returns true if the node is deleted
        }

        while (currentNode != nullptr) {
            if (value == currentNode->data) {
                previousNode->nextElement = currentNode->nextElement;
                deleted = true;
                break;
            }
            previousNode = currentNode;
            currentNode = currentNode->nextElement; // pointing current to current's nextElement
        }
        if (deleted == false){
            cout << value << " does not exist!" << endl;
        }
        else{
            cout << value << " deleted!" << endl;
        }
        return deleted;
    } // end of delete()
};

class Graph {
private:
    int vertices;
    LinkedList *array;

public:
    Graph(int v) {
        array = new LinkedList[v];
        vertices = v;
    }

    void addEdge(int source, int destination){
        if (source < vertices && destination < vertices){
            array[source].insertAtHead(destination);
            array[destination].insertAtHead(source);
        }
    }

    void printGraph() {
        cout << "Adjacency List of Undirected Graph" << endl;
        Node *temp;
        for (int i = 0; i < vertices; i++)
        {
            cout << "|" << i << "| => ";
            temp = (array[i]).getHead();

            while (temp != NULL) {
                cout << "[" << temp->data << "] -> ";
                temp = temp->nextElement;
            }
            cout << "NULL" << endl;
        }
    }

    LinkedList *getArray() {
        return array;
    }
    int getVertices() {
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