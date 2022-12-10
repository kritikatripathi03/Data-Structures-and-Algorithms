#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices;
    struct node** adjList;
};

struct node* createNode(int vertex){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> vertex = vertex;
    newNode -> next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> numVertices = vertices;
    graph -> adjList = malloc(vertices * sizeof(struct node*));
    int i;
    for(int i = 0; i < vertices; i ++){
        graph -> adjList[i] = NULL;
    }
    return graph;
}

struct Graph* insertEdge(struct Graph* graph, int source, int destination){
    struct node* newnode = createNode(destination);
    struct node* newnode2 = createNode(source);
    newnode -> next = graph -> adjList[source];
    graph -> adjList[source] = newnode;

    newnode2 -> next = graph -> adjList[destination];
    graph -> adjList[destination] = newnode2;   
}

void printGraph(struct Graph* graph){
    int v;
    struct node* temp;
    for(v = 0; v < graph -> numVertices; v ++){
        temp = graph -> adjList[v];
        printf("Vertex %d: ", v);
        while(temp){
            printf("%d ", temp -> vertex);
            temp = temp -> next;
        }
        printf("\n");
    }
}


void delEdge(struct Graph* graph, int data){
    struct node* temp;
    int v = 0;
    for(; v < graph -> numVertices; v ++){
        temp = graph ->adjList[v];
        while(temp){
            if(temp -> vertex == data){
                
            }
        }
    }
}

int main(){
    struct Graph* graph = createGraph(5);
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 3);
    insertEdge(graph, 2, 4);
    insertEdge(graph, 4, 3);
    printGraph(graph);
    return 0;
}