#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_math.h"

int main() {
    int a, b;

    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &a, &b);

    printf("GCD: %d\n", gcd(a, b));
    printf("LCM: %d\n", lcm(a, b));

    return 0;
}