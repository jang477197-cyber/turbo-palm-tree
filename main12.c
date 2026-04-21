#define _CRT_SECURE_NO_WARNINGS
#include "list1.h"

int main() {
    SeqList list;
    int menu, pos, value;

    initList(&list, 3);

    while (1) {
        printf("\n===== 메뉴 =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Replace\n");
        printf("4. Print\n");
        printf("5. Clear\n");
        printf("0. Exit\n");
        printf("선택: ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf("삽입할 위치와 값을 입력하세요: ");
            scanf("%d %d", &pos, &value);
            insertAt(&list, pos, value);
            break;

        case 2:
            printf("삭제할 위치를 입력하세요: ");
            scanf("%d", &pos);
            deleteAt(&list, pos);
            break;

        case 3:
            printf("변경할 위치와 값을 입력하세요: ");
            scanf("%d %d", &pos, &value);
            replaceAt(&list, pos, value);
            break;

        case 4:
            printList(&list);
            break;

        case 5:
            clearList(&list);
            printf("리스트가 초기화되었습니다.\n");
            break;

        case 0:
            freeList(&list);
            printf("프로그램 종료\n");
            return 0;

        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}