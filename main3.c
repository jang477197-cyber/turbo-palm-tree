#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    clock_t start, end;

    printf("n\tGCD\tTime\n");

    for (int n = 5; n <= 30; n++) {
        start = clock();

        int fn = fib(n);
        int fn1 = fib(n - 1);
        int result = gcd(fn, fn1);

        end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%d\t%f\n", n, result, time);
    }

    return 0;
}