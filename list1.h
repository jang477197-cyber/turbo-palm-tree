#pragma once
#ifndef LIST1_H
#define LIST1_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct {
    Element* data;
    int size;
    int capacity;
} SeqList;

void initList(SeqList* list, int capacity);
void insertAt(SeqList* list, int pos, Element item);
void deleteAt(SeqList* list, int pos);
void replaceAt(SeqList* list, int pos, Element item);
void printList(SeqList* list);
void clearList(SeqList* list);
void freeList(SeqList* list);

#endif