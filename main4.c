#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    int* arr;

    printf("배열 크기 N 입력: ");
    scanf("%d", &N);

    // 동적 할당
    arr = (int*)malloc(sizeof(int) * N);

    srand(time(NULL));

    // 배열 채우기 (0 ~ N)
    for (int i = 0; i < N; i++) {
        *(arr + i) = rand() % (N + 1);
    }

    // 정방향 출력
    printf("정방향 출력:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 역방향 출력
    printf("역방향 출력:\n");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 합, 최대값, 최소값
    int sum = 0;
    int max = *arr;
    int min = *arr;

    for (int i = 0; i < N; i++) {
        sum += *(arr + i);

        if (*(arr + i) > max)
            max = *(arr + i);

        if (*(arr + i) < min)
            min = *(arr + i);
    }

    printf("합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    free(arr);

    return 0;
}