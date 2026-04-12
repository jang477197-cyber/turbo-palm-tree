#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LEN 50
#define MAX_NAMES 200

typedef struct {
    char name[NAME_LEN];
    int id;
    int score;
} Student;

int main() {
    int N;
    printf("학생 수 입력: ");
    scanf("%d", &N);

    Student* arr = (Student*)malloc(sizeof(Student) * N);
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // ===== 이름 파일 읽기 =====
    FILE* fp = fopen("name_list.txt", "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        free(arr);
        return 1;
    }

    char nameList[MAX_NAMES][NAME_LEN];
    int nameCount = 0;

    while (fgets(nameList[nameCount], NAME_LEN, fp) != NULL) {
        nameList[nameCount][strcspn(nameList[nameCount], "\n")] = '\0';
        nameCount++;
    }

    fclose(fp);

    srand((unsigned int)time(NULL));

    // ===== 학생 데이터 생성 =====
    for (int i = 0; i < N; i++) {
        int randIndex = rand() % nameCount;  // ⭐ 랜덤 이름 선택

        strcpy(arr[i].name, nameList[randIndex]);
        arr[i].id = i + 1;                   // ⭐ 학번 1~N
        arr[i].score = rand() % 100 + 1;     // ⭐ 1~100
    }

    // ===== 통계 계산 =====
    int max = arr[0].score;
    int min = arr[0].score;
    int max_idx = 0, min_idx = 0;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += arr[i].score;

        if (arr[i].score > max) {
            max = arr[i].score;
            max_idx = i;
        }

        if (arr[i].score < min) {
            min = arr[i].score;
            min_idx = i;
        }
    }

    double avg = (double)sum / N;

    // ===== 결과 출력 =====
    printf("\n[전체 학생 정보]\n");
    for (int i = 0; i < N; i++) {
        printf("%d) 이름: %s / 학번: %d / 점수: %d\n",
            i + 1, arr[i].name, arr[i].id, arr[i].score);
    }

    printf("\n[결과]\n");
    printf("최고점 학생: %s / 학번: %d / 점수: %d\n",
        arr[max_idx].name, arr[max_idx].id, max);

    printf("최저점 학생: %s / 학번: %d / 점수: %d\n",
        arr[min_idx].name, arr[min_idx].id, min);

    printf("평균 점수: %.2f\n", avg);

    free(arr);
    return 0;
}