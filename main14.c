#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size = 0;

    return list;
}

void destroyLinkedList(LinkedList* list) {
    Node* current = list->head;
    Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(list);
}

int isEmptyLinkedList(LinkedList* list) {
    if (list->head == NULL)
        return 1;
    else
        return 0;
}

int sizeLinkedList(LinkedList* list) {
    return list->size;
}

void insertFirstLinkedList(LinkedList* list, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = item;
    newNode->next = list->head;

    list->head = newNode;
    list->size++;
}

void insertLastLinkedList(LinkedList* list, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* current;

    newNode->data = item;
    newNode->next = NULL;

    if (isEmptyLinkedList(list)) {
        list->head = newNode;
    }
    else {
        current = list->head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }

    list->size++;
}

int insertAtLinkedList(LinkedList* list, int at, int item) {
    Node* newNode;
    Node* current;
    int i;

    if (at < 0 || at > list->size) {
        return 0;
    }

    if (at == 0) {
        insertFirstLinkedList(list, item);
        return 1;
    }

    current = list->head;

    for (i = 0; i < at - 1; i++) {
        current = current->next;
    }

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = current->next;
    current->next = newNode;

    list->size++;

    return 1;
}

int deleteAtLinkedList(LinkedList* list, int at, int* deletedData) {
    Node* current;
    Node* deleteNode;
    int i;

    if (at < 0 || at >= list->size) {
        return 0;
    }

    if (isEmptyLinkedList(list)) {
        return 0;
    }

    if (at == 0) {
        deleteNode = list->head;
        list->head = list->head->next;
    }
    else {
        current = list->head;

        for (i = 0; i < at - 1; i++) {
            current = current->next;
        }

        deleteNode = current->next;
        current->next = deleteNode->next;
    }

    *deletedData = deleteNode->data;
    free(deleteNode);
    list->size--;

    return 1;
}

void printLinkedList(LinkedList* list) {
    Node* current = list->head;

    if (isEmptyLinkedList(list)) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    printf("전체 목록: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void printMenu() {
    printf("\n===== 연결리스트 메뉴 =====\n");
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
    LinkedList* list = createLinkedList();

    int menu;
    int item;
    int index;
    int deletedData;

    while (1) {
        printMenu();
        scanf("%d", &menu);

        if (menu == 1) {
            printf("추가할 정수 입력: ");
            scanf("%d", &item);

            insertFirstLinkedList(list, item);
            printf("맨 앞에 추가되었습니다.\n");
        }
        else if (menu == 2) {
            printf("추가할 정수 입력: ");
            scanf("%d", &item);

            insertLastLinkedList(list, item);
            printf("맨 뒤에 추가되었습니다.\n");
        }
        else if (menu == 3) {
            printf("추가할 위치 index 입력: ");
            scanf("%d", &index);

            printf("추가할 정수 입력: ");
            scanf("%d", &item);

            if (insertAtLinkedList(list, index, item)) {
                printf("해당 위치에 추가되었습니다.\n");
            }
            else {
                printf("잘못된 위치입니다.\n");
            }
        }
        else if (menu == 4) {
            printf("삭제할 위치 index 입력: ");
            scanf("%d", &index);

            if (deleteAtLinkedList(list, index, &deletedData)) {
                printf("삭제된 값: %d\n", deletedData);
            }
            else {
                printf("잘못된 위치입니다.\n");
            }
        }
        else if (menu == 5) {
            printLinkedList(list);
        }
        else if (menu == 6) {
            printf("현재 리스트 크기: %d\n", sizeLinkedList(list));
        }
        else if (menu == 0) {
            destroyLinkedList(list);
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 메뉴입니다.\n");
        }
    }

    return 0;
}