#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

// 순차 리스트 구조체
typedef struct {
    Element* data;   // 동적 배열
    int size;        // 현재 저장된 원소 개수
    int capacity;    // 배열의 총 크기
} SeqList;

// 함수 선언
void initList(SeqList* list, int capacity);
void insertLast(SeqList* list, Element item);
void printList(SeqList* list);
void freeList(SeqList* list);

#endif#pragma once
