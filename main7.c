#include <stdio.h>

#define N 3   // 반드시 홀수

int main() {
    if (N % 2 == 0) {
        printf("오류: N은 홀수여야 합니다.\n");
        return 0;
    }

    int magic[N][N] = { 0 };
    int num = 1;
    int row = 0;
    int col = N / 2;

    // 마방진 생성
    while (num <= N * N) {
        magic[row][col] = num;

        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (magic[next_row][next_col] != 0) {
            row = (row + 1) % N;
        }
        else {
            row = next_row;
            col = next_col;
        }

        num++;
    }

    // 배열 전체 출력
    printf("마방진 배열 전체 출력:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", magic[i][j]);
        }
        printf("\n");
    }

    int target = N * (N * N + 1) / 2;

    printf("\n[검증 결과 - 각 세트의 합]\n");

    // 가로 세트
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += magic[i][j];
        }
        printf("가로 %d번째 세트의 합: %d\n", i + 1, sum);
    }

    // 세로 세트
    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += magic[i][j];
        }
        printf("세로 %d번째 세트의 합: %d\n", j + 1, sum);
    }

    // 대각선 세트
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += magic[i][i];
        sum2 += magic[i][N - 1 - i];
    }

    printf("왼쪽 위 → 오른쪽 아래 대각선 세트의 합: %d\n", sum1);
    printf("오른쪽 위 → 왼쪽 아래 대각선 세트의 합: %d\n", sum2);

    printf("\n모든 세트의 기준값 (마방진 상수): %d\n", target);

    return 0;
}