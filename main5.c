#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int* arr;

    printf("홀수 크기 N 입력: ");
    scanf("%d", &N);

    if (N % 2 == 0) {
        printf("홀수만 입력 가능합니다.\n");
        return 0;
    }

    // 동적 할당
    arr = (int*)malloc(sizeof(int) * N * N);

    // 초기화
    for (int i = 0; i < N * N; i++) {
        *(arr + i) = 0;
    }

    int num = 1;
    int row = 0;
    int col = N / 2;

    // 마방진 생성
    while (num <= N * N) {
        *(arr + row * N + col) = num;

        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (*(arr + next_row * N + next_col) != 0) {
            row = (row + 1) % N;
        }
        else {
            row = next_row;
            col = next_col;
        }

        num++;
    }

    // 출력
    printf("\n마방진:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", *(arr + i * N + j));
        }
        printf("\n");
    }

    // 가로 합
    printf("\n각 가로의 합:\n");
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += *(arr + i * N + j);
        }
        printf("%d ", sum);
    }

    // 세로 합
    printf("\n각 세로의 합:\n");
    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += *(arr + i * N + j);
        }
        printf("%d ", sum);
    }

    // 대각선 합
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += *(arr + i * N + i);
        sum2 += *(arr + i * N + (N - 1 - i));
    }

    printf("\n대각선 합: %d %d\n", sum1, sum2);

    free(arr);

    return 0;
}