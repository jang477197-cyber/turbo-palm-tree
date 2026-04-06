#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 

int main() {
    int arr[N];
    int i;

    // 난수 초기화
    srand(time(NULL));

    // 배열에 임의의 값 저장
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    int sum = 0;
    int max = arr[0];
    int min = arr[0];

    // 정방향 출력
    printf("정방향 출력:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];

        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    // 역방향 출력
    printf("\n\n역방향 출력:\n");
    for (i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n\n배열 전체 합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    return 0;
}