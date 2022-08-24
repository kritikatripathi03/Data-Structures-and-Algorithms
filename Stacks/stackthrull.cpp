#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        while(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};

class Stack
{
public:
    int size;
    int data;
    Node *head;
    Node *top;
    int cnt = 0;
    Stack(int size)
    {
        this->size = size;
        top = NULL;
        head = NULL;
    }
    push(int d)
    {
        if (size - cnt > 1)
        {
            Node* n = new Node(d);
            if (top == NULL)
            {
                top = n;
                head = top;
            }
            else
            {
                top -> next = n;
                top = n;
            }
            cnt++;
        }
    }

    pop(){
        if(top != NULL){
            Node* curr = head;
            Node* prev = NULL;

            int c = 1;
            while (cnt < cnt){
                prev = curr;
                curr = curr -> next;
                cnt ++;
            }
            tail = prev;
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
    }
    peek(){
        if(top != NULL){
            cout << top -> data << endl;
        }
    }
};

int main()
{

    return 0;
}