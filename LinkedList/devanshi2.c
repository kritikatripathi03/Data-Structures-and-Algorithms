#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummyHead = (struct Node*)malloc(sizeof(struct Node));
    dummyHead -> val = 0;
    dummyHead -> next = NULL;
    struct Node* p = l1, *q = l2, *curr = dummyHead;
    int carry = 0;

    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p -> val : 0;
        int y = (q != NULL) ? q -> val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr -> next = (struct Node*)malloc(sizeof(struct Node));
        curr -> next -> val = sum % 10;
        curr -> next -> next = NULL;
        curr = curr -> next;
        if (p != NULL) p = p -> next;
        if (q != NULL) q = q -> next;
    }

    if (carry > 0) {
        curr -> next = (struct Node*)malloc(sizeof(struct Node));
        curr -> next -> val = carry;
        curr -> next -> next = NULL;
    }

    return dummyHead -> next;
}

int main(){
    struct Node* l1 = (struct Node*)malloc(sizeof(struct Node));
    l1 -> val = 2;
    l1 -> next = (struct Node*)malloc(sizeof(struct Node));
    l1 -> next -> val = 4;
    l1 -> next -> next = (struct Node*)malloc(sizeof(struct Node));
    l1 -> next -> next -> val = 3;
    l1 -> next -> next -> next = NULL;

    struct Node* l2 = (struct Node*)malloc(sizeof(struct Node));
    l2 -> val = 5;
    l2 -> next = (struct Node*)malloc(sizeof(struct Node));
    l2 -> next -> val = 6;
    l2 -> next -> next = (struct Node*)malloc(sizeof(struct Node));
    l2 -> next -> next -> val = 4;
    l2 -> next -> next -> next = NULL;

    struct Node* l3 = addTwoNumbers(l1, l2);
    while(l3 != NULL){
        printf("%d ", l3 -> val);
        l3 = l3 -> next;
    }
    return 0;
}