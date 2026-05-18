#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LinkedList1.h"

void printMenu() {
    printf("\n===== 이중 원형 연결리스트 메뉴 =====\n");
    printf("1. 맨 앞에 추가\n");
    printf("2. 맨 뒤에 추가\n");
    printf("3. 특정 위치에 추가\n");
    printf("4. 특정 위치 삭제\n");
    printf("5. 전체 목록 출력\n");
    printf("6. 리스트 크기 확인\n");
    printf("0. 종료\n");
    printf("메뉴 선택: ");
}

int main() {
    LinkedList* li;
    int menu;
    int item;
    int index;
    int deletedData;

    li = createLinkedList();

    if (li == NULL) {
        printf("리스트 생성 실패\n");
        return 1;
    }

    while (1) {
        printMenu();
        scanf("%d", &menu);

        if (menu == 1) {
            printf("추가할 정수 입력: ");
            scanf("%d", &item);

            if (insertFirstLinkedList(li, item)) {
                printf("맨 앞에 추가되었습니다.\n");
            }
            else {
                printf("추가 실패\n");
            }
        }
        else if (menu == 2) {
            printf("추가할 정수 입력: ");
            scanf("%d", &item);

            if (insertLastLinkedList(li, item)) {
                printf("맨 뒤에 추가되었습니다.\n");
            }
            else {
                printf("추가 실패\n");
            }
        }
        else if (menu == 3) {
            printf("추가할 위치 index 입력: ");
            scanf("%d", &index);

            printf("추가할 정수 입력: ");
            scanf("%d", &item);

            if (insertAtLinkedList(li, index, item)) {
                printf("해당 위치에 추가되었습니다.\n");
            }
            else {
                printf("잘못된 위치입니다.\n");
            }
        }
        else if (menu == 4) {
            printf("삭제할 위치 index 입력: ");
            scanf("%d", &index);

            if (deleteAtLinkedList(li, index, &deletedData)) {
                printf("삭제된 값: %d\n", deletedData);
            }
            else {
                printf("잘못된 위치입니다.\n");
            }
        }
        else if (menu == 5) {
            printLinkedList(li);
        }
        else if (menu == 6) {
            printf("현재 리스트 크기: %d\n", sizeLinkedList(li));
        }
        else if (menu == 0) {
            destroyLinkedList(li);
            printf("모든 메모리를 해제하고 프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 메뉴입니다.\n");
        }
    }

    return 0;
}