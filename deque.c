#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int key;
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

int main(void) {
    srand((unsigned int) time(NULL));

    push_front(0);
    push_front(1);
    push_back(2);
    push_back(3);
    push_front(-2);
    int popped = pop_front();
    printf("popped value: %d\n", popped);
    popped = pop_back();
    printf("popped value: %d\n", popped);
    
    print();
    
    reverse();
    
    print();
    
    free_list();
}

void print() {
    Node *current = head;
    while(current != NULL) {
        printf("key: %d, value: %d\n", current->key, current->data);
        current = current->next;
    }
}

void push_front(int data) {
    Node *newNode = NULL;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> key = rand();
    newNode -> data = data;
    newNode -> next = head;
    newNode -> prev = NULL;
    if(head == NULL) {
        tail = newNode;
    }
    else {
        head->prev = newNode;
    }
    head = newNode;
}

void push_back(int data) {
    Node *newNode = NULL;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> key = rand();
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = tail;
    tail -> next = newNode;
    tail = newNode;
}

int pop_front() {
    if(head != NULL) {
        Node* temp = head;
        int result = temp->data;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return result;
    }
}

int pop_back() {
    if(tail != NULL) {
        Node* temp = tail;
        int result = temp->data;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        return result;
    }
}

void reverse() {
    Node* current = head;
    tail = current;
    while(current != NULL) {
        Node* prev = current->prev;
        current->prev = current->next;
        current->next = prev;
        if(current->prev == NULL) {
            head = current;
        }
        current = current->prev;
    }
}

void free_list() {
    Node* current = head;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}
