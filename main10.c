#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

// 반복문 방식
int fibo_iter(int n) {
    int f1 = 1, f2 = 1, fn;

    if (n <= 2) return 1;

    for (int i = 3; i <= n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    return fn;
}

// 재귀 방식
int fibo_rec(int n) {
    if (n <= 2) return 1;
    return fibo_rec(n - 1) + fibo_rec(n - 2);
}

int main() {
    int n;
    clock_t start, end;
    double time_iter, time_rec;

    printf("N 입력: ");
    scanf("%d", &n);

    // ----------------------
    // 반복문 시간 측정
    // ----------------------
    start = clock();
    int iter = fibo_iter(n);
    end = clock();
    time_iter = (double)(end - start) / CLOCKS_PER_SEC;

    // ----------------------
    // 재귀 시간 측정
    // ----------------------
    start = clock();
    int rec = fibo_rec(n);
    end = clock();
    time_rec = (double)(end - start) / CLOCKS_PER_SEC;

    // ----------------------
    // 결과 출력
    // ----------------------
    printf("\n===== 결과 =====\n");

    printf("[반복문 방식]\n");
    printf("F(%d) = %d\n", n, iter);
    printf("실행 시간: %f초\n", time_iter);

    printf("\n[재귀 방식]\n");
    printf("F(%d) = %d\n", n, rec);
    printf("실행 시간: %f초\n", time_rec);

    return 0;
}