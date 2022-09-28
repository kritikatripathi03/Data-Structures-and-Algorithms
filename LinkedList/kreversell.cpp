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
};

Node* kreverse(Node* head, int k){
    if(head == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int cnt = 0;
    while(cnt < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt += 1;
    }
    if(curr != NULL){
        head -> next = kreverse(next, k);
    }
    return prev;
}

int main(){


}