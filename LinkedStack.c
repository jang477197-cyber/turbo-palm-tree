#include "Linkedstack.h"

char* copyString(const char* str)
{
    char* temp;
    int len;

    if (str == NULL) {
        return NULL;
    }

    len = (int)strlen(str);

    temp = (char*)malloc(sizeof(char) * (len + 1));

    if (temp == NULL) {
        return NULL;
    }

    strcpy_s(temp, len + 1, str);

    return temp;
}

LinkedStack* createLinkedStack()
{
    LinkedStack* re = (LinkedStack*)malloc(sizeof(LinkedStack));

    if (re == NULL) {
        return NULL;
    }

    re->head = NULL;
    re->size = 0;

    return re;
}

void destroyLinkedStack(LinkedStack* s)
{
    Node* temp;
    Node* delNode;

    if (s == NULL) {
        return;
    }

    temp = s->head;

    while (temp != NULL) {
        delNode = temp;
        temp = temp->next;

        free(delNode->data);
        free(delNode);
    }

    free(s);
}

void destoryLinkedStack(LinkedStack* s)
{
    destroyLinkedStack(s);
}

int emptyLinkedStack(LinkedStack* s)
{
    if (s == NULL) {
        return 1;
    }

    return s->size == 0;
}

int fullLinkedStack(LinkedStack* s)
{
    return 0;
}

int pushLinkedStack(LinkedStack* s, stackElement item)
{
    Node* temp;

    if (s == NULL || item == NULL) {
        return 0;
    }

    temp = (Node*)malloc(sizeof(Node));

    if (temp == NULL) {
        return 0;
    }

    temp->data = copyString(item);

    if (temp->data == NULL) {
        free(temp);
        return 0;
    }

    temp->next = s->head;
    s->head = temp;
    s->size++;

    return 1;
}

stackElement popLinkedStack(LinkedStack* s)
{
    Node* delNode;
    stackElement data;

    if (emptyLinkedStack(s)) {
        return NULL;
    }

    delNode = s->head;
    data = delNode->data;

    s->head = delNode->next;
    s->size--;

    free(delNode);

    return data;
}

stackElement peekLinkedStack(LinkedStack* s)
{
    if (emptyLinkedStack(s)) {
        return NULL;
    }

    return s->head->data;
}

stackElement peakLinkedStack(LinkedStack* s)
{
    return peekLinkedStack(s);
}

void printLinkedStack(LinkedStack* s)
{
    Node* temp;

    if (s == NULL) {
        return;
    }

    printf("Stack:\n");
    printf("Size: %d\n", s->size);

    temp = s->head;

    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}