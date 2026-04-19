#include "list.h"

// 리스트 초기화 함수
void initList(SeqList* list, int capacity) {
    list->data = (Element*)malloc(sizeof(Element) * capacity);

    if (list->data == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    list->size = 0;
    list->capacity = capacity;
}

// 리스트 끝에 데이터 삽입
void insertLast(SeqList* list, Element item) {
    // 배열이 가득 찼다면 크기 증가
    if (list->size == list->capacity) {
        list->capacity *= 2;

        Element* temp = (Element*)realloc(list->data, sizeof(Element) * list->capacity);

        if (temp == NULL) {
            printf("메모리 재할당 실패\n");
            exit(1);
        }

        list->data = temp;

        printf("배열 크기 증가: %d\n", list->capacity);
    }

    list->data[list->size] = item;
    list->size++;
}

// 리스트 출력 함수
void printList(SeqList* list) {
    printf("리스트 내용: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 메모리 해제 함수
void freeList(SeqList* list) {
    free(list->data);
    list->data = NULL;
}