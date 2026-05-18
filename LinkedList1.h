#ifndef LINKED_LIST1_H
#define LINKED_LIST1_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* createLinkedList();
void destroyLinkedList(LinkedList* li);

int isEmptyLinkedList(LinkedList* li);
int sizeLinkedList(LinkedList* li);

int insertFirstLinkedList(LinkedList* li, int item);
int insertLastLinkedList(LinkedList* li, int item);
int insertAtLinkedList(LinkedList* li, int at, int item);

int deleteAtLinkedList(LinkedList* li, int at, int* deletedData);

void printLinkedList(LinkedList* li);

#endif