#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList1.h"

LinkedList* createLinkedList() {
    LinkedList* li;

    li = (LinkedList*)malloc(sizeof(LinkedList));

    if (li == NULL) {
        return NULL;
    }

    li->head = NULL;
    li->size = 0;

    return li;
}

void destroyLinkedList(LinkedList* li) {
    Node* current;
    Node* temp;
    int i;

    if (li == NULL) {
        return;
    }

    current = li->head;

    for (i = 0; i < li->size; i++) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(li);
}

int isEmptyLinkedList(LinkedList* li) {
    if (li->size == 0) {
        return 1;
    }

    return 0;
}

int sizeLinkedList(LinkedList* li) {
    return li->size;
}

int insertFirstLinkedList(LinkedList* li, int item) {
    Node* newNode;
    Node* tail;

    newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        return 0;
    }

    newNode->data = item;

    if (isEmptyLinkedList(li)) {
        newNode->prev = newNode;
        newNode->next = newNode;
        li->head = newNode;
    }
    else {
        tail = li->head->prev;

        newNode->prev = tail;
        newNode->next = li->head;

        tail->next = newNode;
        li->head->prev = newNode;

        li->head = newNode;
    }

    li->size++;

    return 1;
}

int insertLastLinkedList(LinkedList* li, int item) {
    Node* newNode;
    Node* tail;

    newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        return 0;
    }

    newNode->data = item;

    if (isEmptyLinkedList(li)) {
        newNode->prev = newNode;
        newNode->next = newNode;
        li->head = newNode;
    }
    else {
        tail = li->head->prev;

        newNode->prev = tail;
        newNode->next = li->head;

        tail->next = newNode;
        li->head->prev = newNode;
    }

    li->size++;

    return 1;
}

int insertAtLinkedList(LinkedList* li, int at, int item) {
    Node* current;
    Node* newNode;
    int i;

    if (at < 0 || at > li->size) {
        return 0;
    }

    if (at == 0) {
        return insertFirstLinkedList(li, item);
    }

    if (at == li->size) {
        return insertLastLinkedList(li, item);
    }

    current = li->head;

    for (i = 0; i < at; i++) {
        current = current->next;
    }

    newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        return 0;
    }

    newNode->data = item;

    newNode->prev = current->prev;
    newNode->next = current;

    current->prev->next = newNode;
    current->prev = newNode;

    li->size++;

    return 1;
}

int deleteAtLinkedList(LinkedList* li, int at, int* deletedData) {
    Node* deleteNode;
    int i;

    if (isEmptyLinkedList(li)) {
        return 0;
    }

    if (at < 0 || at >= li->size) {
        return 0;
    }

    deleteNode = li->head;

    for (i = 0; i < at; i++) {
        deleteNode = deleteNode->next;
    }

    *deletedData = deleteNode->data;

    if (li->size == 1) {
        li->head = NULL;
    }
    else {
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;

        if (at == 0) {
            li->head = deleteNode->next;
        }
    }

    free(deleteNode);
    li->size--;

    return 1;
}

void printLinkedList(LinkedList* li) {
    Node* current;
    int i;

    if (isEmptyLinkedList(li)) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    current = li->head;

    printf("전체 목록: ");

    for (i = 0; i < li->size; i++) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}