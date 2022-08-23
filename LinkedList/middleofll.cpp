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

int getCount(Node* head){
    Node* temp = head;
    int cnt = 1;
    while(temp != NULL){
        cnt ++;
        temp = temp -> next;
    }
    return cnt;
}

Node* getMid1(Node* head){
    int len = getCount(head) / 2;
    Node* mid = head;
    int pos = 0;
    while(pos < len){
        mid = mid -> next;
    }
    return mid;
}

Node* girMid2(Node* head){
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

int main(){
    
}