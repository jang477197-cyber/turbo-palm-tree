#include <stdio.h>
#include <stdint.h>

int main() {

    float input;

    scanf_s("%f", &input);

    int16_t fixed = (int16_t)(input * 256);

    for (int i = 15; i >= 8; i--) {
        printf("%d", (fixed >> i) & 1);
    }

    printf(".");

    for (int i = 7; i >= 0; i--) {
        printf("%d", (fixed >> i) & 1);
    }

    printf("\n");

    return 0;
}