#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* stackElement;

typedef struct node {
    stackElement data;
    struct node* next;
} Node;

typedef struct linkedStack {
    Node* head;
    int size;
} LinkedStack;

extern LinkedStack* createLinkedStack();

extern void destroyLinkedStack(LinkedStack* s);
extern void destoryLinkedStack(LinkedStack* s);

extern int emptyLinkedStack(LinkedStack* s);
extern int fullLinkedStack(LinkedStack* s);

extern int pushLinkedStack(LinkedStack* s, stackElement item);
extern stackElement popLinkedStack(LinkedStack* s);

extern stackElement peekLinkedStack(LinkedStack* s);
extern stackElement peakLinkedStack(LinkedStack* s);

extern void printLinkedStack(LinkedStack* s);

#endif