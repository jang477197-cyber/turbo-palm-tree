#define _CRT_SECURE_NO_WARNINGS
#include "sparse.h"

int main() {
    SeqList* aList = (SeqList*)malloc(sizeof(SeqList));
    SeqList* bList = (SeqList*)malloc(sizeof(SeqList));

    initSeqList(aList, 20);
    initSeqList(bList, 20);

    insertTerm(aList, 0, 1, 5);
    insertTerm(aList, 0, 3, 8);
    insertTerm(aList, 1, 0, 3);
    insertTerm(aList, 1, 4, 7);
    insertTerm(aList, 2, 2, 6);
    insertTerm(aList, 2, 5, 1);
    insertTerm(aList, 3, 1, 9);
    insertTerm(aList, 3, 7, 4);
    insertTerm(aList, 4, 4, 2);
    insertTerm(aList, 4, 8, 6);
    insertTerm(aList, 5, 0, 7);
    insertTerm(aList, 5, 6, 5);
    insertTerm(aList, 6, 2, 8);
    insertTerm(aList, 6, 9, 3);
    insertTerm(aList, 7, 3, 4);
    insertTerm(aList, 7, 7, 2);
    insertTerm(aList, 8, 1, 6);
    insertTerm(aList, 8, 5, 9);
    insertTerm(aList, 9, 0, 1);
    insertTerm(aList, 9, 8, 7);

    SparseMatrix A = { 10, 10, &aList };
    SparseMatrix B = { 0, 0, &bList };

    printf("원본 희소행렬:\n");
    printSparse(&A);

    transpose(&A, &B);

    printf("\n전치 희소행렬:\n");
    printSparse(&B);

    freeSeqList(aList);
    freeSeqList(bList);

    free(aList);
    free(bList);

    return 0;
}