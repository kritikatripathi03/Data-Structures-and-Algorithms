#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(){
        next = NULL;
    }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head -> data = 0;
            head -> next = NULL;
        };
        void insertAtHead(int data){
            Node* newNode = new Node();
            newNode -> data = data;
            newNode -> next = head;
            head = newNode;
        }
        Node* getHead(){
            return head;
        }
};

class Graph{
    private:
        int vertices;
        LinkedList * array;
    public:
        Graph(int v){
            array = new LinkedList[v];
            vertices = v;
        };
        void addEdge(int source, int destinations){
            if (source < vertices && destinations < vertices)
                array[source].insertAtHead(destinations);
        }
        void printGraph(){
            cout << "Adjacent List of Directed Graph" << endl;
            Node* temp;
            for(int i = 0; i < vertices; i ++){
                cout << " | " << i << " | => ";
                temp = (array[i]).getHead();
            while(temp != NULL){
                cout << " [ " << temp -> data << " ] -> "; 
                temp = temp -> next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    cout << endl;
    g.printGraph();
    return 0;
}