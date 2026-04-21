#pragma once
#ifndef SPARSE_H
#define SPARSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Term;

typedef Term Element;

typedef struct {
    Element* data;
    int size;
    int capacity;
} SeqList;

typedef struct {
    int row;
    int col;
    SeqList** list;
} SparseMatrix;

void initSeqList(SeqList* list, int capacity);
void insertTerm(SeqList* list, int row, int col, int value);
void transpose(SparseMatrix* a, SparseMatrix* b);
void printSparse(SparseMatrix* s);
void freeSeqList(SeqList* list);

#endif