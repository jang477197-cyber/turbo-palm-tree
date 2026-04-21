#define _CRT_SECURE_NO_WARNINGS
#include "list1.h"

void initList(SeqList* list, int capacity) {
    list->data = (Element*)malloc(sizeof(Element) * capacity);

    if (list->data == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    list->size = 0;
    list->capacity = capacity;
}

void insertAt(SeqList* list, int pos, Element item) {
    if (item <= 0 || pos < 0 || pos > list->size) {
        printf("삽입 오류\n");
        return;
    }

    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (Element*)realloc(list->data, sizeof(Element) * list->capacity);

        if (list->data == NULL) {
            printf("메모리 재할당 실패\n");
            exit(1);
        }
    }

    for (int i = list->size; i > pos; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[pos] = item;
    list->size++;
}

void deleteAt(SeqList* list, int pos) {
    if (pos < 0 || pos >= list->size) {
        printf("삭제 오류\n");
        return;
    }

    for (int i = pos; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
}

void replaceAt(SeqList* list, int pos, Element item) {
    if (item <= 0 || pos < 0 || pos >= list->size) {
        printf("변경 오류\n");
        return;
    }

    list->data[pos] = item;
}

void printList(SeqList* list) {
    if (list->size == 0) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    printf("리스트 내용: ");
    for (int i = 0; i < list->size; i++) {
        printf("[%d]=%d ", i, list->data[i]);
    }
    printf("\n");
}

void clearList(SeqList* list) {
    list->size = 0;
}

void freeList(SeqList* list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}