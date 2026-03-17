#include <stdio.h>

int main() {
    float num;
    unsigned int bits;

    scanf_s("%f", &num);

    bits = *(unsigned int*)&num;

    int sign = (bits >> 31) & 1;
    int exponent = (bits >> 23) & 0xFF;
    int fraction = bits & 0x7FFFFF;

    printf("%d/", sign);

    for (int i = 7; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
        if (i == 4) printf(" ");
    }

    printf("/");

    for (int i = 22; i >= 0; i--) {
        printf("%d", (fraction >> i) & 1);
        if (i % 4 == 3 && i != 22) printf(" ");
    }

    printf("\n");

    return 0;
}