#include "list.h"

int main() {
    SeqList list;

    // 초기 용량 3으로 리스트 생성
    initList(&list, 3);

    // 데이터 삽입
    for (int i = 1; i <= 10; i++) {
        insertLast(&list, i * 10);
    }

    // 리스트 출력
    printList(&list);

    // 메모리 해제
    freeList(&list);

    return 0;
}