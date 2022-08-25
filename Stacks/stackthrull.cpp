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
    void push(int d)
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

    void pop(){
        if(top != NULL){
            Node* curr = head;
            Node* prev = NULL;
            Node* temp = head;
            cnt = 0;
            while(temp != NULL){
                temp = temp -> next;
                cnt ++;
            }
            if(cnt == 1){
                top = NULL;
                return;
            }
            int c = 1;
            while (c < cnt){
                prev = curr;
                curr = curr -> next;
                c ++;
            }
            top = prev;
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
    }
    void peek(){
        if(top != NULL){
            cout << top -> data << endl;
            return;
        }
        else{
            cout << -1 << endl;
            return;
        }
    }
    bool isEmpty(){
        if(top != NULL){
            return false;
        }
        return true;
    }
};

int main()
{
    Stack st(5);
    st.peek();
    st.push(22);
    st.peek();
    st.push(34);
    st.peek();
    st.push(55);
    st.peek();
    st.pop();
    st.peek();
    cout << st.isEmpty() << endl;
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.peek();
    cout << st.isEmpty() << endl;
    return 0;
}