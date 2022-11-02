#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertAtHead(struct node** head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;
    newNode -> data = data;
    newNode -> next = temp;
    *head = newNode;
}

void printList(struct node* head){
    struct node* current = head;
    while(current){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

void insertAtEnd(struct node* head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newNode -> data = data;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = NULL;
}

void insertAtPosition(struct node** head, int data, int position){
    int count = 1;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;
    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    else{
        newNode -> data = data;
        while(count < position - 1){
            temp = temp -> next;
            count ++;
        }
        if(temp -> next == NULL){
            insertAtEnd(*head, data);
            return;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void deleteAtHead(struct node** head){
    struct node* temp = *head;
    *head = temp -> next;
    free(temp);
}

void deleteAtEnd(struct node** head){
    struct node* prev = NULL;
    struct node* temp = *head;
    while(temp -> next){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
}

void deleteAtPosition(struct node** head, int position){
    struct node* prev = NULL;
    struct node* curr = *head;
    int count = 1;
    if(position == 1){
        deleteAtHead(head);
    }
    else{
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count ++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
    }
}

int getCount(struct node* head){
    struct node* temp = head;
    int count = 0;
    while(temp){
        temp = temp -> next;
        count ++;
    }
    return count;
}

void reverse(struct node** head){
    struct node* current = *head;
    struct node* forward = NULL;
    struct node* prev = NULL;
    while (current){
        forward = current -> next;
        current -> next = prev;
        prev = current;
        current = forward;
    }
    *head = prev;
}

int search(struct node* head, int data){
    struct node* temp = head;
    int count = 1;
    while(temp){
        if(temp -> data == data){
            return count;
        }
        temp = temp -> next;
        count ++; 
    }
    return -1;
}

void sort(struct node** head){
    struct node* temp = *head;
    struct node* current;
    struct node* other;
    int helper;
    while(temp -> next){
        current = temp;
        other = temp -> next;
        while(other){
            if(other -> data < current -> data){
                helper = current -> data;
                current -> data = other -> data;
                other -> data = helper;
            }
            other = other -> next;
        }
        temp = temp -> next;
    }
}

int detectLoop(struct node* head){
    struct node* slow = head;
    struct node* fast = head;
    while(fast && fast -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow){
            return 1;
        }
    }
    return 0;
}

void removeDuplicates(struct node** head){
    struct node* current = *head;
    struct node* temp = NULL;
    struct node* forward = NULL;
    int count = 1;
    while(current -> next){
        printf("%d \n", current -> data);
        temp = current -> next;
        while(temp -> next){
            forward = temp -> next;
            if(temp -> data == current -> data){
                deleteAtPosition(head, count); 
                count ++;
            }
            temp = forward;
        }
        current = current -> next;
    }
}

int main(){
    struct node* head = NULL;
    insertAtHead(&head, 4);
    printList(head);
    insertAtHead(&head, 5);
    printList(head);
    insertAtEnd(head, 6);
    printList(head);
    insertAtEnd(head, 7);
    printList(head);
    insertAtPosition(&head, 5, 3);
    printList(head);
    insertAtPosition(&head, 6, 1);
    printList(head);
    insertAtPosition(&head, 7, 7);
    printList(head);
    removeDuplicates(&head);
    printList(head);
    //head -> next -> next -> next = head;
    //printf("%d ", detectLoop(head));
    /**printList(head);
    printf("The count of the Linked List is: %d.\n", getCount(head));
    sort(&head);
    printList(head);
    deleteAtEnd(&head);
    printList(head);
    deleteAtHead(&head);
    printList(head);
    deleteAtPosition(&head, 3);
    printList(head);
    reverse(&head);
    printList(head);
    if(search(head, 5) != -1){
        printf("The element is present at the %d position.", search(head, 5));
    }
    else{
        printf("Sorry! The element is not present in the linked list.");
    }
    sort(&head);
    printList(head);**/
}