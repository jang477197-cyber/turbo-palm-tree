#define _CRT_SECURE_NO_WARNINGS
#include "sparse.h"

void initSeqList(SeqList* list, int capacity) {
    list->data = (Element*)malloc(sizeof(Element) * capacity);

    if (list->data == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    list->size = 0;
    list->capacity = capacity;
}

void insertTerm(SeqList* list, int row, int col, int value) {
    if (list->size >= list->capacity) {
        printf("희소행렬 공간 부족\n");
        return;
    }

    list->data[list->size].row = row;
    list->data[list->size].col = col;
    list->data[list->size].value = value;
    list->size++;
}

void transpose(SparseMatrix* a, SparseMatrix* b) {
    int moveCount = 0;

    b->row = a->col;
    b->col = a->row;

    for (int c = 0; c < a->col; c++) {
        for (int i = 0; i < (*a->list)->size; i++) {
            if ((*a->list)->data[i].col == c) {
                insertTerm(*b->list,
                    (*a->list)->data[i].col,
                    (*a->list)->data[i].row,
                    (*a->list)->data[i].value);
                moveCount++;
            }
        }
    }

    printf("\n데이터 이동 횟수: %d\n", moveCount);
}

void printSparse(SparseMatrix* s) {
    for (int i = 0; i < (*s->list)->size; i++) {
        printf("(%d, %d, %d)\n",
            (*s->list)->data[i].row,
            (*s->list)->data[i].col,
            (*s->list)->data[i].value);
    }
}

void freeSeqList(SeqList* list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}